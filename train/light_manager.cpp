#include "light_manager.hpp"
#include <array>
#include "objects.hpp"
#include "json_manager.hpp"

void initLights() {
    // Initialisation de la lumière (lune)
	myEngine.switchToPhongShading();
	myEngine.setLightPosition({3.0f * size_grid, 0.f, 4.0f * size_grid, 1.f}, 0);
	myEngine.setLightIntensity({90.f * size_grid, 90.f * size_grid, 180.f * size_grid});
	// Lampadaires
	// Lampadaire de la gare
	myEngine.addALight({(stationPos[0] + 0.2f) * size_grid, (stationPos[1] + 0.85f) * size_grid, 0.585f * size_grid, 1.f}, {3.f * size_grid, 3.f * size_grid, 3.f * size_grid});
	// Lampadaires du circuit
    for (const auto &position : lampPos) {
		float lampX = ((position[0] + 0.2f) * size_grid) + (size_grid / 2.0f);
		float lampY = ((position[1] + 0.85f) * size_grid) + (size_grid);
        float lampZ = 1.f * size_grid;
        
        myEngine.addALight({lampX, lampY, lampZ, 1.f}, {3.f * size_grid, 3.f * size_grid, 2.f * size_grid});
    }
	myEngine.switchToFlatShading();
}

void updateLight(int angle) {
    myEngine.switchToPhongShading();
    
    float a = M_PI * angle / 180.f;
    float x = std::cos(a) * 3.f * size_grid;
    float y = std::sin(a) * 3.f * size_grid;
    myEngine.setLightPosition({x, y, 4.f * size_grid, 1.f}, 0);

    // Les lampadaires
    // Lampadaire de la gare
    myEngine.setLightPosition({(stationPos[0] + 0.2f) * size_grid, (stationPos[1] + 0.85f) * size_grid, 0.585f * size_grid, 1.f}, 1);
    // Lampadaires du circuit
    int lightIndex = 2;
    for (const auto &position : lampPos) {
        float lampX = ((position[0] + 0.2f) * size_grid) + (size_grid / 2.0f);
        float lampY = ((position[1] + 0.85f) * size_grid) + (size_grid);
        float lampZ = 1.f * size_grid;
        myEngine.setLightPosition({lampX, lampY, lampZ, 1.f}, lightIndex);
        
        lightIndex++;
    }
}