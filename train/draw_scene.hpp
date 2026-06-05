#pragma once

#include "glbasimac/glbi_engine.hpp"
#include "glbasimac/glbi_texture.hpp"
#include "glbasimac/glbi_engine.hpp"
#include "glbasimac/glbi_set_of_points.hpp"
#include "glbasimac/glbi_convex_2D_shape.hpp"
#include "tools/basic_mesh.hpp"
#include <fstream>
#include <iostream>

using namespace glbasimac;

/* Camera parameters and functions */
static const float Z_NEAR {0.1f};
static const float Z_FAR {500.f};
extern float rr ;
extern float sx;
extern float sr;
extern float size_grid;
/* OpenGL Engine */
extern GLBI_Texture textureGold;
extern GLBI_Texture textureCloud;
extern GLBI_Texture texturePlatform;

extern GLBI_Texture textureNx;
extern GLBI_Texture textureNy;
extern GLBI_Texture textureNz;
extern GLBI_Texture texturePx;
extern GLBI_Texture texturePy;
extern GLBI_Texture texturePz;

extern GLBI_Engine myEngine;
extern IndexedMesh* sphere;
extern IndexedMesh* cube;
extern IndexedMesh* cyl;
extern IndexedMesh* sphere;
extern StandardMesh* rectangle;
extern StandardMesh* cone;
extern GLBI_Convex_2D_Shape arc;
extern GLBI_Convex_2D_Shape circle;
void createCirlce(float r);
extern void closedCylinder();

extern std::array<int,2> stationPos;
extern std::vector<std::array<int,2>> railsPos;

void initScene();
void initJson();

void rails_straight();
void rails_curved();

void drawScene();

