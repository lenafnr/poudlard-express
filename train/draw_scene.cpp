#include "draw_scene.hpp"

/// Camera parameters
float angle_theta {45.0};      // Angle between x axis and viewpoint
float angle_phy {30.0};      // Angle between z axis and viewpoint
float dist_zoom {30.0};      // Distance between origin and viewpoint

GLBI_Engine myEngine;
GLBI_Set_Of_Points somePoints(3);
GLBI_Convex_2D_Shape ground{3};
StandardMesh* repere = NULL;
IndexedMesh* sphere;
IndexedMesh* cyl;
IndexedMesh* cube;

float rr {};
float sx {};
float sr {}; 
float size_grid {/*rails.size_grid*/};

void initScene() {
	std::vector<float> points {0.0,0.0,0.0};
	somePoints.initSet(points,1.0,1.0,1.0);

	std::vector<float> baseCarre{-100.0,-100.0,0.0,
								 100.0,-100.0,0.0,
								 100.0,100.0,0.0,
								 -100.0,100.0,0.0};
	ground.initShape(baseCarre);
	ground.changeNature(GL_TRIANGLE_FAN);

	repere = createRepere(10.0f);
	repere->createVAO(); // Creation de l'objet dans OpenGL

	// Un cylindre de hauteur 20 et de rayon 5
	cyl = basicCylinder(20.0,5.);
	cyl->createVAO(); // Creation de l'objet dans OpenGL

	// Un cube de taille 1
	cube = basicCube(1.f);
	cube->createVAO(); // Creation de l'objet dans OpenGL
}

void rails_straight() {
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety({sr, size_grid, sr});
		myEngine.updateMvMatrix();
		myEngine.setFlatColor(0.5,0.5,0.5);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();
}

void rails_curved() {

}

void drawScene() {
	glPointSize(10.0);

	myEngine.setFlatColor(0.2,0.0,0.0);

	ground.drawShape();
	repere->draw();
}