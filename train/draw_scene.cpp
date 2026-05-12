#include "draw_scene.hpp"

/// Camera parameters
float angle_theta {45.0};      // Angle between x axis and viewpoint
float angle_phy {30.0};      // Angle between z axis and viewpoint
float dist_zoom {30.0};      // Distance between origin and viewpoint

GLBI_Engine myEngine;
GLBI_Set_Of_Points somePoints(3);
GLBI_Convex_2D_Shape ground{3};
// GLBI_Convex_2D_Shape arc_of_cirlce{};
StandardMesh* repere = NULL;
IndexedMesh* sphere;
IndexedMesh* cyl;
IndexedMesh* cube;

float rr {0.5f};
float sx {0.5f};
float sr {1.f}; 
float size_grid {10.f};

void initScene() {
	std::vector<float> points {0.0,0.0,0.0};
	somePoints.initSet(points,1.0,1.0,1.0);

	std::vector<float> baseCarre{-100.0,-100.0,0.0,
								 100.0,-100.0,0.0,
								 100.0,100.0,0.0,
								 -100.0,100.0,0.0};

	ground.initShape(baseCarre);
	ground.changeNature(GL_TRIANGLE_FAN);

	// arc_of_cirlce.initShape(baseArcOfCircle);
	// arc_of_cirlce.changeNature(GL_TRIANGLE_FAN);

	repere = createRepere(10.0f);
	repere->createVAO(); // Creation de l'objet dans OpenGL

	// Un cylindre de hauteur 1 et de rayon 1
	cyl = basicCylinder(1.f,1.f);
	cyl->createVAO(); // Creation de l'objet dans OpenGL

	// Un cube de taille 1
	cube = basicCube(1.f);
	cube->createVAO(); // Creation de l'objet dans OpenGL
}

void rails_straight() {
	// Les rails
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({3.f, 5.f, sr / 2 + 2 * rr});
		myEngine.mvMatrixStack.addHomothety({sr, size_grid, sr});
		myEngine.updateMvMatrix();
		myEngine.setFlatColor(0.5,0.5,0.5);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({7.f, 5.f, sr / 2 + 2 * rr});
		myEngine.mvMatrixStack.addHomothety({sr, size_grid, sr});
		myEngine.updateMvMatrix();
		myEngine.setFlatColor(0.5,0.5,0.5);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	// Les balasts
	for (int i {}; i < 5; i++) {
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({8.f, (sx + rr) + i * (2.0f * sx + 2.0f * rr), rr});
			myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.f, 0.f, 1.f});
			myEngine.mvMatrixStack.addHomothety({rr, 6.f, rr});
			myEngine.updateMvMatrix();
			myEngine.setFlatColor(1.f,0.7,0.f);
			cyl->draw();
		myEngine.mvMatrixStack.popMatrix();
	}
}

void rails_curved() {
	// Le rail intérieur
	for (int i{}; i < 101; i++) {
		float teta = M_PI / 200 * i;
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addRotation(teta - M_PI / 2, {0.f, 0.f, 1.f});
			myEngine.mvMatrixStack.addTranslation({0.f, 5.f, 4 * rr});
			myEngine.mvMatrixStack.addHomothety({sr, sr, sr});
			myEngine.updateMvMatrix();
			myEngine.setFlatColor(0.5,0.5,0.5);
			cyl->draw();
		myEngine.mvMatrixStack.popMatrix();
	}
	// Le rail extérieur
	for (int i{}; i < 101; i++) {
		float teta = M_PI / 200 * i;
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addRotation(teta - M_PI / 2, {0.f, 0.f, 1.f});
			myEngine.mvMatrixStack.addTranslation({0.f, 9.f, 4 * rr});
			myEngine.mvMatrixStack.addHomothety({sr, sr, sr});
			myEngine.updateMvMatrix();
			myEngine.setFlatColor(0.5,0.5,0.5);
			cyl->draw();
		myEngine.mvMatrixStack.popMatrix();
	}
	// Les balasts
    for (int i{1}; i < 4; i++) {
		float teta = M_PI / 8.f * i;
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addRotation(teta - M_PI / 2, {0.f, 0.f, 1.f});
			myEngine.mvMatrixStack.addTranslation({0.f, 4.f, rr});
			myEngine.mvMatrixStack.addHomothety({rr, 7.f, rr});
			myEngine.updateMvMatrix();
			myEngine.setFlatColor(1.f, 0.7f, 0.f);
			cyl->draw();
		myEngine.mvMatrixStack.popMatrix();
	}
}


void drawScene() {
	glPointSize(10.0);

	myEngine.setFlatColor(0.2,0.0,0.0);

	ground.drawShape();
	repere->draw();

	rails_curved();
}