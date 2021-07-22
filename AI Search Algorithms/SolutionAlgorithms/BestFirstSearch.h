#ifndef BEST_FIRST_SEACRH_H
#define BEST_FIRST_SEACRH_H

#include "SolutionAlgorithm.h"


class BestFS : public SolutionAlgorithm
{
	struct Comp
	{
		Comp(int* newGoalState)
		{
			this->goalState = newGoalState;
		}

		// compare based on total cost and path cost.
		bool operator() (const Node* a, const Node* b)
		{
			return
				(
					this->NumberOfTilesMisplaced(a->GetCurrentState())
				<
					this->NumberOfTilesMisplaced(b->GetCurrentState())
				);
		}
	private:
		int NumberOfTilesMisplaced(int* a)
		{
			int count = 0;

			for (int i = 0; i < 9; i++)
			{
				if (a[i] != goalState[i])
				{
					count++;
				}
			}

			return (count);
		}

		int* goalState;
	};
public:
	//-------> Big Six oeprators <---------//

	// default constructor.
	BestFS();
	// copy assignment constructor.
	BestFS(const BestFS&) = delete;
	// assignment operator.
	const BestFS& operator = (const BestFS&) = delete;
	// move assignment constructor.
	BestFS(const BestFS&&) = delete;
	// move assignment operator.
	const BestFS&& operator = (const BestFS&&) = delete;
	// destructor.
	virtual ~BestFS();

	//---------------------------------------//

	// public virtual function
	virtual bool Solve(std::deque<Node*>& solutionList, int& totalCost, unsigned int& totalTime, unsigned int& totalSpace, int* goalState) override;

private:

	Comp comparator;
};

#endif BEST_FIRST_SEACRH_H