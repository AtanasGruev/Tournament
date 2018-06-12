#ifndef GROUPSTAGE_GROUPSTAGE_GROUPSTAGE_H_
#define GROUPSTAGE_GROUPSTAGE_GROUPSTAGE_H_

#include "Group.h"

class GroupStage : public Group
{
private:
	Group* groupsInStage; // groups which take part in the group stage, determined by class Tournament
	int numGroups; // number of groups at play
	void copyGroupStage(const GroupStage&); // method which allows for more effective copying
public:
	GroupStage(const Group* = NULL, int = 0); //constructor
	GroupStage(const GroupStage&); //copy constructor
	GroupStage& operator=(const GroupStage&); //predefined operator=
	virtual ~GroupStage(); //destructor

	//setter and getter, the latter returns teams properly ranked
	int getNumGroups() const; 
	Group* getGroupsInStage() const;
	Team** getRankedTeams() const;

	//method is invoked whenever two groups participating in the need to account for the new ranking
	void swapGroups(int, int);
	//method allows for the conduct of all matches within the stage, thus applying a second ranking
	virtual void GroupStageSort();
};


#endif // !GROUPSTAGE_GROUPSTAGE_GROUPSTAGE_H_
