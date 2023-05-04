#include <iostream>
#include <vector>
#include "Team.h"

int main() {
	std::vector<Team> league;

	for(int i = 0; i < 10; i++) {
		league.push_back(*(new Team));
	}

	std::cout << "\t\t\t\t\t\033[47m\033[30mbefore sorting\033[40m\n";
	std::cout << "\033[37m";

	for (auto& team : league) {
		std::cout << team << "\n";
	}
	
	std::sort(league.begin(), league.end(),std::greater<Team>());

	std::cout << "\n\n\n";
	std::cout << "\t\t\t\t\t\033[47m\033[30mafter sorting\033[40m\n";
	std::cout << "\033[37m";

	for (auto& team : league) {
		std::cout << team << "\n";
	}

	return 0;
}