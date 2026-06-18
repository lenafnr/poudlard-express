#pragma once
#include "draw_scene.hpp"

void initJson();

extern float size_grid;
extern std::array<int,2> stationPos;
extern std::array<int, 2> trainPos;
extern std::vector<std::array<int,2>> railsPos;
extern std::vector<std::array<int, 2>> treesPos;
extern std::vector<std::array<int, 2>> pinePos;
extern std::vector<std::array<int, 2>> lampPos;