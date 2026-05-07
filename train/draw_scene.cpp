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

int angle{};

void initScene() {
	std::vector<float> points {0.0,0.0,0.0};
	somePoints.initSet(points,1.0,1.0,1.0);

	std::vector<float> baseCarre{-10.0,-10.0,0.0,
								 10.0,-10.0,0.0,
								 10.0,10.0,0.0,
								 -10.0,10.0,0.0};
	ground.initShape(baseCarre);
	ground.changeNature(GL_TRIANGLE_FAN);

	repere = createRepere(10.0f);
	repere->createVAO(); // Creation de l'objet dans OpenGL

	sphere = basicSphere();
	sphere->createVAO();
}

void drawFrame() {
	// Cf code Juju
}

void drawBase() {
	// TO DO
}

void drawArm() {
	// TO DO
}

void drawPan() {
	// TO DO
}

void drawScene() {
	glPointSize(10.0);

	somePoints.drawSet();

	myEngine.setFlatColor(0.2,0.0,0.0);

	ground.drawShape();
	repere->draw();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addRotation(M_PI * angle / 180, {0.0, 0.0, 1.0});
		myEngine.mvMatrixStack.addTranslation({4.0, 0.f, 5.0});
		myEngine.mvMatrixStack.addHomothety({3.f, 3.f, 3.0});
		myEngine.updateMvMatrix();
		myEngine.setFlatColor(1.,1.0,0.0);
		sphere->draw();
		angle++;
	myEngine.mvMatrixStack.popMatrix();
}