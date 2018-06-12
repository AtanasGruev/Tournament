#include "FinalStage.h"

void FinalStage::copyFinalStage(const FinalStage& finalStage)
{
	numTeams = finalStage.numTeams;
	teamsInStage = new Team[numTeams];
	assert(teamsInStage);
	for (int i = 0; i < numTeams; i++)
	{
		teamsInStage[i] = finalStage.teamsInStage[i];
	}
	powerOfTwo = finalStage.powerOfTwo;
}

FinalStage::FinalStage(const Team* teams, int num)
{
	numTeams = num;
	teamsInStage = new Team[numTeams];
	assert(teamsInStage);
	for (int i = 0; i < numTeams; i++)
	{
		teamsInStage[i] = teams[i];
	}
	if (ceil(log2(num)) == floor(log2(num))) powerOfTwo = true;
	else powerOfTwo = false;
}

FinalStage::FinalStage(const FinalStage& finalStage)
{
	copyFinalStage(finalStage);
}

FinalStage& FinalStage::operator=(const FinalStage& finalStage)
{
	if (this != &finalStage)
	{
		delete[] teamsInStage;
		copyFinalStage(finalStage);
	}
	return *this;
}

FinalStage::~FinalStage()
{
	delete[] teamsInStage;
}

bool FinalStage::getPowerOfTwo() const
{
	return powerOfTwo;
}

int FinalStage::getNumTeams() const
{
	return numTeams;
}

Team* FinalStage::getTeamsInStage() const
{
	return teamsInStage;
}

void FinalStage::selectionPowerTwo(const Team* rankedTeams, int numRanked)
{
	delete[] teamsInStage;
	if (ceil(log2(numRanked)) == floor(log2(numRanked))) numTeams = numRanked;
	else numTeams = pow(2, floor(log2(numRanked)));
	teamsInStage = new Team[numTeams];
	assert(teamsInStage);
	for (int i = 0; i < numTeams; i++)
	{
		teamsInStage[i] = rankedTeams[i];
	}
}

void FinalStage::finalStageSort()
{
	while (numTeams / 2 != 1)
	{
		int numberOfMatches = numTeams / 2;
		std::cout << "1/" << numberOfMatches << " Stage:" << std::endl;
		Team* finalists = new Team[numTeams];
		assert(finalists);
		for (int i = 0; i < numTeams; i++)
		{
			finalists[i] = teamsInStage[i];
		}

		delete[] teamsInStage;
		teamsInStage = new Team[numberOfMatches];
		assert(teamsInStage);
		int* teamsChosen = new int[numberOfMatches];
		assert(teamsChosen);
		for (int i = 0; i < numTeams; i += 2)
		{
			std::cout << "Please select which teams will compete against each other: " << std::endl;
			std::cin >> teamsChosen[i]; std::cout << " vs. "; std::cin >> teamsChosen[i + 1];
			teamsInStage[i / 2 - 1] = finalists[teamsChosen[i]].matchInFinals(finalists[teamsChosen[i + 1]]);
			std::cout << teamsInStage[i / 2 - 1].getName() << "has won and will compete in the next round" << std::endl;
		}
		numTeams /= 2;
		delete[] finalists;
		delete[] teamsChosen;
		finalStageSort();
	}

	Team Victor;
	Victor = teamsInStage[0].matchInFinals(teamsInStage[1]);
	std::cout << "Team " << Victor.getName() << "has emerged victorious!" << std::endl;
}