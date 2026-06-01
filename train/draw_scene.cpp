#include "draw_scene.hpp"
#include "tools/stb_image.h"
#include "rails.hpp"
#include "train.hpp"

/// Camera parameters
float angle_theta {45.0};      // Angle between x axis and viewpoint
float angle_phy {30.0};      // Angle between z axis and viewpoint
float dist_zoom {30.0};      // Distance between origin and viewpoint

GLBI_Engine myEngine;
GLBI_Texture textureGold;
GLBI_Texture textureCloud;
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

	repere = createRepere(10.0f);
	repere->createVAO(); // Creation de l'objet dans OpenGL

	// Un cylindre de hauteur 1 et de rayon 1
	cyl = basicCylinder(1.f,1.f);
	cyl->createVAO(); // Creation de l'objet dans OpenGL

	// Un cube de taille 1
	cube = basicCube(1.f);
	cube->createVAO(); // Creation de l'objet dans OpenGL

	// Une sphère de taille 1
	sphere = basicSphere(1.f);
	sphere->createVAO(); // Creation de l'objet dans OpenGL
		// Gold
	int x_g, y_g, n_g;
    unsigned char* img_gold = stbi_load("../assets/textures/gold.jpg", &x_g, &y_g, &n_g, 4);
	textureGold.createTexture();
	textureGold.attachTexture();
	textureGold.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	textureGold.loadImage(x_g, y_g, 4, img_gold); // On force n = 4 ici
	textureGold.detachTexture();
	stbi_image_free(img_gold);
		// Clouds
	int x_c, y_c, n_c;
    unsigned char* img_cloud = stbi_load("../assets/textures/cloud.jpg", &x_c, &y_c, &n_c, 4);
	textureCloud.createTexture();
	textureCloud.attachTexture();
	textureCloud.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	textureCloud.loadImage(x_c, y_c, 4, img_cloud); // On force n = 4 ici
	textureCloud.detachTexture();
	stbi_image_free(img_cloud);
	
	glActiveTexture(GL_TEXTURE0);
}

void drawScene() {
	glPointSize(10.0);

	myEngine.activateTexturing(false);
	myEngine.setFlatColor(0.2,0.0,0.0);

	ground.drawShape();
	repere->draw();

	train();
}