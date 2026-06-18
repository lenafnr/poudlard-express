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
#include "light_manager.hpp"

float rr{};
float sx{};
float sr{};
int angle{};
bool phong_lightning = true;

void initScene()
{
	rr = 0.05f * size_grid;
	sx = 0.05f * size_grid;
	sr = 0.1f * size_grid;
	
	initLights();
	initAllObjects();
	loadAllTextures();
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
			myEngine.mvMatrixStack.addTranslation({3.0f * size_grid, 0.f, 4.0f * size_grid});
			myEngine.mvMatrixStack.addHomothety({0.2f * size_grid, 0.2f * size_grid, 0.2f *size_grid});
			myEngine.updateMvMatrix();
			myEngine.setFlatColor(0.5f, 0.5f, 0.5f);
			sphere->draw();
		myEngine.mvMatrixStack.popMatrix();
		updateLight(angle);
		angle++;
	}
	myEngine.setFlatColor(0.2, 0.0, 0.0);
	// Car le modèle phong utilise une matrice pour calculer les normales : il faut l'update
	myEngine.updateMvMatrix();
	ground.drawShape();
	railsPlacement();
	treesPlacement();
	lampsPlacement();

	trainPlacement();

	stationPlacement();
	
	drawRect();
	if (phong_lightning) {
		myEngine.switchToFlatShading();
	}
}