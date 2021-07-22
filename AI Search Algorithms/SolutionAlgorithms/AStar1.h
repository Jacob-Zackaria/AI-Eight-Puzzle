#ifndef A_STAR_1_H
#define A_STAR_1_H

#include "SolutionAlgorithm.h"


class A1Star : public SolutionAlgorithm
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
					(
						a->GetNodeData()->GetTotalCost() +
						this->NumberOfTilesMisplaced(a->GetCurrentState())
					)
				<
					(
						b->GetNodeData()->GetTotalCost() +
						this->NumberOfTilesMisplaced(b->GetCurrentState())
					)
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
	A1Star();
	// copy assignment constructor.
	A1Star(const A1Star&) = delete;
	// assignment operator.
	const A1Star& operator = (const A1Star&) = delete;
	// move assignment constructor.
	A1Star(const A1Star&&) = delete;
	// move assignment operator.
	const A1Star&& operator = (const A1Star&&) = delete;
	// destructor.
	virtual ~A1Star();

	//---------------------------------------//

	// public virtual function
	virtual bool Solve(std::deque<Node*>& solutionList, int& totalCost, unsigned int& totalTime, unsigned int& totalSpace, int* goalState) override;

private:
	Comp comparator;
};

#endif A_STAR_1_H