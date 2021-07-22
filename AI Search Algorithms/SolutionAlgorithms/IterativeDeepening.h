#ifndef ITERATIVE_SEACRH_H
#define ITERATIVE_SEACRH_H

#include "SolutionAlgorithm.h"


class IDS : public SolutionAlgorithm
{
public:
	//-------> Big Six oeprators <---------//

	// default constructor.
	IDS();
	// copy assignment constructor.
	IDS(const IDS&) = delete;
	// assignment operator.
	const IDS& operator = (const IDS&) = delete;
	// move assignment constructor.
	IDS(const IDS&&) = delete;
	// move assignment operator.
	const IDS&& operator = (const IDS&&) = delete;
	// destructor.
	virtual ~IDS();

	//---------------------------------------//

	// public virtual function
	virtual bool Solve(std::deque<Node*>& solutionList, int& totalCost, unsigned int& totalTime, unsigned int& totalSpace, int* goalState) override;

};

#endif ITERATIVE_SEACRH_H