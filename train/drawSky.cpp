#include "drawSky.hpp"

void drawRect()
{

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({25.f * size_grid, 25.f * size_grid, 25.f * size_grid});
    myEngine.mvMatrixStack.addHomothety({50 * size_grid, 1, 50 * size_grid});
    myEngine.mvMatrixStack.addRotation(M_PI, {0.f, 1.f, 0.f});
    myEngine.updateMvMatrix();
    myEngine.activateTexturing(true);
    textureNx.attachTexture();
    myEngine.setFlatColor(0.5, 0.5, 0.5);
    rectangle->draw();
    textureNx.detachTexture();
    myEngine.activateTexturing(false);
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-25.f * size_grid, 25.f * size_grid, 25.f * size_grid});
    myEngine.mvMatrixStack.addRotation(M_PI, {1.f, -1.f, 0.f});
    myEngine.mvMatrixStack.addHomothety({50 * size_grid, 1, 50 * size_grid});
    myEngine.updateMvMatrix();
    myEngine.activateTexturing(true);
    texturePz.attachTexture();
    myEngine.setFlatColor(0.5, 0.5, 0.5);
    rectangle->draw();
    texturePz.detachTexture();
    myEngine.activateTexturing(false);
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({25.f * size_grid, -25.f * size_grid, 25.f * size_grid});
    myEngine.mvMatrixStack.addRotation(M_PI, {1.f, -1.f, 0.f});
    myEngine.mvMatrixStack.addRotation(M_PI, {0.f, 0.f, 1.f});
    myEngine.mvMatrixStack.addHomothety({50 * size_grid, 1, 50 * size_grid});
    myEngine.updateMvMatrix();
    myEngine.activateTexturing(true);
    textureNz.attachTexture();
    myEngine.setFlatColor(0.5, 0.5, 0.5);
    rectangle->draw();
    textureNz.detachTexture();
    myEngine.activateTexturing(false);
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-25.f * size_grid, -25.f * size_grid, 25.f * size_grid});
    myEngine.mvMatrixStack.addRotation(M_PI, {0.f, 1.f, 0.f});
    myEngine.mvMatrixStack.addRotation(M_PI, {0.f, 0.f, 1.f});
    myEngine.mvMatrixStack.addHomothety({50 * size_grid, 1, 50 * size_grid});
    myEngine.updateMvMatrix();
    myEngine.activateTexturing(true);
    texturePx.attachTexture();
    myEngine.setFlatColor(0.5, 0.5, 0.5);
    rectangle->draw();
    texturePx.detachTexture();
    myEngine.activateTexturing(false);
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({25.f * size_grid, 25.f * size_grid, 25.f * size_grid});
    // myEngine.mvMatrixStack.addTranslation({1.f, 0.f, 30.f});
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.f, 0.f, 0.f});
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.f, -1.f, 0.f});
    // myEngine.mvMatrixStack.addRotation(M_PI, {0.f, 0.f, 1.f});
    myEngine.mvMatrixStack.addHomothety({50 * size_grid, 1, 50 * size_grid});
    myEngine.updateMvMatrix();
    myEngine.activateTexturing(true);
    texturePy.attachTexture();
    myEngine.setFlatColor(0.5, 0.5, 0.5);
    rectangle->draw();
    texturePy.detachTexture();
    myEngine.activateTexturing(false);
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-25.f * size_grid, 25.f * size_grid, -25.f * size_grid});
    //myEngine.mvMatrixStack.addTranslation({1.f, 0.f, 1.f});
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.f, 0.f, 0.f});
    myEngine.mvMatrixStack.addRotation(M_PI/2  , {0.f, 1.f, 0.f});
    myEngine.mvMatrixStack.addRotation(M_PI  , {0.f, 0.f, 1.f});
    // myEngine.mvMatrixStack.addRotation(M_PI, {0.f, 0.f, 1.f});
    myEngine.mvMatrixStack.addHomothety({50 * size_grid, 1, 50 * size_grid});
    myEngine.updateMvMatrix();
    myEngine.activateTexturing(true);
    textureNy.attachTexture();
    myEngine.setFlatColor(0.5, 0.5, 0.5);
    rectangle->draw();
    textureNy.detachTexture();
    myEngine.activateTexturing(false);
    myEngine.mvMatrixStack.popMatrix();
}