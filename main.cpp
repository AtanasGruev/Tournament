#include "GroupStage.h"
#include "FinalStage.h"

Group* distributionInGroups(Team* arrTeams, int numTeams, int& numGroups)
{
	int remainder;
	if (numTeams % 4 == 0)
	{
		numGroups = numTeams / 4;
		remainder = 0;
	}
	else if (numTeams % 4 == 1)
	{
		numGroups = (numTeams - 9) / 4 + 3;
		remainder = 3;
	}
	else if (numTeams % 4 == 2)
	{
		numGroups = (numTeams - 6) / 4 + 2;
		remainder = 2;
	}
	else
	{
		numGroups = (numTeams - 3) / 4 + 1;
		remainder = 1;
	}

	int jumpInTeams = 0;

	Group* groupsInTournament = new Group[numGroups];
	assert(groupsInTournament);
	for (int i = 0; i < numGroups - remainder; i++)
	{
		groupsInTournament[i].setTeams(arrTeams + jumpInTeams, 4);
		jumpInTeams += 4;
	}
	for (int i = numGroups - remainder; i < numGroups; i++)
	{
		groupsInTournament[i].setTeams(arrTeams + jumpInTeams, 3);
		jumpInTeams += 3;
	}

	return groupsInTournament;
}

int main()
{

	int numTeams;
	int numGroups;
	std::cout << "Enter the number of teams:";
	std::cin >> numTeams;
	std::cout << std::endl;

	Team** arrTeams = new Team*[numTeams];
	assert(arrTeams);
	for (int i = 0; i < numTeams; i++)
	{
		char nameOfTeam[100];
		int pointsOfTeam;

		std::cout << "Enter the name of the " << i + 1 << "-st team: ";
		std::cin.ignore();
		std::cin.getline(nameOfTeam, 100, '\n');
		std::cout << std::endl;

		std::cout << "Enter the points of the " << i + 1 << "-st team: ";
		std::cin >> pointsOfTeam;
		std::cout << std::endl;

		arrTeams[i] = new Team(nameOfTeam, pointsOfTeam);
		assert(arrTeams[i]);
	}

	Group* arrGroups = distributionInGroups(*arrTeams, numTeams, numGroups);

	GroupStage groupStage(arrGroups, numGroups);
	groupStage.playMatch();
	groupStage.GroupStageSort();
	FinalStage finalStage(*groupStage.getRankedTeams(), numTeams);
	if (!finalStage.getPowerOfTwo()) finalStage.selectionPowerTwo(*groupStage.getRankedTeams(), numTeams);
	finalStage.finalStageSort();

	return 0;
}