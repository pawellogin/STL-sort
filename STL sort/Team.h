#pragma once
#include <iostream>
#include <random>

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
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, 4);
		std::uniform_int_distribution<int> dis_goal(0, 14);

		win = dis(gen);
		draw = dis(gen);
		lose = dis(gen);
		goal = std::uniform_int_distribution<int>(0, (2 * win) + draw)(gen);
		lost_goal = std::uniform_int_distribution<int>(0, (2 * lose) + draw)(gen);
		points = count_points();
	}

	bool operator>(const Team& other) const {
		if (points != other.points) {
			return (points > other.points);
		}
		else if (win != other.win) {
			return win > other.win;
		}
		else if (lose != other.lose) {
			return lose < other.lose;
		}
		else if (goal != other.goal) {
			return goal > other.goal;
		}
		else {
			return lost_goal < other.lost_goal;
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const Team& t) {
		os << "\t\033[32mWins : " << t.win << "\tDraws : " << t.draw << "\t\033[31mLooses : " << t.lose;
		os << "\t\033[32mGoals : " << t.goal << "\t\033[31mLost Goals : " << t.lost_goal;
		os << "\033[37m";
		return os;
	}
};
