#pragma once
class MatchScore
{
private:
	int redScore, blueScore, redAdv, blueAdv;
	int redPen, bluePen;	//penalties
	bool submission, disqualification;
	bool redWon, blueWon, draw;
	// time

public:
	//constructors
	MatchScore() {
		redScore = 0;
		blueScore = 0;
		redAdv = 0;
		blueAdv = 0;
		redPen = 0;
		bluePen = 0;
		submission = false;
		disqualification = false;
		redWon = false;
		blueWon = false;
		draw = false;
	}
	//getters and setters
	int getRedScore() {
		return redScore;
	}
	void setRedScore(int s) {
		redScore = s;
	}
	int getBlueScore() {
		return blueScore;
	}
	void setBlueScore(int s) {
		blueScore = s;
	}
	int getRedAdv() {
		return redAdv;
	}
	void setRedAdv(int s) {
		redAdv = s;
	}
	int getBlueAdv() {
		return blueAdv;
	}
	void setBlueAdv(int s) {
		blueAdv = s;
	}
	int getRedPen() {
		return redPen;
	}
	void setRedPen(int s) {
		redPen = s;
	}
	int getBluePen() {
		return bluePen;
	}
	void setBluePen(int s) {
		bluePen = s;
	}
	bool getSubmission() {
		return submission;
	}
	void setSubmission(bool b) {
		submission = b;
	}
	bool getDisqualification() {
		return disqualification;
	}
	void setDisqualification(bool b) {
		disqualification = b;
	}
	bool getRedWon() {
		return redWon;
	}
	void setRedWon(bool b) {
		redWon = b;
	}
	bool getBlueWon() {
		return blueWon;
	}
	void setBlueWon(bool b) {
		blueWon = b;
	}
	bool isDraw() {
		return draw;
	}
	void setdraw(bool b) {
		draw = b;
	}

    /*friend ostream& operator<<(ostream& os, MatchScore& m) {
		os << "Score: " << m.getRedScore() << "-" << m.getBlueScore() << endl;
		if (m.getRedAdv() != 0 || m.getBlueAdv() != 0) {
			os << m.getRedAdv() << "-" << m.getBlueAdv() << " Advantages" << endl;
		}
		if (m.getRedPen() != 0 || m.getBluePen() != 0) {
			os << m.getRedPen() << "-" << m.getBluePen() << " Penalties" << endl;
		}
		if (m.getSubmission()) {
			os << "Submission!";
		}
		else if (m.getDisqualification()) {
			os << "DQ!";
		}
		else if (m.isDraw()) {
			os << "Draw";
		}
		return os;
	}*/



};
//// overloaded operator prototype
//ostream& operator<<(ostream&, MatchScore&);





