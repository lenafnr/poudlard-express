#include "texture_manager.hpp"
#include "tools/stb_image.h"

GLBI_Texture textureGold;
GLBI_Texture textureCloud;
GLBI_Texture texturePlatform;
GLBI_Texture textureNx;
GLBI_Texture textureNy;
GLBI_Texture textureNz;
GLBI_Texture texturePx;
GLBI_Texture texturePy;
GLBI_Texture texturePz;

void loadAllTextures() {
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