#pragma once
#include <iostream>

class Team {
public:
	int win;
	int draw;
	int lose;
	int goal;
	int lost_goal;
	int points;

public:

	int count_points() {
		return win * 3 + draw;
	}

	Team() {
		win = 3;
		draw = 2;
		lose = 5;
		goal = 2;
		lost_goal = 6;
		points = count_points();
	}

	bool operator<(const Team& other) const {
		return win < other.win;
	}

	friend std::ostream& operator<<(std::ostream& os, const Team& t) {
		os << "\t\033[32mWins : " << t.win << "\tDraws : " << t.draw << "\t\033[31mLooses : " << t.lose;
		os << "\t\033[32mGoals : " << t.goal << "\t\033[31mLost Goals : " << t.lost_goal;
		os << "\033[37m";
		return os;
	}
};
