#include "draw_scene.hpp"
#include "tools/stb_image.h"
#include "rails.hpp"
#include "train.hpp"
#include "station.hpp"

/// Camera parameters
float angle_theta{45.0}; // Angle between x axis and viewpoint
float angle_phy{30.0};	 // Angle between z axis and viewpoint
float dist_zoom{30.0};	 // Distance between origin and viewpoint

GLBI_Engine myEngine;
GLBI_Texture textureGold;
GLBI_Texture textureCloud;
GLBI_Texture texturePlatform;
GLBI_Set_Of_Points somePoints(3);
GLBI_Convex_2D_Shape ground{3};
GLBI_Convex_2D_Shape arc{3};
GLBI_Convex_2D_Shape circle;

std::vector<float> pointCircle {
};

void createCircle(float r)
{
    int segments = 50;
 
    for (int i = 0; i < segments; ++i)
    {
        // Calcul de l'angle pour ce segment (en radians)
        float theta = 2.0f * M_PI * float(i) / float(segments);
        
        // Calcul des coordonnées x et y
        float x = r * std::cos(theta);
        float y = r * std::sin(theta);
        
        pointCircle.push_back(x);
        pointCircle.push_back(y);
    }
}

StandardMesh *repere = NULL;
IndexedMesh *sphere;
IndexedMesh *cyl;
IndexedMesh *cube;
IndexedMesh *disk;

float rr{0.5f};
float sx{0.5f};
float sr{1.f};
float size_grid{10.f};

void initScene()
{
	std::vector<float> points{0.0, 0.0, 0.0};
	somePoints.initSet(points, 1.0, 1.0, 1.0);

	std::vector<float> baseCarre{-100.0, -100.0, 0.0,
								 100.0, -100.0, 0.0,
								 100.0, 100.0, 0.0,
								 -100.0, 100.0, 0.0};

	ground.initShape(baseCarre);
	ground.changeNature(GL_TRIANGLE_FAN);

	repere = createRepere(10.0f);
	repere->createVAO(); // Creation de l'objet dans OpenGL

	// Un cylindre de hauteur 1 et de rayon 1
	cyl = basicCylinder(1.f, 1.f);
	cyl->createVAO(); // Creation de l'objet dans OpenGL

	// Un cube de taille 1
	cube = basicCube(1.f);
	cube->createVAO(); // Creation de l'objet dans OpenGL

	// Une sphère de taille 1
	sphere = basicSphere(1.f);
	sphere->createVAO(); // Creation de l'objet dans OpenGL

	createCircle(1.f);
	circle.initShape(pointCircle);
	circle.changeNature(GL_TRIANGLE_FAN);
	
	// 1/4 arc
	std::vector<float> rail;
	float R = 1.0f;
	float stroke = 0.1f;
	int N = 100;

	float start = 0.f;
	float end = M_PI / 2.f;

	for (int i = 0; i <= N; i++)
	{
		float t = (float)i / N;
		float a = start + t * (end - start);

		float x1 = R * cos(a);
		float y1 = R * sin(a);

		float x2 = (R - stroke) * cos(a);
		float y2 = (R - stroke) * sin(a);

		rail.push_back(x1);
		rail.push_back(y1);
		rail.push_back(0.f);

		rail.push_back(x2);
		rail.push_back(y2);
		rail.push_back(0.f);
	}

	arc.initShape(rail);
	arc.changeNature(GL_TRIANGLE_STRIP);
		// Gold
	int x_g, y_g, n_g;
    unsigned char* img_gold = stbi_load("../assets/textures/gold.jpg", &x_g, &y_g, &n_g, 4);
	textureGold.createTexture();
	textureGold.attachTexture();
	textureGold.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	textureGold.loadImage(x_g, y_g, 4, img_gold);
	textureGold.detachTexture();
	stbi_image_free(img_gold);
		// Clouds
	int x_c, y_c, n_c;
    unsigned char* img_cloud = stbi_load("../assets/textures/cloud.jpg", &x_c, &y_c, &n_c, 4);
	textureCloud.createTexture();
	textureCloud.attachTexture();
	textureCloud.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	textureCloud.loadImage(x_c, y_c, 4, img_cloud);
	textureCloud.detachTexture();
	stbi_image_free(img_cloud);
	// 9 3/4
	int x_p, y_p, n_p;
    unsigned char* img_platform = stbi_load("../assets/textures/plateform.jpg", &x_p, &y_p, &n_p, 4);
	texturePlatform.createTexture();
	texturePlatform.attachTexture();
	texturePlatform.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	texturePlatform.loadImage(x_p, y_p, 4, img_platform);
	texturePlatform.detachTexture();
	stbi_image_free(img_platform);
	
	glActiveTexture(GL_TEXTURE0);
}

void drawScene()
{
	glPointSize(10.0);

	myEngine.activateTexturing(false);
	myEngine.setFlatColor(0.2,0.0,0.0);

	ground.drawShape();
	repere->draw();

	rails_straight();
}