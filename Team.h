#ifndef TEAM_TEAM_TEAM_H_
#define TEAM_TEAM_TEAM_H_

#include <iostream>
#include <cassert>

#pragma warning (disable : 4996)

class Team
{
private:
	char* nameTeam; // name of the team taking part in the tournament
	int pointsTeam; // points from former tournaments or competitions
	int differencePoints; // differencePoints are used to determine the ranking of the teams in a group during the Group Stage
	void copyTeam(const Team&); // method which allows for more effective copying
public:
	Team(const char* = "", int = 0); // constructor
	Team(const Team&); // copy constructor
	Team& operator=(const Team&); // predefined operator=
	virtual ~Team(); // virtual destructor, extremely important when dealing with inheritance

	// getters and setters for the member-data
	const char* getName() const; 
	int getPoints() const;
	int getDifferencePoints() const;
	void setDifferencePoints(int);
	void setName(const char*);
	void setPoints(int);

	// method which conducts a match between two teams based on user input
	Team& matchInFinals(Team&);
};

#endif // !TEAM_TEAM_TEAM_H_
