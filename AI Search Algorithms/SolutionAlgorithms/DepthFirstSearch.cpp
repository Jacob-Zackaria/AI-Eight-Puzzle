#include "DepthFirstSearch.h"

DFS::DFS()
{
}

DFS::~DFS()
{
}

bool DFS::Solve(std::deque<Node*>& solutionList, int& totalCost, unsigned int& totalTime, unsigned int& totalSpace, int* goalState)
{
	// clear visited list
	visitedList.clear();

	// set time to 0
	totalTime = 0; totalSpace = 0;

	// create queue.
	std::deque<Node*> currentQueue = {};

	// add root node to queue from currentList
	currentQueue.push_back(solutionList.back());

	// remove root from current List
	solutionList.pop_back();

	// get current time
	auto startTime = std::chrono::steady_clock::now();

	// check if current list is empty.
	while (!currentQueue.empty())
	{
		// get current time
		auto timePoint = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::milliseconds>(timePoint - startTime).count() > MAX_ALGORITHM_TIME)
		{
			// unsuccessfull
			return (false);
		}

		// get last node.
		Node* removedNode = currentQueue.back();

		// remove last node from queue
		currentQueue.pop_back();

		// update time
		totalTime++;

		// add to visited list
		this->visitedList.push_back(removedNode);

		// check if it is goal state.
		if (this->CheckGoal(removedNode->GetCurrentState(), goalState))
		{
			// get total cost from current node.
			totalCost = removedNode->GetNodeData()->GetTotalCost();

			// track route from root node to current node.
			solutionList = removedNode->TrackRoute();

			// successfull
			return (true);
		}

		// Generate children nodes.
		removedNode->GenerateChildren();

		// get child list
		unsigned int index = 0;
		Node* childNode = removedNode->GetChild(index);

		while (childNode != nullptr)
		{
			// add total cost
			childNode->GetNodeData()->SetTotalCost(removedNode->GetNodeData()->GetTotalCost() + childNode->GetNodeData()->GetPathCost());

			// check if child exist in the queue.
			if (!this->FindInQueue(currentQueue, childNode->GetCurrentState()))
			{
				// check if child exist in visted list.
				if (!this->FindInVisited(childNode->GetCurrentState()))
				{
					// if not add to queue
					currentQueue.push_back(childNode);
				}
				else
				{
					delete childNode;
				}
			}

			index++;
			childNode = removedNode->GetChild(index);
		}

		// check the size
		if (currentQueue.size() > totalSpace)
		{
			totalSpace = (unsigned int)currentQueue.size();
		}
	}

	// unsuccessfull
	return (false);
}

