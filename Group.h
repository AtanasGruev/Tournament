#ifndef GROUP_GROUP_GROUP_H_
#define GROUP_GROUP_GROUP_H_

#include "Team.h"

class Group : public Team
{
private:
	Team* teamsInGroup; // array of teams, which consists of either 3 or 4 teams, according to Tournament distribution
	int numTeams; // number of teams in the group, could be 3 or 4
	int totalDifference; // groups are also ranked according to the following rule: the more differencePoints teams inside a single group have,
						 // the higher current group ranks among the others
	void copyGroup(const Group&); // method which allows for more effective copying
public:
	Group(const Team* = NULL, int = 0); //constructor
	Group(const Group&); //copy constructor
	Group& operator=(const Group&); //predefined operator=
	virtual ~Group(); //destructor

	// setters and getters for the member-data
	void setTeams(const Team*, int);
	Team* getTeams() const;
	int getNumTeams() const;
	int getDifference() const;

	//method is invoked whenever two teams within a group need to account for the new ranking
	void swapTeams(int, int);
	//method allows for the conduct of all matches within a single group, nevermind its size
	void playMatch();
};

#endif // !GROUP_GROUP_GROUP_H_
