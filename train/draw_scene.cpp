#include "draw_scene.hpp"
#include "tools/stb_image.h"
#include "rails.hpp"
#include "train.hpp"
#include "station.hpp"
#include "trees.hpp"
#include "json.hpp"
#include "drawSky.hpp"
#include "texture_manager.hpp"
#include "objects.hpp"

float rr{0.05f * size_grid};
float sx{0.05f * size_grid};
float sr{0.1f * size_grid};
float size_grid{10.f};

bool phong_lightning = true;

using json = nlohmann::json;

std::array<int, 2> stationPos{};
std::vector<std::array<int, 2>> railsPos{};
std::vector<std::array<int, 2>> treesPos{};
std::vector<std::array<int, 2>> pinePos{};
std::vector<std::array<int, 2>> lampPos{};

void initJson()
{
	std::ifstream file("../data/props.json");

	if (!file.is_open())
	{
		std::cout << "JSON introuvable !" << std::endl;
		return;
	}

	json data;
	file >> data;

	railsPos.clear();

	for (const auto &p : data["path"])
	{
		railsPos.push_back({p[0].get<int>(),
							p[1].get<int>()});
	}

	stationPos = {
		data["origin"][0].get<int>(),
		data["origin"][1].get<int>()};

	treesPos.clear();

	for (const auto &p : data["trees"])
	{
		treesPos.push_back({p[0].get<int>(),
							p[1].get<int>()});
	}

	pinePos.clear();

	for (const auto &p : data["pine"])
	{
		pinePos.push_back({p[0].get<int>(),
						   p[1].get<int>()});
	}

	lampPos.clear();

	for (const auto &p : data["lamp"])
	{
		lampPos.push_back({p[0].get<int>(),
						   p[1].get<int>()});
	}

	size_grid = data["size_grid"].get<float>();
}

void initScene()
{
	// Initialisation de la lumière (lune)
	myEngine.switchToPhongShading();
	myEngine.setLightPosition({3.0f * size_grid, 0.f, 5.0f * size_grid, 1.f}, 0);
	myEngine.setLightIntensity({1500.f, 1500.f, 1500.f});
	// Lampadaires
	// Lampadaire de la gare
	myEngine.addALight({(stationPos[0] + 0.2f) * size_grid, (stationPos[1] + 0.85f) * size_grid, 0.585f * size_grid, 1.f}, {30.f, 30.f, 30.f});
	// Lampadaires du circuit
    for (const auto &position : lampPos) {
		float lampX = ((position[0] + 0.2f) * size_grid) + (size_grid / 2.0f);
		float lampY = ((position[1] + 0.85f) * size_grid) + (size_grid);
        float lampZ = 1.f * size_grid;
        
        myEngine.addALight({lampX, lampY, lampZ, 1.f}, {30.f, 30.f, 30.f});
    }
	myEngine.switchToFlatShading();
	initAllObjects();
	loadAllTextures();
}

int angle{};
void drawScene()
{
	glPointSize(10.0);

	myEngine.activateTexturing(false);

	// La lune
	if (phong_lightning)
	{
		myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addRotation(M_PI * angle / 180, {0.0, 0.0, 1.0});
		myEngine.mvMatrixStack.addTranslation({3.0f * size_grid, 0.f, 5.0f * size_grid});
		myEngine.mvMatrixStack.addHomothety({2.f, 2.f, 2.f});
		myEngine.updateMvMatrix();
		myEngine.setFlatColor(0.5f, 0.5f, 0.5f);
		sphere->draw();
		angle++;
		myEngine.mvMatrixStack.popMatrix();

		// On illumine la scène
		myEngine.switchToPhongShading();
		// On fait tourner la lumière avec la sphère
		float a = M_PI * angle / 180.f;
		float x = cos(a) * 3.f * size_grid;
		float y = sin(a) * 3.f * size_grid;
		myEngine.setLightPosition({x, y, 5.f * size_grid,1.f},0);

		// Les lampadaires
		// Lampadaire de la gare
		myEngine.setLightPosition({(stationPos[0] + 0.2f) * size_grid, (stationPos[1] + 0.85f) * size_grid, 0.585f * size_grid, 1.f}, 1);
		// Lampadaires du circuit
		int lightIndex = 2;
        for (const auto &position : lampPos) {
            float lampX = ((position[0] + 0.2f) * size_grid) + (size_grid / 2.0f);
			float lampY = ((position[1] + 0.85f) * size_grid) + (size_grid);
			float lampZ = 1.f * size_grid;
            myEngine.setLightPosition({lampX, lampY, lampZ, 1.f}, lightIndex);
            
            lightIndex++;
        }
	}
	myEngine.setFlatColor(0.2, 0.0, 0.0);
	// Car le modèle phong utilise une matrice pour calculer les normales : il faut l'update
	myEngine.updateMvMatrix();
	ground.drawShape();
	railsPlacement();
	treesPlacement();
	lampsPlacement();
	// treesPlacement();
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({2.f * size_grid, 2.f * size_grid, 0});
	myEngine.updateMvMatrix();
	train();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({stationPos[0] * size_grid, stationPos[1] * size_grid, 0});
	myEngine.updateMvMatrix();
	station();
	myEngine.mvMatrixStack.popMatrix();
	drawRect();
	if (phong_lightning) {
		myEngine.switchToFlatShading();
	}
}