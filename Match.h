#pragma once
#include "Fighter.h"
#include "MatchScore.h"
class Match
{
private:
	string red;
	string blue;
	bool matchPlayed;
	MatchScore score;
public:
	// constructors
	Match() {
		red = "No name";
		blue = "No name";
		matchPlayed = false;
		score = MatchScore();
	}
	Match(string r, string b) {
		red = r;
		blue = b;
		matchPlayed = false;
		score = MatchScore();
	}
	// getters and setters
	string getRed() {
		return red;
	}
	void setRed(string s) {
		red = s;
	}
	string getBlue() {
		return blue;
	}
	void setBlue(string s) {
		blue = s;
	}
	bool getMatchPlayed() {
		return matchPlayed;
	}
	void setMatchPlayed(bool m) {
		matchPlayed = m;
	}
	MatchScore getScore() {
		return score;
	}
	void setScore(MatchScore ms) {
		score = ms;
	}
};

