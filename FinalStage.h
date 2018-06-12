#ifndef FINALSTAGE_FINALSTAGE_FINALSTAGE_H_
#define FINALSTAGE_FINALSTAGE_FINALSTAGE_H_

#include "Team.h"

class FinalStage : public Team
{
private:
	Team* teamsInStage; // array of teams, which should have been sorted throughout the Group Stage
	int numTeams; // number of teams at play, possibly reduced to suit the rule which requires a (power ot 2) teams 
	bool powerOfTwo; // simple check whether the number of teams should be reduced or not
	void copyFinalStage(const FinalStage&); // method which allows for more effective copying
public:
	FinalStage(const Team* = NULL, int = 0); //constructor
	FinalStage(const FinalStage&); //copy constructor
	FinalStage& operator=(const FinalStage&); //predefined operator=
	virtual ~FinalStage(); //destructor
	void selectionPowerTwo(const Team*, int); //selects the first (max power of 2) best teams according to ranking 
	bool getPowerOfTwo() const; //accounts for the boolean variable
	int getNumTeams() const;
	Team* getTeamsInStage() const;
	//method which conducts the final stage and celebrates the winner
	virtual void finalStageSort();
};

#endif // !FINALSTAGE_FINALSTAGE_FINALSTAGE_H_
