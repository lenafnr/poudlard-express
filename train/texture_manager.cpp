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

// Pour alléger la fonction suivante
static void loadSingleTexture(GLBI_Texture& texture, char const* path) {
	int x, y, n;
	// On le charge dans CPU
	unsigned char *img = stbi_load(path, &x, &y, &n, 4);
	texture.createTexture();
	// On fait le lien avec GPU
	texture.attachTexture();
	texture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	// On le charge dans le GPU
	texture.loadImage(x, y, 4, img);
	// On coupe le lien
	texture.detachTexture();
	// On libère le CPU
	stbi_image_free(img);
}

void loadAllTextures() {
    // Gold
	loadSingleTexture(textureGold, "../assets/textures/gold.jpg");
	// Clouds
	loadSingleTexture(textureCloud, "../assets/textures/cloud.jpg");
	// 9 3/4
	loadSingleTexture(texturePlatform, "../assets/textures/plateform.jpg");
	// SkyBox
	// 1. Px skyBox
	loadSingleTexture(texturePx, "../assets/textures/px.png");
	// 2. Nx skyBox
	loadSingleTexture(textureNx, "../assets/textures/nx.png");
	// 3. Py skyBox
	loadSingleTexture(texturePy, "../assets/textures/py.png");
	// 4. Ny skyBox
	loadSingleTexture(textureNy, "../assets/textures/ny.png");
	// 5. Pz skyBox
	loadSingleTexture(texturePz, "../assets/textures/pz.png");
	// 6. Nz skyBox
	loadSingleTexture(textureNz, "../assets/textures/nz.png");

	glActiveTexture(GL_TEXTURE0);
}