#include "rails.hpp"

void rails_straight()
{
	// Les rails
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({3.f, 5.f, sr / 2 + 2 * rr});
	myEngine.mvMatrixStack.addHomothety({sr, size_grid, sr});
	myEngine.updateMvMatrix();
	myEngine.setFlatColor(0.5, 0.5, 0.5);
	cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({7.f, 5.f, sr / 2 + 2 * rr});
	myEngine.mvMatrixStack.addHomothety({sr, size_grid, sr});
	myEngine.updateMvMatrix();
	myEngine.setFlatColor(0.5, 0.5, 0.5);
	cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	// Les balasts
	for (int i{}; i < 5; i++)
	{
		myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({8.f, (sx + rr) + i * (2.0f * sx + 2.0f * rr), rr});
		myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.f, 0.f, 1.f});
		myEngine.mvMatrixStack.addHomothety({rr, 6.f, rr});
		myEngine.updateMvMatrix();
		myEngine.setFlatColor(1.f, 0.7, 0.f);
		closedCylinder();
		myEngine.mvMatrixStack.popMatrix();
	}
}

void rails_curved()
{
	// Le rail intérieur
	for (int i{}; i < 101; i++)
	{
		float teta = M_PI / 200 * i;
		myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addRotation(teta - M_PI / 2, {0.f, 0.f, 1.f});
		myEngine.mvMatrixStack.addTranslation({0.f, 3.f, 3 * rr});
		myEngine.mvMatrixStack.addHomothety({sr, sr, sr});
		myEngine.updateMvMatrix();
		myEngine.setFlatColor(0.5, 0.5, 0.5);
		cube->draw();
		myEngine.mvMatrixStack.popMatrix();
	}
	// Le rail extérieur
	for (int i{}; i < 101; i++)
	{
		float teta = M_PI / 200 * i;
		myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addRotation(teta - M_PI / 2, {0.f, 0.f, 1.f});
		myEngine.mvMatrixStack.addTranslation({0.f, 7.f, 3 * rr});
		myEngine.mvMatrixStack.addHomothety({sr, sr, sr});
		myEngine.updateMvMatrix();
		myEngine.setFlatColor(0.5, 0.5, 0.5);
		cube->draw();
		myEngine.mvMatrixStack.popMatrix();
	}
	// Les balasts
	for (int i{1}; i < 4; i++)
	{
		float teta = M_PI / 8.f * i;
		myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addRotation(teta - M_PI / 2, {0.f, 0.f, 1.f});
		myEngine.mvMatrixStack.addTranslation({0.f, 2.f, rr});
		myEngine.mvMatrixStack.addHomothety({rr, 7.f, rr});
		myEngine.updateMvMatrix();
		myEngine.setFlatColor(1.f, 0.7f, 0.f);
		closedCylinder();
		myEngine.mvMatrixStack.popMatrix();
	}
}

void railsPlacement()
{
	int size{int(railsPos.size())};
	// std::cout << railsPos.size()<< std::endl;

	for (int i = 0; i < size; i++)
	{

		std::array<int, 2> prev = railsPos[(i - 1 + size) % size];
		std::array<int, 2> curr = railsPos[i];
		std::array<int, 2> next = railsPos[(i + 1) % size];

		myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({curr[0] * size_grid, curr[1] * size_grid, 0});
		myEngine.updateMvMatrix();
		// std::cout << curr[0] << curr[1] << std::endl;

		int dx1 = curr[0] - prev[0];
		int dy1 = curr[1] - prev[1];

		int dx2 = next[0] - curr[0];
		int dy2 = next[1] - curr[1];

		float angle{};

		if (dx1 != dx2 && dy1 != dy2)
		{
			if ((dx1 == 1 && dy2 == 1) || (dy1 == -1 && dx2 == -1))
			{
				angle = 3 * M_PI / 2;
			}
			else if ((dy1 == -1 && dx2 == 1) || (dx1 == -1 && dy2 == 1))
			{
				angle = M_PI;
			}
			else if ((dx1 == -1 && dy2 == -1) || (dy1 == 1 && dx2 == 1))
			{
				angle = M_PI /2;
			}
			else if ((dy1 == 1 && dx2 == -1) || (dx1 == 1 && dy2 == -1))
			{
				angle = 0.0f;
			}

			myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.5f * size_grid, 0.5f * size_grid, 0.f});
			myEngine.mvMatrixStack.addRotation(angle, {0.f, 0.f, 1.f});
			myEngine.mvMatrixStack.addTranslation({-0.5f * size_grid, -0.5f * size_grid, 0.f});
			myEngine.updateMvMatrix();
			rails_curved();
			myEngine.mvMatrixStack.popMatrix();
		}

		else
		{
			if (prev[1] == curr[1])
			{
				myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({0.5f * size_grid, 0.5f * size_grid, 0.f});
				myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.f, 0.f, 1.f});
				myEngine.mvMatrixStack.addTranslation({-0.5f * size_grid, -0.5f * size_grid, 0.f});
				myEngine.updateMvMatrix();
				rails_straight();
			}
			rails_straight();
			myEngine.mvMatrixStack.popMatrix();
		}
		myEngine.mvMatrixStack.popMatrix();
	}
}