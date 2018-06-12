#include "Group.h"

void Group::swapTeams(int index1, int index2)
{
	Team* tempTeam = new Team[numTeams];
	assert(tempTeam);
	for (int i = 0; i < numTeams; i++)
	{
		tempTeam[i] = teamsInGroup[i];
	}

	delete[] teamsInGroup;
	teamsInGroup = new Team[numTeams];
	assert(teamsInGroup);
	for (int i = 0; i < numTeams; i++)
	{
		if (i == index1) teamsInGroup[index1] = tempTeam[index2];
		else if (i == index2) teamsInGroup[index2] = tempTeam[index1];
		else teamsInGroup[i] = tempTeam[i];
	}

	delete[] tempTeam;
}

void Group::playMatch()
{
	int teamPoints[4] = { 0, 0, 0, 0 }; // stores information about the points each team within the group has
	int pointsDifference[4] = { 0, 0, 0, 0 }; // stores information about the differencePoints each team within the group has
	for (int i = 0; i < numTeams - 1; i++)
	{
		for (int j = i + 1; j < numTeams; j++)
		{
			if (numTeams == 3)
			{
				int gameTeam[3][3][2]; // first array stores teams, second array stores the rival team and the third array stores the rounds
				std::cout << teamsInGroup[i].getName() << " vs. " << teamsInGroup[j].getName();
				std::cout << "First game: "; std::cin >> gameTeam[i][j][0]; std::cout << " - "; std::cin >> gameTeam[j][i][0];
				teamPoints[i] += gameTeam[i][j][0]; teamPoints[j] += gameTeam[j][i][0];
				pointsDifference[i] += teamPoints[i] - teamPoints[j];
				pointsDifference[j] += teamPoints[j] - teamPoints[i];
				totalDifference = pointsDifference[i] + pointsDifference[j];
				std::cout << "Second game: "; std::cin >> gameTeam[i][j][1]; std::cout << " - "; std::cin >> gameTeam[j][i][1];
				teamPoints[i] += gameTeam[i][j][1]; teamPoints[j] += gameTeam[j][i][1];
				pointsDifference[i] += teamPoints[i] - teamPoints[j];
				pointsDifference[j] += teamPoints[j] - teamPoints[i];
				totalDifference = pointsDifference[i] + pointsDifference[j];
			}
			else
			{
				int gameTeam[4][4]; // similirat to the above, first array stores teams and second - rival teams
				std::cout << teamsInGroup[i].getName() << " vs. " << teamsInGroup[j].getName();
				std::cout << "First game: "; std::cin >> gameTeam[i][j]; std::cout << " - "; std::cin >> gameTeam[j][i];
				teamPoints[i] += gameTeam[i][j]; teamPoints[j] += gameTeam[j][i];
				pointsDifference[i] += teamPoints[i] - teamPoints[j];
				pointsDifference[j] += teamPoints[j] - teamPoints[i];
				totalDifference = pointsDifference[i] + pointsDifference[j];
			}
		}
	}

	for (int i = 0; i < numTeams; i++)
	{
		teamsInGroup[i].setDifferencePoints(pointsDifference[i]);
	}

	for (int i = 0; i < numTeams - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < numTeams; j++)
		{
			if (teamsInGroup[min].getDifferencePoints() < teamsInGroup[j].getDifferencePoints())
			{
				min = j;
				swapTeams(i, min);
			}
		}
	}
}

void Group::copyGroup(const Group& group)
{
	numTeams = group.numTeams;
	teamsInGroup = new Team[numTeams];
	assert(teamsInGroup);
	for (int i = 0; i < numTeams; i++)
	{
		teamsInGroup[i] = group.teamsInGroup[i];
	}
	totalDifference = group.totalDifference;
}

Group::Group(const Team* arrTeams, int num)
{
	numTeams = num;
	teamsInGroup = new Team[numTeams];
	assert(teamsInGroup);
	for (int i = 0; i < numTeams; i++)
	{
		teamsInGroup[i].setName(arrTeams[i].getName());
		teamsInGroup[i].setPoints(arrTeams[i].getPoints());
	}
	totalDifference = 0;
}

Group::Group(const Group& group)
{
	copyGroup(group);
}

Group& Group::operator=(const Group& group)
{
	if (this != &group)
	{
		delete[] teamsInGroup;
		copyGroup(group);
	}
	return *this;
}

Group::~Group()
{
	delete[] teamsInGroup;
}

void Group::setTeams(const Team* arrTeams, int num)
{
	if (teamsInGroup != NULL)
	{
		delete[] teamsInGroup;
	}
	numTeams = num;
	teamsInGroup = new Team[numTeams];
	assert(teamsInGroup);
	for (int i = 0; i < numTeams; i++)
	{
		teamsInGroup[i] = arrTeams[i];
	}
}

Team* Group::getTeams() const
{
	return teamsInGroup;
}

int Group::getDifference() const
{
	return totalDifference;
}

int Group::getNumTeams() const
{
	return numTeams;
}