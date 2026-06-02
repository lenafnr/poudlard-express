#include "rails.hpp"

void closedCylinder() {
	cyl->draw();
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f, 0.5f, 0.f});
		myEngine.mvMatrixStack.addRotation(M_PI/2, {1,0,0});
		myEngine.updateMvMatrix();
		circle.drawShape();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f, 0.f, 0.f});
		myEngine.mvMatrixStack.addRotation(M_PI/2, {1,0,0});
		myEngine.updateMvMatrix();
		circle.drawShape();
	myEngine.mvMatrixStack.popMatrix();
}

void rails_straight() {
	// Les rails
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({3.f, 5.f, sr / 2 + 2 * rr});
		myEngine.mvMatrixStack.addHomothety({sr, size_grid, sr});
		myEngine.updateMvMatrix();
		myEngine.setFlatColor(0.5,0.5,0.5);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({7.f, 5.f, sr / 2 + 2 * rr});
		myEngine.mvMatrixStack.addHomothety({sr, size_grid, sr});
		myEngine.updateMvMatrix();
		myEngine.setFlatColor(0.5,0.5,0.5);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	// Les balasts
	for (int i {}; i < 5; i++) {
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({8.f, (sx + rr) + i * (2.0f * sx + 2.0f * rr), rr});
			myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.f, 0.f, 1.f});
			myEngine.mvMatrixStack.addHomothety({rr, 6.f, rr});
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
			myEngine.mvMatrixStack.addTranslation({0.f, 5.f, 4 * rr});
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
			myEngine.mvMatrixStack.addTranslation({0.f, 9.f, 4 * rr});
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
			myEngine.mvMatrixStack.addTranslation({0.f, 4.f, rr});
			myEngine.mvMatrixStack.addHomothety({rr, 7.f, rr});
			myEngine.updateMvMatrix();
			myEngine.setFlatColor(1.f, 0.7f, 0.f);
			closedCylinder();
		myEngine.mvMatrixStack.popMatrix();
	}
}