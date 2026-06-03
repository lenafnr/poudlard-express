#include "rails.hpp"

void rails_straight() {
	// Les rails
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.3f * size_grid, 0.5f * size_grid, sr / 2 + 2 * rr});
		myEngine.mvMatrixStack.addHomothety({sr, size_grid, sr});
		myEngine.updateMvMatrix();
		myEngine.setFlatColor(0.5,0.5,0.5);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.7f * size_grid, 0.5f * size_grid, sr / 2 + 2 * rr});
		myEngine.mvMatrixStack.addHomothety({sr, size_grid, sr});
		myEngine.updateMvMatrix();
		myEngine.setFlatColor(0.5,0.5,0.5);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	// Les balasts
	for (int i {}; i < 5; i++) {
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.8f * size_grid, (sx + rr) + i * (2.0f * sx + 2.0f * rr), rr});
			myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.f, 0.f, 1.f});
			myEngine.mvMatrixStack.addHomothety({rr, 0.6f * size_grid, rr});
			myEngine.updateMvMatrix();
			myEngine.setFlatColor(1.f,0.7,0.f);
			closedCylinder();
		myEngine.mvMatrixStack.popMatrix();
	}
}

void rails_curved() {
	// Le rail intérieur
	for (int i{}; i < 101; i++) {
		float teta = M_PI / 200 * i;
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addRotation(teta - M_PI / 2, {0.f, 0.f, 1.f});
			myEngine.mvMatrixStack.addTranslation({0.f, 0.3f * size_grid, 3 * rr});
			myEngine.mvMatrixStack.addHomothety({sr, sr, sr});
			myEngine.updateMvMatrix();
			myEngine.setFlatColor(0.5,0.5,0.5);
			cube->draw();
		myEngine.mvMatrixStack.popMatrix();
	}
	// Le rail extérieur
	for (int i{}; i < 101; i++) {
		float teta = M_PI / 200 * i;
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addRotation(teta - M_PI / 2, {0.f, 0.f, 1.f});
			myEngine.mvMatrixStack.addTranslation({0.f, 0.7f * size_grid, 3 * rr});
			myEngine.mvMatrixStack.addHomothety({sr, sr, sr});
			myEngine.updateMvMatrix();
			myEngine.setFlatColor(0.5,0.5,0.5);
			cube->draw();
		myEngine.mvMatrixStack.popMatrix();
	}
	// Les balasts
    for (int i{1}; i < 4; i++) {
		float teta = M_PI / 8.f * i;
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addRotation(teta - M_PI / 2, {0.f, 0.f, 1.f});
			myEngine.mvMatrixStack.addTranslation({0.f, 0.15f * size_grid, rr});
			myEngine.mvMatrixStack.addHomothety({rr, 7.f, rr});
			myEngine.updateMvMatrix();
			myEngine.setFlatColor(1.f, 0.7f, 0.f);
			closedCylinder();
		myEngine.mvMatrixStack.popMatrix();
	}
}