#include "Team.h"

Team& Team::matchInFinals(Team& other)
{
	int counterWinsFirst = 0;
	int counterWinsSecond = 0;
	int pointsOfTeams[2][3]; //2 teams play up to 3 rounds
							 //first array stores teams, second array stores rounds
	std::cout << getName() << " vs. " << other.getName();
	for (int i = 0; i < 2; i++)
	{
		std::cout << i + 1 << "-st game: "; std::cin >> pointsOfTeams[0][0]; std::cout << " - "; std::cin >> pointsOfTeams[1][0];
		pointsTeam += pointsOfTeams[0][i];
		other.setPoints(other.getPoints() + pointsOfTeams[1][i]);
		if (pointsTeam > other.getPoints()) counterWinsFirst++;
		else counterWinsSecond++;
	}
	if (counterWinsFirst == counterWinsSecond)
	{
		std::cout << "Final game: "; std::cin >> pointsOfTeams[0][2]; std::cout << " - "; std::cin >> pointsOfTeams[1][2];
		pointsTeam += pointsOfTeams[0][2];
		other.setPoints(other.getPoints() + pointsOfTeams[1][2]);
		if (pointsTeam > other.getPoints()) counterWinsFirst++;
		else counterWinsSecond++;
	}
	if (counterWinsFirst > counterWinsSecond) return *this;
	else if (counterWinsFirst < counterWinsSecond) return other;
}

void Team::copyTeam(const Team& team)
{
	nameTeam = new char[strlen(team.nameTeam) + 1];
	assert(nameTeam);
	strcpy(nameTeam, team.nameTeam);
	pointsTeam = team.pointsTeam;
	differencePoints = team.differencePoints;
}

Team::Team(const char* name, int points)
{
	nameTeam = new char[strlen(name) + 1];
	assert(nameTeam);
	strcpy(nameTeam, name);
	pointsTeam = points;
	differencePoints = 0;
}

Team::Team(const Team& team)
{
	copyTeam(team);
}

Team& Team::operator=(const Team& team)
{
	if (this != &team)
	{
		delete[] nameTeam;
		copyTeam(team);
	}
	return *this;
}

Team::~Team()
{
	delete[] nameTeam;
}

const char* Team::getName() const
{
	return nameTeam;
}

int Team::getPoints() const
{
	return pointsTeam;
}

int Team::getDifferencePoints() const
{
	return differencePoints;
}

void Team::setDifferencePoints(int points)
{
	differencePoints = points;
}

void Team::setName(const char* name)
{
	delete[] nameTeam;
	nameTeam = new char[strlen(name) + 1];
	assert(nameTeam);
	strcpy(nameTeam, name);
}

void Team::setPoints(int points)
{
	pointsTeam = points;
}