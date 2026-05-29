#include "station.hpp"

const float U = size_grid;

void bench()
{

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.45f * U, 0.5f * U, 0.225f * U});
    myEngine.mvMatrixStack.addHomothety({0.2f * U, 0.6f * U, 0.05f * U});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.357f, 0.188f, 0.02f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    for (float i{}; i <= 0.15f; i += 0.15f)
    {
        for (float j{}; j <= 0.5f; j += 0.5f)
        {
            myEngine.mvMatrixStack.pushMatrix();
            myEngine.mvMatrixStack.addTranslation({(0.375f + i) * U, (0.25f + j) * U, 0.15f * U});
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
    const float baseY = 0.05f * U;
    const float baseZ = 0.125f * U;

    const float stepY = 0.1f * U;
    const float stepZ = 0.05f * U;

    for (int i = 0; i < 10; i++)
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
}

void roofStation()
{
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.5f * U, 0.5f * U, 0.95f * U});
    myEngine.mvMatrixStack.addHomothety({1.0f * U, 1.0f * U, 0.1f * U});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.945f, 0.831f, 0.659f);
    cube->draw();
    myEngine.mvMatrixStack.popMatrix();

    const float baseY = 0.05f * U;
    const float stepY = 0.9f * U;

    for (int i = 0; i < 2; i++)
    {
        float transaltionY = baseY + i * stepY;

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.125f * U, transaltionY, 0.5f * U});
        myEngine.mvMatrixStack.addHomothety({0.1f * U, 0.1f * U, 0.8f * U});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(0.945f, 0.831f, 0.659f);
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
}