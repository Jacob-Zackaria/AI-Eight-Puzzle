#include "SolveMethod.h"
#include<assert.h>
#include<iterator>
// User defined classes
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
#include "IterativeDeepening.h"
#include "UniformCostSearch.h"
#include "BestFirstSearch.h"
#include "AStar1.h"
#include "AStar2.h"
#include "AStar3.h"

int SolveMethod::GetInput()
{
	// get singleton instance
	SolveMethod* pSolveMethod = SolveMethod::privGetInstance();

	// input menu options.
	int option = 0;

	do {
		system("CLS");

		// display menu
		pSolveMethod->privMenu();

		RETURN_NOT_USED(scanf_s("%d", &option));

		if(option > 0 && option < 10)
		{
			break;
		}
		else
		{
			printf("\n\n WRONG INPUT\n");
			system("pause");
		}
	} while (1);

	return (option);
}

void SolveMethod::BreadthFirstSearch(int* a)
{
	// get singleton instance
	SolveMethod* pSolveMethod = SolveMethod::privGetInstance();

	// create root node.
	Node* startNode = new Node(a);

	// add to list 
	pSolveMethod->solutionList.push_back(startNode);


	BFS newC = {};
	bool success = newC.Solve(pSolveMethod->solutionList, pSolveMethod->totalCost, pSolveMethod->totalTime, pSolveMethod->totalSpace, pSolveMethod->goalState);
	if (!success)
	{
		printf("\n\n ALGORITHM EXCEEDED MAX TIME  5 Min!\n");
		system("pause");
	}
	else
	{
		pSolveMethod->PrintStatus();
	}
}

void SolveMethod::DepthFirstSearch(int* a)
{
	// get singleton instance
	SolveMethod* pSolveMethod = SolveMethod::privGetInstance();

	// create root node.
	Node* startNode = new Node(a);

	// add to list 
	pSolveMethod->solutionList.push_back(startNode);


	DFS newD = {};
	bool success = newD.Solve(pSolveMethod->solutionList, pSolveMethod->totalCost, pSolveMethod->totalTime, pSolveMethod->totalSpace, pSolveMethod->goalState);
	if (!success)
	{
		printf("\n\n ALGORITHM EXCEEDED MAX TIME  5 Min!\n");
		system("pause");
	}
	else
	{
		pSolveMethod->PrintStatus();
	}
	
}

void SolveMethod::IteartiveSearch(int* a)
{
	// get singleton instance
	SolveMethod* pSolveMethod = SolveMethod::privGetInstance();

	// create root node.
	Node* startNode = new Node(a);

	// add to list 
	pSolveMethod->solutionList.push_back(startNode);


	IDS newD = {};
	bool success = newD.Solve(pSolveMethod->solutionList, pSolveMethod->totalCost, pSolveMethod->totalTime, pSolveMethod->totalSpace, pSolveMethod->goalState);
	if (!success)
	{
		printf("\n\n ALGORITHM EXCEEDED MAX TIME  5 Min!\n");
		system("pause");
	}
	else
	{
		pSolveMethod->PrintStatus();
	}
}

void SolveMethod::UniformCostSearch(int* a)
{
	// get singleton instance
	SolveMethod* pSolveMethod = SolveMethod::privGetInstance();

	// create root node.
	Node* startNode = new Node(a);

	// add to list 
	pSolveMethod->solutionList.push_back(startNode);


	UCS newS = {};
	bool success = newS.Solve(pSolveMethod->solutionList, pSolveMethod->totalCost, pSolveMethod->totalTime, pSolveMethod->totalSpace, pSolveMethod->goalState);
	if (!success)
	{
		printf("\n\n ALGORITHM EXCEEDED MAX TIME  5 Min!\n");
		system("pause");
	}
	else
	{
		pSolveMethod->PrintStatus();
	}
}

void SolveMethod::BestFirstSearch(int* a)
{
	// get singleton instance
	SolveMethod* pSolveMethod = SolveMethod::privGetInstance();

	// create root node.
	Node* startNode = new Node(a);

	// add to list 
	pSolveMethod->solutionList.push_back(startNode);


	BestFS newS = {};
	bool success = newS.Solve(pSolveMethod->solutionList, pSolveMethod->totalCost, pSolveMethod->totalTime, pSolveMethod->totalSpace, pSolveMethod->goalState);
	if (!success)
	{
		printf("\n\n ALGORITHM EXCEEDED MAX TIME  5 Min!\n");
		system("pause");
	}
	else
	{
		pSolveMethod->PrintStatus();
	}
}

void SolveMethod::AStar1(int* a)
{
	// get singleton instance
	SolveMethod* pSolveMethod = SolveMethod::privGetInstance();

	// create root node.
	Node* startNode = new Node(a);

	// add to list 
	pSolveMethod->solutionList.push_back(startNode);


	A1Star newS = {};
	bool success = newS.Solve(pSolveMethod->solutionList, pSolveMethod->totalCost, pSolveMethod->totalTime, pSolveMethod->totalSpace, pSolveMethod->goalState);
	if (!success)
	{
		printf("\n\n ALGORITHM EXCEEDED MAX TIME  5 Min!\n");
		system("pause");
	}
	else
	{
		pSolveMethod->PrintStatus();
	}
}

void SolveMethod::AStar2(int* a)
{
	// get singleton instance
	SolveMethod* pSolveMethod = SolveMethod::privGetInstance();

	// create root node.
	Node* startNode = new Node(a);

	// add to list 
	pSolveMethod->solutionList.push_back(startNode);


	A2Star newS = {};
	bool success = newS.Solve(pSolveMethod->solutionList, pSolveMethod->totalCost, pSolveMethod->totalTime, pSolveMethod->totalSpace, pSolveMethod->goalState);
	if (!success)
	{
		printf("\n\n ALGORITHM EXCEEDED MAX TIME  5 Min!\n");
		system("pause");
	}
	else
	{
		pSolveMethod->PrintStatus();
	}
}

void SolveMethod::AStar3(int* a)
{
	// get singleton instance
	SolveMethod* pSolveMethod = SolveMethod::privGetInstance();

	// create root node.
	Node* startNode = new Node(a);

	// add to list 
	pSolveMethod->solutionList.push_back(startNode);


	A3Star newS = {};
	bool success = newS.Solve(pSolveMethod->solutionList, pSolveMethod->totalCost, pSolveMethod->totalTime, pSolveMethod->totalSpace, pSolveMethod->goalState);
	if (!success)
	{
		printf("\n\n ALGORITHM EXCEEDED MAX TIME  5 Min!\n");
		system("pause");
	}
	else
	{
		pSolveMethod->PrintStatus();
	}
}

void SolveMethod::PrintStatus()
{
	// get singleton instance
	SolveMethod* pSolveMethod = SolveMethod::privGetInstance();

	printf("\n\n SOLUTION PATH:\n");

	for (auto it = pSolveMethod->solutionList.begin(); it != pSolveMethod->solutionList.end(); it++)
	{
		Node* newNode = *it;
		printf("\nACTION:%s", newNode->GetNodeData()->GetOperationString());
		newNode->PrintCurrentState();
	}

	printf("\n Path Length:%zd", pSolveMethod->solutionList.size());
	printf("\n Total Cost:%d", pSolveMethod->totalCost);
	printf("\n Time:%u", pSolveMethod->totalTime);
	printf("\n Space:%u \n\n", pSolveMethod->totalSpace);

	system("pause");
}

void SolveMethod::privMenu()
{
	printf("\t\t SOLVE METHODS\n");
	printf("\n 1) Breadth First Search");
	printf("\n 2) Depth First Search");
	printf("\n 3) Iterative Deepening");
	printf("\n 4) Uniform Cost Search");
	printf("\n 5) Best First Search");
	printf("\n 6) A* 1");
	printf("\n 7) A* 2");
	printf("\n 8) A* 3");
	printf("\n 9) MAIN MENU");
	printf("\n\n >> ");
}




void SolveMethod::setGoalState()
{
	this->goalState[0] = 1;
	this->goalState[1] = 2;
	this->goalState[2] = 3;
	this->goalState[3] = 8;
	this->goalState[4] = 0;
	this->goalState[5] = 4;
	this->goalState[6] = 7;
	this->goalState[7] = 6;
	this->goalState[8] = 5;
}


SolveMethod* SolveMethod::privGetInstance()
{
	static SolveMethod instance = {};
	return (&instance);
}

SolveMethod::SolveMethod()
	:
	solutionList{},
	totalTime(0),
	totalSpace(0),
	totalCost(0),
	goalState{0}
{
	this->setGoalState();
}