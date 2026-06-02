#include "station.hpp"

const float U = size_grid;

void bench()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.6f * U, 0.5f * U, 0.225f * U});
    myEngine.mvMatrixStack.addHomothety({0.2f * U, 0.6f * U, 0.05f * U});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.357f, 0.188f, 0.02f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    const float baseX = 0.525f * U;
    const float baseY = 0.25f * U;

    const float stepX = 0.15f * U;
    const float stepY = 0.5f * U;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            float translationX = baseX + i * stepX;
            float translationY = baseY + j * stepY;

            myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addTranslation({translationX, translationY, 0.15f * U});
            myEngine.mvMatrixStack.addHomothety({0.05f * U, 0.05f * U, 0.1f * U});
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
    myEngine.mvMatrixStack.addTranslation({0.5f * U, 0.5f * U, 0.05f * U});
    myEngine.mvMatrixStack.addHomothety({1.0f * U, 1.0f * U, 0.1f * U});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.486f, 0.486f, 0.486f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();
}

void wallStation()
{
    const float baseY = 0.15f * U;
    const float baseZ = 0.125f * U;

    const float stepY = 0.1f * U;
    const float stepZ = 0.05f * U;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            float transaltionY = baseY + i * stepY;
            float translationZ = baseZ + j * stepZ;

            myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addTranslation({0.95f * U, transaltionY, translationZ});
            myEngine.mvMatrixStack.addHomothety({0.1f * U, 0.1f * U, 0.05f * U});
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
    myEngine.mvMatrixStack.addTranslation({0.0f * U, 1.0f * U, 0.2f * U});
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({1.0f * U, 0.80f * U, 0.0f * U});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.263f, 0.263f, 0.263f);
    arc.drawShape();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.0f * U, 0.0f * U, 0.2f * U});
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({1.0f * U, 0.80f * U, 0.0f * U});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.263f, 0.263f, 0.263f);
    arc.drawShape();
    myEngine.mvMatrixStack.popMatrix();
}

void roofStation()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.5f * U, 0.5f * U, 0.95f * U});
    myEngine.mvMatrixStack.addHomothety({1.0f * U, 1.0f * U, 0.1f * U});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.263f, 0.263f, 0.263f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    const float baseY = 0.05f * U;
    const float stepY = 0.9f * U;

    for (int i = 0; i < 2; i++)
    {
        float transaltionY = baseY + i * stepY;

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.95f * U, transaltionY, 0.5f * U});
        myEngine.mvMatrixStack.addHomothety({0.1f * U, 0.1f * U, 0.8f * U});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(0.263f, 0.263f, 0.263f);
        cube->draw();
        myEngine.mvMatrixStack.popMatrix();
    }
}

void pannelStation()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.825f * U, 0.5f * U, 0.575f * U});
    myEngine.mvMatrixStack.addHomothety({0.05f * U, 0.6f * U, 0.45f * U});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.565f, 0.055f, 0.063f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    const float baseY = 0.3f * U;
    const float baseZ = 0.475f * U;

    const float stepY = 0.4f * U;
    const float stepZ = 0.2f * U;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            float transaltionY = baseY + i * stepY;
            float translationZ = baseZ + j * stepZ;

            myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addTranslation({0.875f * U, transaltionY, translationZ});
            myEngine.mvMatrixStack.addHomothety({0.05f * U, 0.05f * U, 0.05f * U});
            myEngine.updateMvMatrix();
            myEngine.setFlatColor(0.0f, 0.0f, 0.0f);
            cube->draw();
            myEngine.mvMatrixStack.popMatrix();
        }
    }

    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.799f * U, 0.5f * U, 0.575f * U});
        myEngine.mvMatrixStack.addRotation(M_PI/2, {0,1,0});
        myEngine.mvMatrixStack.addHomothety({0.1742f * U, 0.1742f * U, 1.f});
        myEngine.updateMvMatrix();
        myEngine.activateTexturing(true);
        texturePlatform.attachTexture();
        myEngine.setFlatColor(1.f,1.f,1.f);
        circle.drawShape();
        texturePlatform.detachTexture();
        myEngine.activateTexturing(false);
    myEngine.mvMatrixStack.popMatrix();
}

void lamp()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.2f * U, 0.85f * U, 0.1f * U});
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.025f * U, 0.40f * U, 0.025f * U});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.0f, 0.0f, 0.0f);
    cyl->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.2f * U, 0.85f * U, 0.51f * U});
    myEngine.mvMatrixStack.addHomothety({0.15f * U, 0.15f * U, 0.02f * U});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.0f, 0.0f, 0.0f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.2f * U, 0.85f * U, 0.585f * U});
    myEngine.mvMatrixStack.addHomothety({0.1f * U, 0.1f * U, 0.13f * U});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.851f, 0.851f, 0.851f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.2f * U, 0.85f * U, 0.66f * U});
    myEngine.mvMatrixStack.addHomothety({0.15f * U, 0.15f * U, 0.02f * U});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.0f, 0.0f, 0.0f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.2f * U, 0.85f * U, 0.67f * U});
    myEngine.mvMatrixStack.addHomothety({0.035f * U, 0.035f * U, 0.035f * U});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.929f, 0.831f, 0.408f);
    sphere->draw();
    myEngine.mvMatrixStack.popMatrix();
}

void books()
{
    const float baseZ = 0.09f * U;
    const float stepZ = 0.025f * U;

    for (int i = 1; i < 4; i++)
    {
        float translationZ = baseZ + i * stepZ;
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.2f * U, 0.15f * U, translationZ});
        myEngine.mvMatrixStack.addRotation(M_PI / 6.0f + i * 0.5, {0.0f, 0.0f, 1.0f});
        myEngine.mvMatrixStack.addHomothety({0.05f * U, 0.09f * U, 0.025f * U});
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

void station()
{
    bench();
    groundStation();
    wallStation();
    roofStation();
    pannelStation();
    lamp();
    books();
}