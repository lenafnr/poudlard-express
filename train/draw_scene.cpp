#include "draw_scene.hpp"
#include "tools/stb_image.h"
#include "rails.hpp"
#include "train.hpp"
#include "station.hpp"
#include "trees.hpp"
#include "drawSky.hpp"
#include "texture_manager.hpp"
#include "objects.hpp"
#include "json_manager.hpp"

float rr{0.05f * size_grid};
float sx{0.05f * size_grid};
float sr{0.1f * size_grid};
float size_grid{10.f};
int angle{};
bool phong_lightning = true;

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
	initJson();
}

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
	myEngine.mvMatrixStack.addTranslation({2.f * size_grid, 0.1f * size_grid, 0.2f * size_grid});
	myEngine.mvMatrixStack.addRotation(M_PI /2 , {0.0f, 0.0f, 1.0f});
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