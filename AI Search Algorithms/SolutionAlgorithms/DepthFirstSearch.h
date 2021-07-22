#ifndef DEPTH_FIRST_SEACRH_H
#define DEPTH_FIRST_SEACRH_H

#include "SolutionAlgorithm.h"


class DFS : public SolutionAlgorithm
{
public:
	//-------> Big Six oeprators <---------//

	// default constructor.
	DFS();
	// copy assignment constructor.
	DFS(const DFS&) = delete;
	// assignment operator.
	const DFS& operator = (const DFS&) = delete;
	// move assignment constructor.
	DFS(const DFS&&) = delete;
	// move assignment operator.
	const DFS&& operator = (const DFS&&) = delete;
	// destructor.
	virtual ~DFS();

	//---------------------------------------//

	// public virtual function
	virtual bool Solve(std::deque<Node*>& solutionList, int& totalCost, unsigned int& totalTime, unsigned int& totalSpace, int* goalState) override;

};

#endif DEPTH_FIRST_SEACRH_H