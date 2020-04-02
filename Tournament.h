#pragma once
#include "Division.h"
#include "Fighter.h"
#include <string>
#include <vector>
using namespace std;


class Tournament
{
private:
	string name;
	Date startDate;
	Date endDate;
	vector<Division> divisions;
	bool registrationClosed;
	double entryFee;
public:
	// constructors
	Tournament() {
		name = "Tournament name";
		startDate = Date(1, 1, 2020);
		endDate = Date(1, 1, 2020);
		setIBJJFGiDivisions();
		entryFee = 0.00;
		registrationClosed = false;
	}
	Tournament(string s, Date st, Date e) {
		name = s;
		startDate = st;
		endDate = e;
		setIBJJFGiDivisions();
		entryFee = 0.00;
		registrationClosed = false;
	}

	// getters and setters
	void setName(string s) {
		name = s;
	}
	string getName() {
		return name;
	}
	void setStartDate(Date d) {
		startDate = d;
	}
	Date getStartDate() {
		return startDate;
	}
	void setEndDate(Date d) {
		endDate = d;
	}
	Date getEndDate() {
		return endDate;
	}
	double getEntryFee() {
		return entryFee;
	}
	void setEntryFee(double e) {
		entryFee = e;
	}
	vector<Division> getDivisions() {
		return divisions;
	}
	void setDivisions(vector<Division> d) {
		divisions = d;
	}
	bool getRegistrationClosed() {
		return registrationClosed;
	}
	void setRegistrationClosed(bool b) {
		registrationClosed = b;
	}

	// other methods 
	void randomiseDivisions() {
		for (Division &div : divisions) {
			div.randomiseParticipantsOrder();
		}
	}
	void closeRegistration() {
		setRegistrationClosed(true);
	}
	void setIBJJFGiDivisions() {
		vector<Division> temp;
		vector<string> belts{ "WHITE", "BLUE", "PURPLE", "BROWN", "BLACK" };
		vector<double> weightsMale{ 64,70,76,82.3,88.3, 94, 100.5, 150 };
		vector<double> weightsFemale{ 53.5,58.5,64,69,74, 79.3, 150 };
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 8; ++j) {
				temp.push_back(Division(belts[i], weightsMale[j],true,true));
			}
		}
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 7; ++j) {
				temp.push_back(Division(belts[i], weightsFemale[j], false, true));
			}
		}
		divisions = temp;
	}
	void setIBJJFNoGiDivisions() {
		vector<Division> temp;
		vector<string> belts{ "WHITE", "BLUE", "PURPLE", "BROWN", "BLACK" };
		vector<double> weightsMale{ 61.5,67.5,73.5,79.5,85.5, 91.5, 97.5, 150 };
		vector<double> weightsFemale{ 51.5,56.5,61.5,66.5,71.5, 76.5, 150 };
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 8; ++j) {
				temp.push_back(Division(belts[i], weightsMale[j],true,false));
			}
		}
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 7; ++j) {
				temp.push_back(Division(belts[i], weightsFemale[j], false,false));
			}
		}
		divisions=temp;
	}
	void setIBJJFGiAndNoGiDivisions() {
		setIBJJFGiDivisions();
		// push_back no gi divisions 
		vector<string> belts{ "white", "blue", "purple", "brown", "black" };
		vector<double> weightsMale{ 61.5,67.5,73.5,79.5,85.5, 91.5, 97.5, 150 };
		vector<double> weightsFemale{ 51.5,56.5,61.5,66.5,71.5, 76.5, 150 };
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 8; ++j) {
				divisions.push_back(Division(belts[i], weightsMale[j], true, false));
			}
		}
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 7; ++j) {
				divisions.push_back(Division(belts[i], weightsFemale[j], false, false));
			}
		}
	}
	void addDivision(Division d) {
		// only add if d is not already in divisions
		bool flag = false;
		for (auto div : divisions) {
			if (d == div) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "Failed to add new division- it's already in divisions" << endl;
		}
		else {
			divisions.push_back(d);
		}
	}
	void removeEmptyDivisions() {
		vector<Division> temp;
		for (auto& d : divisions) {
			if (d.getParticipants().size() != 0) {
				temp.push_back(d);
			}
		}
		divisions = temp;
	}
	void addParticipant(Fighter f, Division d) {
		if (!registrationClosed) {
			// if d is not in divisions add division first
			bool flag = false;
			for (auto div : divisions) {
				if (div == d) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				addDivision(d);
			}

			// add f into d by reference
			for (Division& div : divisions) {
				if (div == d) {
					div.addParticipant(f);
				}
			}
		}
		else {
			cout << "Registration closed- failed to add participant" << endl;
		}
	}
	void removeParticipant(Fighter f) {
		// remove fighter f from tournament
		// check if f is in any of the divsions
		bool flag = false;	// true if f is found
		for (auto &d : divisions) {
			auto participants = d.getParticipants();
			for (auto i = participants.begin(); i != participants.end(); ++i) {
				if (*i == f) {
					// remove participant when found
					d.removeParticipant(f);
					flag = true;
					break;
				}
			}
		}
		if (!flag) {
			cout << f << " is not a participant so couldn't be removed" << endl;
		}
	}
	void printParticipantsList() {
		cout << name << " participants list:" << endl << endl;
		for (auto division : divisions) {
			division.printParticipants();
		}
	}
	void createBrackets() {
		removeEmptyDivisions();
		cout << "Brackets:" << endl;
		for (auto div : divisions) {
			div.createBracket();
			cout << endl;
		}
	}
};

