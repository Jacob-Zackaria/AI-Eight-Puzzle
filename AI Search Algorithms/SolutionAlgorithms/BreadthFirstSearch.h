#ifndef BREADTH_FIRST_SEACRH_H
#define BREADTH_FIRST_SEACRH_H

#include "SolutionAlgorithm.h"


class BFS: public SolutionAlgorithm
{
public:
	//-------> Big Six oeprators <---------//

	// default constructor.
	BFS();
	// copy assignment constructor.
	BFS(const BFS&) = delete;
	// assignment operator.
	const BFS& operator = (const BFS&) = delete;
	// move assignment constructor.
	BFS(const BFS&&) = delete;
	// move assignment operator.
	const BFS&& operator = (const BFS&&) = delete;
	// destructor.
	virtual ~BFS();

	//---------------------------------------//

	// public virtual function
	virtual bool Solve(std::deque<Node*>& solutionList, int& totalCost, unsigned int& totalTime, unsigned int& totalSpace, int* goalState) override;

	
};

#endif BREADTH_FIRST_SEACRH_H