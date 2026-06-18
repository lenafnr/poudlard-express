#include "train.hpp"
#include <array>

void wheels() {
    float big_radius {0.13f * size_grid};
    float little_radius {0.06f * size_grid};

    // Roues arrières
    for (float j{}; j <= 0.5; j+=0.5) {
        for (float i{}; i <= 0.3f; i+=0.3f) {
            myEngine.mvMatrixStack.pushMatrix();
                myEngine.mvMatrixStack.addTranslation({(0.2f + i) * size_grid, (0.25f + j) * size_grid, big_radius});
                // Pour rotation de la rangée de gauche
                if (j > 0.f)
                    myEngine.mvMatrixStack.addRotation(M_PI, {0.f, 0.f, 1.f});
                myEngine.mvMatrixStack.addHomothety({big_radius, 0.05f * size_grid, big_radius});
                myEngine.updateMvMatrix();
                myEngine.setFlatColor(0.263f, 0.263f, 0.263f);
                closedCylinder();
            myEngine.mvMatrixStack.popMatrix();
        }
    }
    // Roues avant
    for (float j{}; j <= 0.5; j+=0.5) {
        for (float i{}; i <= 0.15f; i+=0.15f) {
            myEngine.mvMatrixStack.pushMatrix();
                myEngine.mvMatrixStack.addTranslation({(0.7f + i) * size_grid, (0.25f + j) * size_grid, little_radius});
                if (j > 0.f)
                    myEngine.mvMatrixStack.addRotation(M_PI, {0.f, 0.f, 1.f});
                myEngine.mvMatrixStack.addHomothety({little_radius, 0.05f * size_grid, little_radius});
                myEngine.updateMvMatrix();
                myEngine.setFlatColor(0.263f, 0.263f, 0.263f);
                closedCylinder();
            myEngine.mvMatrixStack.popMatrix();
        }
    }
}

void body() {
    float center_grid {0.5f * size_grid};
    float body_width {0.4f * size_grid};
    float body_radius {0.2f * size_grid};

    // Corps cylindrique
    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.7f * size_grid, center_grid, 0.4f * size_grid});
        myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.f, 0.f, 1.f});
        myEngine.mvMatrixStack.addHomothety({body_radius, 0.4f * size_grid, body_radius});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(0.56f, 0.055f, 0.063f);
        cyl->draw();
    myEngine.mvMatrixStack.popMatrix();
    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.92f * size_grid, center_grid, 0.4f * size_grid});
        myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.f, 0.f, 1.f});
        myEngine.mvMatrixStack.addHomothety({body_radius, 0.22f * size_grid, body_radius});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(0.f, 0.f, 0.f);
        cyl->draw();
    myEngine.mvMatrixStack.popMatrix();

    // Corps rectangulaire
    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.45f * size_grid, center_grid, 0.15f * size_grid});
        myEngine.mvMatrixStack.addHomothety({0.9f * size_grid, body_width, 0.12f * size_grid});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(0.f,0.f,0.f);
        cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.2f * size_grid, center_grid, 0.45f * size_grid});
        myEngine.mvMatrixStack.addHomothety({0.4f * size_grid, body_width, 0.5f * size_grid});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(0.4f, 0.0f, 0.063f);
        cube->draw();
    myEngine.mvMatrixStack.popMatrix();
    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.2f * size_grid, center_grid, 0.71f * size_grid});
        myEngine.mvMatrixStack.addHomothety({0.4f * size_grid, body_width, 0.02f * size_grid});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(0.f, 0.f, 0.f);
        cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.92f * size_grid, center_grid, 0.4f * size_grid});
        myEngine.mvMatrixStack.addHomothety({0.05f * size_grid, body_radius, body_radius});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(0.f, 0.f, 0.f);
        sphere->draw();
    myEngine.mvMatrixStack.popMatrix();

    // Ornements
    // Barre horizontale
    float incr_x{};
    float incr_y{};
    for (float j{}; j < 2; j++) {
        myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addTranslation({0.6f * size_grid, (0.3f + incr_y) * size_grid, 0.4f * size_grid});
            myEngine.mvMatrixStack.addHomothety({0.6f * size_grid, 0.01f * size_grid, 0.03f * size_grid});
            myEngine.updateMvMatrix();
            myEngine.activateTexturing(true);
            textureGold.attachTexture();
            myEngine.setFlatColor(1.f,1.f,0.f);
            cube->draw();
            textureGold.detachTexture();
            myEngine.activateTexturing(false);
        myEngine.mvMatrixStack.popMatrix();
        for (float i{}; i < 4; i++) {
            myEngine.mvMatrixStack.pushMatrix();
                myEngine.mvMatrixStack.addTranslation({(0.3f + incr_x) * size_grid, (0.3f + incr_y) * size_grid, 0.4f * size_grid});
                myEngine.mvMatrixStack.addHomothety({0.04f * size_grid, 0.01f * size_grid, 0.04f * size_grid});
                myEngine.updateMvMatrix();
                myEngine.activateTexturing(true);
                textureGold.attachTexture();
                myEngine.setFlatColor(1.f,1.f,0.f);
                sphere->draw();
                textureGold.detachTexture();
                myEngine.activateTexturing(false);
            myEngine.mvMatrixStack.popMatrix();

            incr_x += 0.2f;
        }
        incr_x = 0;
        incr_y += 0.4f;
    }

    float chimney_radius {0.04f * size_grid};
    // Cheminées
    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.6f * size_grid, center_grid, 0.6f * size_grid});
        myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.f, 0.f, 0.f});
        myEngine.mvMatrixStack.addHomothety({chimney_radius, 0.07f * size_grid, chimney_radius});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(1.f, 1.f, 0.f);
        cyl->draw();
    myEngine.mvMatrixStack.popMatrix();
    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.85f * size_grid, center_grid, 0.6f * size_grid});
        myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.f, 0.f, 0.f});
        myEngine.mvMatrixStack.addHomothety({chimney_radius, 0.07f * size_grid, chimney_radius});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(0.f, 0.f, 0.f);
        cyl->draw();
    myEngine.mvMatrixStack.popMatrix();
    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.85f * size_grid, center_grid, 0.67f * size_grid});
        myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.f, 0.f, 0.f});
        myEngine.mvMatrixStack.addHomothety({chimney_radius, 0.04f * size_grid, chimney_radius});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(1.f, 1.f, 0.f);
        cyl->draw();
    myEngine.mvMatrixStack.popMatrix();

    // Barre roue
    for (float j{}; j <= 0.5; j+=0.5) {
        myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addTranslation({0.45f * size_grid, (0.25f + j) * size_grid, 0.15f * size_grid});
            myEngine.mvMatrixStack.addHomothety({0.9f * size_grid, 0.01f * size_grid, 0.03f * size_grid});
            myEngine.updateMvMatrix();
            myEngine.setFlatColor(0.4f, 0.0f, 0.063f);
            cube->draw();
        myEngine.mvMatrixStack.popMatrix();
    }
}

void smoke() {
    float center_grid {0.5f * size_grid};
    float incr_x {};
    float incr_z {};
    for (float i{}; i < 2; i++) {
        myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addTranslation({(0.82f + incr_x) * size_grid, center_grid, 0.75f * size_grid});
            myEngine.mvMatrixStack.addHomothety({0.1f * size_grid, 0.07f * size_grid, 0.07f * size_grid});
            myEngine.updateMvMatrix();
            myEngine.activateTexturing(true);
            textureCloud.attachTexture();
            myEngine.setFlatColor(1.f,1.f,0.f);
            sphere->draw();
            textureCloud.detachTexture();
            myEngine.activateTexturing(false);
        myEngine.mvMatrixStack.popMatrix();

        incr_x=-0.18f;
    }
    for (float i{}; i < 2; i++) {
        myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addTranslation({0.7f * size_grid, center_grid, (0.72f + incr_z) * size_grid});
            myEngine.mvMatrixStack.addHomothety({0.08f * size_grid, 0.07f * size_grid, 0.07f * size_grid});
            myEngine.updateMvMatrix();
            myEngine.activateTexturing(true);
            textureCloud.attachTexture();
            myEngine.setFlatColor(1.f,1.f,0.f);
            sphere->draw();
            textureCloud.detachTexture();
            myEngine.activateTexturing(false);
        myEngine.mvMatrixStack.popMatrix();

        incr_z=0.06f;
    }
    myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addTranslation({0.55f * size_grid, center_grid, 0.8f * size_grid});
            myEngine.mvMatrixStack.addHomothety({0.1f * size_grid, 0.07f * size_grid, 0.07f * size_grid});
            myEngine.updateMvMatrix();
            myEngine.activateTexturing(true);
            textureCloud.attachTexture();
            myEngine.setFlatColor(1.f,1.f,0.f);
            sphere->draw();
            textureCloud.detachTexture();
            myEngine.activateTexturing(false);
        myEngine.mvMatrixStack.popMatrix();
}

void trainPlacement() {
    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({(trainPos[0] + 0.5f) * size_grid, (trainPos[1] + 0.5f) * size_grid, 0.2f * size_grid});
        myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.f, 0.f, 1.f});
        myEngine.mvMatrixStack.addTranslation({-0.5f * size_grid, -0.5f * size_grid, 0.f});
        myEngine.updateMvMatrix();
        train();
	myEngine.mvMatrixStack.popMatrix();
}

void train() {
    wheels();
    body();
    smoke();
}