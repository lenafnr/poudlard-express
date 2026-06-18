#include "objects.hpp"

GLBI_Engine myEngine;
GLBI_Set_Of_Points somePoints(3);
GLBI_Convex_2D_Shape ground{3};
GLBI_Convex_2D_Shape arc{3};
GLBI_Convex_2D_Shape circle;
StandardMesh *rectangle;
StandardMesh *repere = NULL;
IndexedMesh *sphere;
IndexedMesh *cyl;
IndexedMesh *cube;
IndexedMesh *disk;
StandardMesh *cone;

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

void initAllObjects() {
    std::vector<float> points{0.0, 0.0, 0.0};
	somePoints.initSet(points, 1.0, 1.0, 1.0);
	std::vector<float> baseCarre{-size_grid * 5, -size_grid * 5, 0.0,
								 size_grid * 5, -size_grid * 5, 0.0,
								 size_grid * 5, size_grid * 5, 0.0,
								 -size_grid * 5, size_grid * 5, 0.0};

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
	arc.initShape(rail);
	arc.changeNature(GL_TRIANGLE_STRIP);
}