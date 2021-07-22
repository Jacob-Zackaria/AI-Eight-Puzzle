#ifndef SOLVE_METHOD_H
#define SOLVE_METHOD_H

// standard libraries
#include<stdlib.h>
#include<stdio.h>

//// user defined classes
#include "Node.h"

// unused variables
#define RETURN_NOT_USED(x) (void(x))

class SolveMethod final
{
	

public:
	//-------> Big five oeprators <---------//
	
	// copy assignment constructor.
	SolveMethod(const SolveMethod&) = delete;
	// assignment operator.
	const SolveMethod& operator = (const SolveMethod&) = delete;
	// move assignment constructor.
	SolveMethod(const SolveMethod&&) = delete;
	// move assignment operator.
	const SolveMethod&& operator = (const SolveMethod&&) = delete;
	// destructor.
	~SolveMethod() = default;

	//---------------------------------------//

	//------> Public member functions <------//

	// Get solving method input.
	static int GetInput();

	// Solve using BFS.
	static void BreadthFirstSearch(int* a);
	// Solve using DFS.
	static void DepthFirstSearch(int* a);
	// Solve using IDS.
	static void IteartiveSearch(int* a);
	// Solve using UCS.
	static void UniformCostSearch(int* a);
	// Solve using BestFS.
	static void BestFirstSearch(int* a);
	// Solve using A* 1 (h = number of tiles not in correct portion).
	static void AStar1(int* a);
	// Solve using A* 2 (h = sum of mahatten distances between all tiles and correct position).
	static void AStar2(int* a);
	// Solve using A* 3 (h = sum of mahatten distances and number of tiles misplaced).
	static void AStar3(int* a);

	// Print solution
	static void PrintStatus();

	//---------------------------------------//

private:

	//------> Private member functions <------//
	
	// display solve method menu
	void privMenu();

	void setGoalState();

	//---------------------------------------//
	
	//--------> Singleton functions <--------//
	
	// deafult constructor.
	SolveMethod();

	// singleton class instance.
	static SolveMethod* privGetInstance();

	//---------------------------------------//

	//----------------> Data <---------------//
	
	// list of solution nodes.
	std::deque<Node*> solutionList;

	// total time
	unsigned int totalTime;

	// total space
	unsigned int totalSpace;

	// total cost
	int totalCost;

	// goal state.
	int goalState[9];

	//---------------------------------------//

};


#endif SOLVE_METHOD_H
