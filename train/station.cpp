#include "station.hpp"
#include <array>

void bench()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.6f * size_grid, 0.5f * size_grid, 0.225f * size_grid});
    myEngine.mvMatrixStack.addHomothety({0.2f * size_grid, 0.6f * size_grid, 0.05f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.357f, 0.188f, 0.02f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    const float baseX = 0.525f * size_grid;
    const float baseY = 0.25f * size_grid;

    const float stepX = 0.15f * size_grid;
    const float stepY = 0.5f * size_grid;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            float translationX = baseX + i * stepX;
            float translationY = baseY + j * stepY;

            myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addTranslation({translationX, translationY, 0.15f * size_grid});
            myEngine.mvMatrixStack.addHomothety({0.05f * size_grid, 0.05f * size_grid, 0.1f * size_grid});
            myEngine.updateMvMatrix();
            myEngine.setFlatColor(0.0f, 0.0f, 0.0f);
            cube->draw();
            myEngine.mvMatrixStack.popMatrix();
        }
    }
}

void groundStation()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.5f * size_grid, 0.5f * size_grid, 0.05f * size_grid});
    myEngine.mvMatrixStack.addHomothety({1.0f * size_grid, 1.0f * size_grid, 0.1f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.486f, 0.486f, 0.486f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();
}

void wallStation()
{
    const float baseY = 0.15f * size_grid;
    const float baseZ = 0.125f * size_grid;

    const float stepY = 0.1f * size_grid;
    const float stepZ = 0.05f * size_grid;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            float transaltionY = baseY + i * stepY;
            float translationZ = baseZ + j * stepZ;

            myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addTranslation({0.95f * size_grid, transaltionY, translationZ});
            myEngine.mvMatrixStack.addHomothety({0.1f * size_grid, 0.1f * size_grid, 0.05f * size_grid});
            myEngine.updateMvMatrix();

            if ((i + j) % 2 == 0)
            {
                myEngine.setFlatColor(0.945f, 0.831f, 0.659f);
            }

            else
            {
                myEngine.setFlatColor(0.808f, 0.698f, 0.459f);
            }
            cube->draw();
            myEngine.mvMatrixStack.popMatrix();
        }
    }

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.0f * size_grid, 1.0f * size_grid, 0.2f * size_grid});
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({1.0f * size_grid, 0.80f * size_grid, 0.0f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.263f, 0.263f, 0.263f);
    arc.drawShape();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.0f * size_grid, 0.0f * size_grid, 0.2f * size_grid});
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({1.0f * size_grid, 0.80f * size_grid, 0.0f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.263f, 0.263f, 0.263f);
    arc.drawShape();
    myEngine.mvMatrixStack.popMatrix();
}

void roofStation()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.5f * size_grid, 0.5f * size_grid, 0.95f * size_grid});
    myEngine.mvMatrixStack.addHomothety({1.0f * size_grid, 1.0f * size_grid, 0.1f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.263f, 0.263f, 0.263f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    const float baseY = 0.05f * size_grid;
    const float stepY = 0.9f * size_grid;

    for (int i = 0; i < 2; i++)
    {
        float transaltionY = baseY + i * stepY;

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.95f * size_grid, transaltionY, 0.5f * size_grid});
        myEngine.mvMatrixStack.addHomothety({0.1f * size_grid, 0.1f * size_grid, 0.8f * size_grid});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(0.263f, 0.263f, 0.263f);
        cube->draw();
        myEngine.mvMatrixStack.popMatrix();
    }
}

void pannelStation()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.825f * size_grid, 0.5f * size_grid, 0.575f * size_grid});
    myEngine.mvMatrixStack.addHomothety({0.05f * size_grid, 0.6f * size_grid, 0.45f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.565f, 0.055f, 0.063f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    const float baseY = 0.3f * size_grid;
    const float baseZ = 0.475f * size_grid;

    const float stepY = 0.4f * size_grid;
    const float stepZ = 0.2f * size_grid;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            float transaltionY = baseY + i * stepY;
            float translationZ = baseZ + j * stepZ;

            myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addTranslation({0.875f * size_grid, transaltionY, translationZ});
            myEngine.mvMatrixStack.addHomothety({0.05f * size_grid, 0.05f * size_grid, 0.05f * size_grid});
            myEngine.updateMvMatrix();
            myEngine.setFlatColor(0.0f, 0.0f, 0.0f);
            cube->draw();
            myEngine.mvMatrixStack.popMatrix();
        }
    }

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.799f * size_grid, 0.5f * size_grid, 0.575f * size_grid});
    myEngine.mvMatrixStack.addRotation(-M_PI / 2, {1, 0, 0});
    myEngine.mvMatrixStack.addHomothety({0.01f * size_grid, 0.1742f * size_grid, 0.1742f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.activateTexturing(true);
    texturePlatform.attachTexture();
    myEngine.setFlatColor(1.f, 1.f, 1.f);
    sphere->draw();
    texturePlatform.detachTexture();
    myEngine.activateTexturing(false);
    myEngine.mvMatrixStack.popMatrix();
}

void lamp()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.2f * size_grid, 0.85f * size_grid, 0});
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.025f * size_grid, 0.50f * size_grid, 0.025f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.0f, 0.0f, 0.0f);
    cyl->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.2f * size_grid, 0.85f * size_grid, 0.51f * size_grid});
    myEngine.mvMatrixStack.addHomothety({0.15f * size_grid, 0.15f * size_grid, 0.02f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.0f, 0.0f, 0.0f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.2f * size_grid, 0.85f * size_grid, 0.585f * size_grid});
    myEngine.mvMatrixStack.addHomothety({0.1f * size_grid, 0.1f * size_grid, 0.13f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(1.f, 1.f, 1.f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.2f * size_grid, 0.85f * size_grid, 0.66f * size_grid});
    myEngine.mvMatrixStack.addHomothety({0.15f * size_grid, 0.15f * size_grid, 0.02f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.0f, 0.0f, 0.0f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.2f * size_grid, 0.85f * size_grid, 0.67f * size_grid});
    myEngine.mvMatrixStack.addHomothety({0.035f * size_grid, 0.035f * size_grid, 0.035f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.929f, 0.831f, 0.408f);
    sphere->draw();
    myEngine.mvMatrixStack.popMatrix();
}

void books()
{
    const float baseZ = 0.09f * size_grid;
    const float stepZ = 0.025f * size_grid;

    for (int i = 1; i < 4; i++)
    {
        float translationZ = baseZ + i * stepZ;
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.2f * size_grid, 0.15f * size_grid, translationZ});
        myEngine.mvMatrixStack.addRotation(M_PI / 6.0f + i * 0.5, {0.0f, 0.0f, 1.0f});
        myEngine.mvMatrixStack.addHomothety({0.05f * size_grid, 0.09f * size_grid, 0.025f * size_grid});
        myEngine.updateMvMatrix();
        if (i == 3)
            myEngine.setFlatColor(0.565f, 0.055f, 0.063f);
        if (i == 2)
            myEngine.setFlatColor(0.047f, 0.365f, 0.561f);
        if (i == 1)
            myEngine.setFlatColor(0.075f, 0.29f, 0.063f);
        cube->draw();
        myEngine.mvMatrixStack.popMatrix();
    }
}

void lampsPlacement()
{
    int size{int(lampPos.size())};

    for (int i = 0; i < size; i++)
    {
        std::array<int, 2> position = lampPos[i];

        float translationX = (position[0] * size_grid) + (size_grid / 2.0f);
        float translationY = (position[1] * size_grid) + (size_grid / 2.0f);

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({translationX, translationY, 0});
        myEngine.mvMatrixStack.addHomothety({2.f, 2.f, 2.f});
        myEngine.updateMvMatrix();
        lamp();
        myEngine.mvMatrixStack.popMatrix();
    }
}

float timer = 0.0f;

void harryPotter()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-1.2f * size_grid, 2.3f * size_grid, 0.f});
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.15f * size_grid, 0.6f * size_grid, 0.15f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.f, 0.f, 0.f);
    cone->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-1.2f * size_grid, 2.3f * size_grid, 0.57f * size_grid});
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.12f * size_grid, 0.4f * size_grid, 0.12f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.604f, 0.376f, 0.227f);
    cone->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-1.2f * size_grid, 2.3f * size_grid, 0.5f * size_grid});
    // myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.12f * size_grid, 0.12f * size_grid, 0.12f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(1.f, 0.859f, 0.722f);
    sphere->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-1.2f * size_grid, 2.3f * size_grid, 0.57f * size_grid});
    // myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.3f * size_grid, 0.3f * size_grid, 0.03f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.604f, 0.376f, 0.227f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-1.33f * size_grid, 2.35f * size_grid, 0.50f * size_grid});
    // myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.01f * size_grid, 0.025f * size_grid, 0.025f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(1.f, 0.859f, 0.722f);
    sphere->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-1.33f * size_grid, 2.25f * size_grid, 0.50f * size_grid});
    // myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.01f * size_grid, 0.025f * size_grid, 0.025f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(1.f, 0.859f, 0.722f);
    sphere->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-1.24f * size_grid, 2.4f * size_grid, 0.3f * size_grid});
    myEngine.mvMatrixStack.addRotation(M_PI / 4, {0.0f, 1.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.03f * size_grid, 0.1f * size_grid, 0.01f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.f, 0.f, 0.f);
    sphere->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-1.32f * size_grid, 2.35f * size_grid, 0.5f * size_grid});
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.0f, 1.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.04f * size_grid, 0.04f * size_grid, 0.04f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.f, 0.f, 0.f);
    circle.drawShape();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-1.32f * size_grid, 2.25f * size_grid, 0.5f * size_grid});
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.0f, 1.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.04f * size_grid, 0.04f * size_grid, 0.04f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.f, 0.f, 0.f);
    circle.drawShape();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-1.32f * size_grid, 2.3f * size_grid, 0.5f * size_grid});
    // myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.0f, 1.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.01f * size_grid, 0.05f * size_grid, 0.02f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.f, 0.f, 0.f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-1.24f * size_grid, 2.56f * size_grid, 0.37f * size_grid});
    myEngine.mvMatrixStack.addRotation(M_PI / 4, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.02f * size_grid, 0.2f * size_grid, 0.02f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.157f, 0.071f, 0.008f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    int nb_spheres = 5;

    for (int i = 0; i < nb_spheres; ++i)
    {
        myEngine.mvMatrixStack.pushMatrix();

        float forward = timer + (i * 0.12f);
        forward = fmod(forward, 1.0f);

        float y = forward * size_grid;
        float z = forward * size_grid;

        myEngine.mvMatrixStack.addTranslation({-1.24f * size_grid,
                                               (2.56f * size_grid) + y,
                                               (0.37f * size_grid) + z});

        float scale = 0.05f * (1.0f - forward);
        myEngine.mvMatrixStack.addHomothety({scale * size_grid, scale * size_grid, scale * size_grid});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(1.f, 0.91f, 0.106f);
        sphere->draw();
        myEngine.mvMatrixStack.popMatrix();
    }

    timer += 0.02f;
}

void stationPlacement() {
    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({stationPos[0] * size_grid, stationPos[1] * size_grid, 0});
        myEngine.updateMvMatrix();
        station();
	myEngine.mvMatrixStack.popMatrix();
}

void station()
{
    bench();
    groundStation();
    wallStation();
    roofStation();
    pannelStation();
    lamp();
    books();
    harryPotter();
}