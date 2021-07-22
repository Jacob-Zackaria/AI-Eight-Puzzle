#ifndef A_STAR_3_H
#define A_STAR_3_H

#include "SolutionAlgorithm.h"


class A3Star : public SolutionAlgorithm
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
						this->NumberOfTilesMisplaced(a->GetCurrentState()) +
						this->SumManhattanDistance(a->GetCurrentState())
						)
					<
					(
						this->NumberOfTilesMisplaced(b->GetCurrentState()) +
						this->SumManhattanDistance(b->GetCurrentState())
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

		int SumManhattanDistance(int* a)
		{
			int sum = 0, n = 0;

			for (int i = 0; i < 9; i++)
			{
				if (a[i] != goalState[i])
				{
					for (int j = 0; j < 9; j++)
					{
						if (a[i] == goalState[j])
						{
							n = abs(j - i);
							while (n > 2)
							{
								n = n - 3;
								sum++;
							}
							sum += n;
							break;
						}
					}
				}
			}

			return (sum);
		}

		int* goalState;
	};
public:
	//-------> Big Six oeprators <---------//

	// default constructor.
	A3Star();
	// copy assignment constructor.
	A3Star(const A3Star&) = delete;
	// assignment operator.
	const A3Star& operator = (const A3Star&) = delete;
	// move assignment constructor.
	A3Star(const A3Star&&) = delete;
	// move assignment operator.
	const A3Star&& operator = (const A3Star&&) = delete;
	// destructor.
	virtual ~A3Star();

	//---------------------------------------//

	// public virtual function
	virtual bool Solve(std::deque<Node*>& solutionList, int& totalCost, unsigned int& totalTime, unsigned int& totalSpace, int* goalState) override;

private:
	Comp comparator;
};

#endif A_STAR_2_H