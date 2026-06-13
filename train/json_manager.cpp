#include "json_manager.hpp"
#include "json.hpp"

using json = nlohmann::json;

std::array<int, 2> stationPos{};
std::vector<std::array<int, 2>> railsPos{};
std::vector<std::array<int, 2>> treesPos{};
std::vector<std::array<int, 2>> pinePos{};
std::vector<std::array<int, 2>> lampPos{};

void initJson()
{
	std::ifstream file("../data/props.json");

	if (!file.is_open())
	{
		std::cout << "JSON introuvable !" << std::endl;
		return;
	}

	json data;
	file >> data;

	railsPos.clear();

	for (const auto &p : data["path"])
	{
		railsPos.push_back({p[0].get<int>(),
							p[1].get<int>()});
	}

	stationPos = {
		data["origin"][0].get<int>(),
		data["origin"][1].get<int>()};

	treesPos.clear();

	for (const auto &p : data["trees"])
	{
		treesPos.push_back({p[0].get<int>(),
							p[1].get<int>()});
	}

	pinePos.clear();

	for (const auto &p : data["pine"])
	{
		pinePos.push_back({p[0].get<int>(),
						   p[1].get<int>()});
	}

	lampPos.clear();

	for (const auto &p : data["lamp"])
	{
		lampPos.push_back({p[0].get<int>(),
						   p[1].get<int>()});
	}

	size_grid = data["size_grid"].get<float>();
}