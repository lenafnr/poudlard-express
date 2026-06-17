#pragma once
#include "draw_scene.hpp"
#include "json_manager.hpp"

/* OpenGL Engine */
extern GLBI_Engine myEngine;
extern StandardMesh* repere;
extern IndexedMesh* sphere;
extern IndexedMesh* cube;
extern IndexedMesh* cyl;
extern IndexedMesh* sphere;
extern StandardMesh* rectangle;
extern StandardMesh* cone;
extern GLBI_Convex_2D_Shape arc;
extern GLBI_Convex_2D_Shape circle;
extern GLBI_Set_Of_Points somePoints;
extern GLBI_Convex_2D_Shape ground;


void createCircle(float r);

void closedCylinder();

void initAllObjects();