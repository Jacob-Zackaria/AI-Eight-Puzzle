#include "SolutionAlgorithm.h"

SolutionAlgorithm::~SolutionAlgorithm()
{
}

bool SolutionAlgorithm::CheckGoal(int* currentState, int* goalState)
{
	bool status = true;

	for (int i = 0; i < 9; i++)
	{
		if (currentState[i] != goalState[i])
		{
			status = false;
			break;
		}
	}

	return (status);
}

bool SolutionAlgorithm::FindInQueue(std::deque<Node*>& currentQueue, int* goalState)
{
	for (auto it = currentQueue.begin(); it != currentQueue.end(); it++)
	{
		Node* newNode = *it;
		if (this->CheckGoal(newNode->GetCurrentState(), goalState))
		{
			return true;
		}
	}

	return false;
}

bool SolutionAlgorithm::FindInVisited(int* goalState)
{
	for (auto it = this->visitedList.begin(); it != this->visitedList.end(); it++)
	{
		Node* newNode = *it;
		if (this->CheckGoal(newNode->GetCurrentState(), goalState))
		{
			return true;
		}
	}

	return false;
}
