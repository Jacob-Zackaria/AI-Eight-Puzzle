#ifndef SOLUTION_ALGORITHM_H
#define SOLUTION_ALGORITHM_H

#include <chrono>
#include "Node.h"

class SolutionAlgorithm
{
#define MAX_ALGORITHM_TIME 300000   // (5 * 60 * 1000)
public:
	//-------> Big Six oeprators <---------//

	// default constructor.
	SolutionAlgorithm() = default;
	// copy assignment constructor.
	SolutionAlgorithm(const SolutionAlgorithm&) = delete;
	// assignment operator.
	const SolutionAlgorithm& operator = (const SolutionAlgorithm&) = delete;
	// move assignment constructor.
	SolutionAlgorithm(const SolutionAlgorithm&&) = delete;
	// move assignment operator.
	const SolutionAlgorithm&& operator = (const SolutionAlgorithm&&) = delete;
	// destructor.
	virtual ~SolutionAlgorithm();

	//---------------------------------------//

	// checks if goal state is reached.
	bool CheckGoal(int* currentState, int* goalState);

	// find if given state exist in current queue
	bool FindInQueue(std::deque<Node*>& currentQueue, int* goalState);

	// find if given state exist in visited list
	bool FindInVisited(int* goalState);

	// virtual function for inherited solution algorithms.
	virtual bool Solve(std::deque<Node*>& solutionList, int& totalCost, unsigned int& totalTime, unsigned int& totalSpace, int* goalState) = 0;

	// visisted List for solution algorithms.
	std::vector<Node*> visitedList;
};


#endif SOLUTION_ALGORITHM_H