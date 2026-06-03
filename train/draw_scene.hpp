#pragma once

#include "glbasimac/glbi_engine.hpp"
#include "glbasimac/glbi_texture.hpp"
#include "glbasimac/glbi_engine.hpp"
#include "glbasimac/glbi_set_of_points.hpp"
#include "glbasimac/glbi_convex_2D_shape.hpp"
#include "tools/basic_mesh.hpp"

using namespace glbasimac;

/* Camera parameters and functions */
static const float Z_NEAR {0.1f};
static const float Z_FAR {500.f};
extern float angle_theta;      // Angle between x axis and viewpoint
extern float angle_phy  ;      // Angle between z axis and viewpoint
extern float dist_zoom  ;      // Distance between origin and viewpoint
extern float rr ;
extern float sx;
extern float sr;
extern float size_grid;
/* OpenGL Engine */
extern GLBI_Texture textureGold;
extern GLBI_Texture textureCloud;
extern GLBI_Texture texturePlatform;
extern GLBI_Engine myEngine;
extern IndexedMesh* sphere;
extern IndexedMesh* cube;
extern IndexedMesh* cyl;
extern IndexedMesh* sphere;
extern StandardMesh* cone;
extern GLBI_Convex_2D_Shape arc;
extern GLBI_Convex_2D_Shape circle;
void createCirlce(float r);
extern void closedCylinder();
void initScene();

void rails_straight();
void rails_curved();

void drawScene();

