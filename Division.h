#pragma once
#include "Fighter.h"
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Division
{
private:
	string belt;
	double weightClass;
	bool isMale;
	bool isGi;
	vector<Fighter> participants;
	vector<Fighter> bracket;

public:
	// constructors
	Division() {
		belt = "WHITE";
		isMale = true;
		isGi = false;
		weightClass = 79.5;
	}
	Division(string b, double w, bool m, bool g) {
		belt = b;
		isMale = m;
		isGi = g;
		weightClass = w;
	}
	// getters and setters
	string getBelt(){
		return belt;
	}
	void setBelt(string s) {
		belt = s;
	}
	void setWeightClass(double w) {
		weightClass = w;
	}
	double getWeightClass() {
		return weightClass;
	}
	vector<Fighter> getParticipants() {
		return participants;
	}
	void setParticipants(vector<Fighter> v) {
		participants = v;
	}
	bool getIsMale() {
		return isMale;
	}
	bool setIsMale(bool b) {
		isMale = b;
	}
	bool getIsGi() {
		return isGi;
	}
	bool setIsGi(bool b) {
		isGi = b;
	}

	// other methods 
	void addParticipant(Fighter f) {
		participants.push_back(f);
	}
	void removeParticipant(Fighter f) {
		bool flag = false;
		for (auto i = participants.begin(); i != participants.end(); ++i) {
			if (*i == f) {
				participants.erase(i);
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << f << "is not a participant so couldn't be removed" << endl;
		}

	}
	void printParticipants() {
		isMale ? cout << "Male " : cout << "Female ";
		isGi ? cout << "Gi " : cout << "No-gi ";
		cout << belt << " " << weightClass << "kg:" << endl;
		for (Fighter f : participants) {			
			cout << f.getName() <<"\t"<<f.getTeam()<< endl;
		}
		cout << endl;
		
	}
	void randomiseParticipantsOrder() {
		int n = participants.size();
		// if n<2 do not change order of participants
		if (n > 1) {
			random_shuffle(participants.begin(),participants.end());
		}
	}
	void createBracket() {
		int copy = participants.size();
		int n = copy;
		int len{};		// number of rounds
		while (n) {
			len++;
			n = n / 2;
		}
		if (copy == 2 || copy == 4 || copy == 8 || copy == 16 || copy == 32 || copy == 64 || copy == 128) {
			// if the number of participants is a power of 2 the bracket is perfectly filled already. (no byes to add)
			len--;
		}
		int byes = pow(2, len) - copy;		// number of byes to add into the bracket
		while (byes) {
			byes--;
			participants.push_back(Fighter(1));	//add byes to participants
		}
		randomiseParticipantsOrder();
		displayBracket();
	}
	void displayBracket() {
		int i = 1;
		cout << "----------------------------------------" << endl;
		cout << belt << " " << weightClass << "kg:" << endl;
		cout << "----------------------------------------" << endl;
		for (auto f : participants) {
			cout << i << ". " << f.getName() << endl << f.getTeam() << endl << endl;
			i++;
		}
		cout << "----------------------------------------" << endl;
	}
};

// overloaded operators
inline bool operator==(Division& lhs, Division& rhs)
{
	return lhs.getBelt() == rhs.getBelt() && lhs.getWeightClass() == rhs.getWeightClass()
		&& lhs.getIsGi()== rhs.getIsGi() && lhs.getIsMale() == rhs.getIsMale();
}