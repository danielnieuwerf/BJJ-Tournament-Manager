#pragma once
#include "Date.h"
#include <string>
#include <vector>
using namespace std;
class Fighter
{
private:
	string firstName;
	string lastName;
	bool isMale;
	Date dateOfBirth;	// compare with current date to get age
	string nationality;
	string belt;
	short age;
	string team;
	short wins;
	short losses;
	short draws;
	//vector<Match> competitionHistory;

public:
	//constructors
	Fighter() {
		firstName = "No";
		lastName = "name";
		isMale = true;
		dateOfBirth = Date();
		nationality = "None";
		belt = "White";
		age = 0;
		team = "No team/affiliation";
		wins = 0;
		losses = 0;
		draws = 0;
		//competitionHistory = {};
	}
	Fighter(int b) {
		// Fighter(int) creates bye
		firstName = "BYE";
		lastName = "";
		isMale = true;
		dateOfBirth = Date();
		nationality = "";
		belt = "";
		age = 0;
		team = "";
		wins = 0;
		losses = 0;
		draws = 0;
	}
	Fighter(string f, string l, bool m) {
		firstName = f;
		lastName = l;
		isMale = m;
		dateOfBirth = Date();
		nationality = "Unknown";
		belt = "Unknown";
		age = 0;
		team = "Unknown";
		wins = 0;
		losses = 0;
		draws = 0;
	}
	Fighter(string f, string l, bool m, Date d, string n,
		string b, short a, string t) {
		firstName = f;
		lastName = l;
		isMale = m;
		dateOfBirth = d;
		nationality = n;
		belt = b;
		age = a;
		team = t;
		wins = 0;
		losses = 0;
		draws = 0;
		//competitionHistory = {};
	}

	// overloaded operators
	bool operator==(Fighter& rhs) {
		// equality by full name change this to unique fighter ID
		return this->getName() == rhs.getName();
	}
	friend ostream& operator<<(ostream& os, Fighter& f) {
		os << f.getName();
		return os;
	}

	// getters and setters
	string getName() {
		return firstName + " " + lastName;
	}
	short getAge() {
		return age;
	}
	string getBelt() {
		return belt;
	}
	string getNation() {
		return nationality;
	}
	string getTeam() {
		return team;
	}
	short getWins() {
		return wins;
	}
	short getLosses() {
		return losses;
	}
	short getDraws() {
		return draws;
	}
	void setBelt(string b) {
		belt = b;
	}
	void setDraws(short d) {
		draws = d;
	}
	void setLosses(short l) {
		losses = l;
	}
	void setWins(short w) {
		wins = w;
	}

	// other methods
	void fighterProfile() {
		cout << getName() << endl;
		cout << "Nationality: " << getNation() << endl;
		cout << "Age:" << getAge() << "\tRank:" << belt << endl;
		cout << "Team:" << getTeam() << endl;
		if (draws == 0) {
			cout << "Wins:" << getWins() << "\tLosses:" << getLosses()<<endl;
		}
		else {
			cout << "Wins:" << getWins() << "\tLosses:" << getLosses() <<
				"\tDraws:" << getDraws() << endl;
		}
	}
	//void payEntryFee(Tournament t, Division d) {
	//	t.addParticipant(*this, d);
	//}
}; 