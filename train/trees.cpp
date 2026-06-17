#include "trees.hpp"

void pine()
{
    float incr_z{};
    float incr_color{};
    float incr_xy{};

    // Tronc centré en (0,0)
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.025f * size_grid, 0.40f * size_grid, 0.025f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.52f, 0.34f, 0.05f);
    cyl->draw();
    myEngine.mvMatrixStack.popMatrix();

    // Feuillage cônes centrés en (0,0)
    for (int i{}; i < 3; i++)
    {
        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.0f, 0.0f, (0.2f + incr_z) * size_grid});
        myEngine.mvMatrixStack.addHomothety({(0.15f + incr_xy) * size_grid, (0.15f + incr_xy) * size_grid, 0.35f * size_grid});
        myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
        myEngine.updateMvMatrix();
        myEngine.setFlatColor(0.f, 0.3f + incr_color, 0.05f);
        cone->draw();
        myEngine.mvMatrixStack.popMatrix();

        incr_z += 0.15f;
        incr_color += 0.15f;
        incr_xy -= 0.03f;
    }
}

void tree()
{
    // Tronçon principal
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addRotation(M_PI / 2, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.025f * size_grid, 0.60f * size_grid, 0.025f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.52f, 0.34f, 0.05f);
    cyl->draw();
    myEngine.mvMatrixStack.popMatrix();

    // Boule de feuilles principale
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.0f, 0.0f, 0.7f * size_grid});
    myEngine.mvMatrixStack.addHomothety({0.18f * size_grid, 0.18f * size_grid, 0.18f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.f, 0.5f, 0.05f);
    sphere->draw();
    myEngine.mvMatrixStack.popMatrix();

    // Branche de droite
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.0f, 0.0f, 0.3f * size_grid});
    myEngine.mvMatrixStack.addRotation(M_PI / 4, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.025f * size_grid, 0.20f * size_grid, 0.025f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.52f, 0.34f, 0.05f);
    cyl->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.0f, 0.15f * size_grid, 0.45f * size_grid}); // 0.65f - 0.5f = 0.15f
    myEngine.mvMatrixStack.addHomothety({0.08f * size_grid, 0.08f * size_grid, 0.08f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.f, 0.5f, 0.05f);
    sphere->draw();
    myEngine.mvMatrixStack.popMatrix();

    // Branche de gauche
    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.0f, 0.0f, 0.2f * size_grid});
    myEngine.mvMatrixStack.addRotation(3 * M_PI / 4, {1.0f, 0.0f, 0.0f});
    myEngine.mvMatrixStack.addHomothety({0.025f * size_grid, 0.30f * size_grid, 0.025f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.52f, 0.34f, 0.05f);
    cyl->draw();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.0f, -0.2f * size_grid, 0.4f * size_grid}); // 0.3f - 0.5f = -0.2f
    myEngine.mvMatrixStack.addHomothety({0.1f * size_grid, 0.1f * size_grid, 0.1f * size_grid});
    myEngine.updateMvMatrix();
    myEngine.setFlatColor(0.f, 0.5f, 0.05f);
    sphere->draw();
    myEngine.mvMatrixStack.popMatrix();
}

void treesPlacement()
{
    int sizeTreeTab{int(treesPos.size())};

    for (int i = 0; i < sizeTreeTab; i++)
    {
        std::array<int, 2> position = treesPos[i];

        float translationX = (position[0] * size_grid) + (size_grid / 2.0f);
        float translationY = (position[1] * size_grid) + (size_grid / 2.0f);

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({translationX, translationY, 0});
        myEngine.mvMatrixStack.addHomothety({2.f, 2.f, 2.f});
        myEngine.updateMvMatrix();
        tree();
        myEngine.mvMatrixStack.popMatrix();
    }

    int sizePineTab{int(pinePos.size())};

    for (int i = 0; i < sizePineTab; i++)
    {
        std::array<int, 2> position = pinePos[i];

        float translationX = (position[0] * size_grid) + (size_grid / 2.0f);
        float translationY = (position[1] * size_grid) + (size_grid / 2.0f);

        myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({translationX, translationY, 0});
        myEngine.mvMatrixStack.addHomothety({2.f, 2.f, 2.f});
        myEngine.updateMvMatrix();
        pine();
        myEngine.mvMatrixStack.popMatrix();
    }
}