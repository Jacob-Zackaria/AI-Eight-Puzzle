#ifndef UNIFORM_COST_SEACRH_H
#define UNIFORM_COST_SEACRH_H

#include "SolutionAlgorithm.h"


class UCS : public SolutionAlgorithm
{
	struct Comp
	{
		// compare based on total cost and path cost.
		bool operator() (const Node* a, const Node* b) const
		{
			return 
				(
					(
						a->GetNodeData()->GetPathCost() +
						a->GetNodeData()->GetTotalCost()
					)
				<
					(
						b->GetNodeData()->GetPathCost() +
						b->GetNodeData()->GetTotalCost()
					)
				);
		}
	};

public:
	//-------> Big Six oeprators <---------//

	// default constructor.
	UCS();
	// copy assignment constructor.
	UCS(const UCS&) = delete;
	// assignment operator.
	const UCS& operator = (const UCS&) = delete;
	// move assignment constructor.
	UCS(const UCS&&) = delete;
	// move assignment operator.
	const UCS&& operator = (const UCS&&) = delete;
	// destructor.
	virtual ~UCS();

	//---------------------------------------//

	// public virtual function
	virtual bool Solve(std::deque<Node*>& solutionList, int& totalCost, unsigned int& totalTime, unsigned int& totalSpace, int* goalState) override;

private:

	Comp comparator;
};

#endif UNIFORM_COST_SEACRH_H