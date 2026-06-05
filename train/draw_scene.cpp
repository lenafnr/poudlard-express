#include "draw_scene.hpp"
#include "tools/stb_image.h"
#include "rails.hpp"
#include "train.hpp"
#include "station.hpp"
#include "trees.hpp"
#include "json.hpp"
#include "drawSky.hpp"

GLBI_Engine myEngine;
GLBI_Texture textureGold;
GLBI_Texture textureCloud;
GLBI_Texture texturePlatform;
GLBI_Texture textureNx;
GLBI_Texture textureNy;
GLBI_Texture textureNz;
GLBI_Texture texturePx;
GLBI_Texture texturePy;
GLBI_Texture texturePz;

GLBI_Set_Of_Points somePoints(3);
GLBI_Convex_2D_Shape ground{3};
GLBI_Convex_2D_Shape arc{3};
GLBI_Convex_2D_Shape circle;
StandardMesh *rectangle;
bool phong_lightning = true;

using json = nlohmann::json;

std::array<int, 2> stationPos{};
std::vector<std::array<int, 2>> railsPos{};

std::vector<float> pointCircle{};

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

void closedCylinder()
{
	cyl->draw();
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f, 1.f, 0.f});
	myEngine.mvMatrixStack.addRotation(M_PI / 2, {1, 0, 0});
	myEngine.updateMvMatrix();
	circle.drawShape();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f, 0.f, 0.f});
	myEngine.mvMatrixStack.addRotation(M_PI / 2, {1, 0, 0});
	myEngine.updateMvMatrix();
	circle.drawShape();
	myEngine.mvMatrixStack.popMatrix();
}

StandardMesh *repere = NULL;
IndexedMesh *sphere;
IndexedMesh *cyl;
IndexedMesh *cube;
IndexedMesh *disk;
StandardMesh *cone;

float rr{0.05f * size_grid};
float sx{0.05f * size_grid};
float sr{0.1f * size_grid};
float size_grid{10.f};

void initJson()
{
	std::ifstream file("../data/railsAdvanced.json");

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

	size_grid = data["size_grid"].get<float>();
}

void initScene()
{
	// Initialisation de la lumière (lune)
	myEngine.switchToPhongShading();
	myEngine.setLightPosition({3.0f * size_grid, 0.f, 5.0f * size_grid, 1.f}, 0);
	myEngine.setLightIntensity({2000.f, 2000.f, 2000.f});
	// myEngine.setConeLight({1.f, 1.f, 0.f}, M_PI / 4, 0);
	myEngine.switchToFlatShading();

	std::vector<float> points{0.0, 0.0, 0.0};
	somePoints.initSet(points, 1.0, 1.0, 1.0);

	std::vector<float> baseCarre{-50.0, -50.0, 0.0,
								 50.0, -50.0, 0.0,
								 50.0, 50.0, 0.0,
								 -50.0, 50.0, 0.0};
	
	myEngine.setNormalForConvex2DShape({0.f,0.f,1.f});
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
	myEngine.setNormalForConvex2DShape({0.f,0.f,1.f});
	circle.initShape(pointCircle);
	circle.changeNature(GL_TRIANGLE_FAN);

	// rectangle 2D
	rectangle = basicRect(1.0, 1.0);
	rectangle->createVAO();
	
	cone = basicCone(1.f, 1.f);
	cone->createVAO();
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
	myEngine.setNormalForConvex2DShape({0.f,0.f,1.f});
	arc.initShape(rail);
	arc.changeNature(GL_TRIANGLE_STRIP);
	// Gold
	int x_g, y_g, n_g;
	unsigned char *img_gold = stbi_load("../assets/textures/gold.jpg", &x_g, &y_g, &n_g, 4);
	textureGold.createTexture();
	textureGold.attachTexture();
	textureGold.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	textureGold.loadImage(x_g, y_g, 4, img_gold);
	textureGold.detachTexture();
	stbi_image_free(img_gold);
	// Clouds
	int x_c, y_c, n_c;
	unsigned char *img_cloud = stbi_load("../assets/textures/cloud.jpg", &x_c, &y_c, &n_c, 4);
	textureCloud.createTexture();
	textureCloud.attachTexture();
	textureCloud.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	textureCloud.loadImage(x_c, y_c, 4, img_cloud);
	textureCloud.detachTexture();
	stbi_image_free(img_cloud);
	// 9 3/4
	int x_p, y_p, n_p;
	unsigned char *img_platform = stbi_load("../assets/textures/plateform.jpg", &x_p, &y_p, &n_p, 4);
	texturePlatform.createTexture();
	texturePlatform.attachTexture();
	texturePlatform.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	texturePlatform.loadImage(x_p, y_p, 4, img_platform);
	texturePlatform.detachTexture();
	stbi_image_free(img_platform);

	// 1. Px skyBox
    int x_Px, y_Px, n_Px;
    unsigned char *img_px = stbi_load("../assets/textures/px.png", &x_Px, &y_Px, &n_Px, 4);
    texturePx.createTexture();
    texturePx.attachTexture();
    texturePx.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    texturePx.loadImage(x_Px, y_Px, 4, img_px);
    texturePx.detachTexture();
    stbi_image_free(img_px);

    // 2. Nx skyBox
    int x_Nx, y_Nx, n_Nx;
    unsigned char *img_nx = stbi_load("../assets/textures/nx.png", &x_Nx, &y_Nx, &n_Nx, 4);
    textureNx.createTexture();
    textureNx.attachTexture();
    textureNx.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    textureNx.loadImage(x_Nx, y_Nx, 4, img_nx);
    textureNx.detachTexture();
    stbi_image_free(img_nx);

    // 3. Py skyBox
    int x_Py, y_Py, n_Py;
    unsigned char *img_py = stbi_load("../assets/textures/py.png", &x_Py, &y_Py, &n_Py, 4);
    texturePy.createTexture();
    texturePy.attachTexture();
    texturePy.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    texturePy.loadImage(x_Py, y_Py, 4, img_py);
    texturePy.detachTexture();
    stbi_image_free(img_py);

    // 4. Ny skyBox
    int x_Ny, y_Ny, n_Ny;
    unsigned char *img_ny = stbi_load("../assets/textures/ny.png", &x_Ny, &y_Ny, &n_Ny, 4);
    textureNy.createTexture();
    textureNy.attachTexture();
    textureNy.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    textureNy.loadImage(x_Ny, y_Ny, 4, img_ny);
    textureNy.detachTexture();
    stbi_image_free(img_ny);

    // 5. Pz skyBox
    int x_Pz, y_Pz, n_Pz;
    unsigned char *img_pz = stbi_load("../assets/textures/pz.png", &x_Pz, &y_Pz, &n_Pz, 4);
    texturePz.createTexture();
    texturePz.attachTexture();
    texturePz.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    texturePz.loadImage(x_Pz, y_Pz, 4, img_pz);
    texturePz.detachTexture();
    stbi_image_free(img_pz);

    // 6. Nz skyBox
    int x_Nz, y_Nz, n_Nz;
    unsigned char *img_nz = stbi_load("../assets/textures/nz.png", &x_Nz, &y_Nz, &n_Nz, 4);
    textureNz.createTexture();
    textureNz.attachTexture();
    textureNz.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    textureNz.loadImage(x_Nz, y_Nz, 4, img_nz);
    textureNz.detachTexture();
    stbi_image_free(img_nz);

	glActiveTexture(GL_TEXTURE0);
}

int angle{};
void drawScene()
{
	glPointSize(10.0);

	myEngine.activateTexturing(false);

	// La lune
	if (phong_lightning) {
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addRotation(M_PI * angle / 180, {0.0, 0.0, 1.0});
			myEngine.mvMatrixStack.addTranslation({3.0f * size_grid, 0.f, 5.0f * size_grid});
			myEngine.mvMatrixStack.addHomothety({2.f, 2.f, 2.f});
			myEngine.updateMvMatrix();
			myEngine.setFlatColor(0.5f,0.5f,0.5f);
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
	}
	myEngine.setFlatColor(0.2, 0.0, 0.0);
	// Car le modèle phong utilise une matrice pour calculer les normales : il faut l'update
	myEngine.updateMvMatrix();
	ground.drawShape();
	railsPlacement();

	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({2.f * size_grid, 2.f * size_grid, 0});
	myEngine.updateMvMatrix();
	train();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addRotation(M_PI, {0.f, 0.f, 1.f});
	myEngine.mvMatrixStack.addTranslation({stationPos[0] * size_grid, stationPos[1] * size_grid, 0});
	myEngine.mvMatrixStack.addTranslation({1.f * size_grid, -1.f * size_grid, 0.f});
	myEngine.updateMvMatrix();
	station();
	myEngine.mvMatrixStack.popMatrix();
	drawRect();
	if (phong_lightning) {
		myEngine.switchToFlatShading();
	}
}