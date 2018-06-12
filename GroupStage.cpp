#include "GroupStage.h"

void GroupStage::copyGroupStage(const GroupStage& groupStage)
{
	numGroups = groupStage.numGroups;
	groupsInStage = new Group[numGroups];
	assert(groupsInStage);
	for (int i = 0; i < numGroups; i++)
	{
		groupsInStage[i] = groupStage.groupsInStage[i];
	}
}

GroupStage::GroupStage(const Group* group, int num)
{
	numGroups = num;
	groupsInStage = new Group[numGroups];
	assert(groupsInStage);
	for (int i = 0; i < numGroups; i++)
	{
		groupsInStage[i].setTeams(group[i].getTeams(), numGroups);
	}
}

GroupStage::GroupStage(const GroupStage& groupStage)
{
	copyGroupStage(groupStage);
}

GroupStage& GroupStage::operator=(const GroupStage& groupStage)
{
	if (this != &groupStage)
	{
		delete[] groupsInStage;
		copyGroupStage(groupStage);
	}
	return *this;
}

GroupStage::~GroupStage()
{
	delete[] groupsInStage;
}

int GroupStage::getNumGroups() const
{
	return numGroups;
}

Group* GroupStage::getGroupsInStage() const
{
	return groupsInStage;
}

void GroupStage::swapGroups(int index1, int index2)
{
	Group* tempGroup = new Group[numGroups];
	assert(tempGroup);
	for (int i = 0; i < numGroups; i++)
	{
		tempGroup[i] = groupsInStage[i];
	}

	delete[] groupsInStage;
	groupsInStage = new Group[numGroups];
	assert(groupsInStage);
	for (int i = 0; i < numGroups; i++)
	{
		if (i == index1) groupsInStage[i] = tempGroup[index2];
		else if (i == index2) groupsInStage[i] = tempGroup[index1];
		else groupsInStage[i] = tempGroup[i];
	}

	delete[] tempGroup;
}

void GroupStage::GroupStageSort()
{
	for (int i = 0; i < numGroups; i++)
	{
		groupsInStage[i].playMatch();
	}

	for (int i = 0; i < numGroups - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < numGroups; j++)
		{
			if (groupsInStage[i].getDifference() < groupsInStage[j].getDifference())
			{
				min = j;
				swapGroups(i, min);
			}
		}
	}
}

Team** GroupStage::getRankedTeams() const
{
	Team** rankedTeams = new Team*[numGroups];
	assert(rankedTeams);
	for (int i = 0; i < numGroups; i++)
	{
		int teamsInGroup = groupsInStage[i].getNumTeams();
		rankedTeams[i] = new Team[teamsInGroup];
		assert(rankedTeams[i]);
		rankedTeams[i] = groupsInStage[i].getTeams();
	}

	return rankedTeams;

	for (int i = 0; i < numGroups; i++)
	{
		delete[] rankedTeams[i];
	}
	delete[] rankedTeams;
}