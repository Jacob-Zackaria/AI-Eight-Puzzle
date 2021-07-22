#ifndef NODE_H
#define NODE_H

// standard template library.
#include<vector>
#include<queue>

// user defined class
#include "NodeData.h"

class Node
{
	

public:
	//-------> Big Six oeprators <---------//

	// default constructor.
	Node(int* a);
	// special constructor.
	Node(int* a, Node* parentNode, NodeData* newData);
	// copy assignment constructor.
	Node(const Node&) = delete;
	// assignment operator.
	const Node& operator = (const Node&) = delete;
	// move assignment constructor.
	Node(const Node&&) = delete;
	// move assignment operator.
	const Node&& operator = (const Node&&) = delete;
	// destructor.
	~Node();

	//---------------------------------------//

	//-----> Public member functions <-------//

	int* GetCurrentState() const;
	void SetCurrentState(int* a);
	void PrintCurrentState();
	
	Node* GetChild(unsigned int index) const;
	NodeData* GetNodeData() const;
	Node* GetParent() const;

	// generate children for current node
	void GenerateChildren();

	// track from root
	std::deque<Node*> TrackRoute();

	//--------------------------------------//

private:

	//-----> Private member functions <-------//
	
	void MoveUp(int* changeState, const int blankTileLocation);
	void MoveDown(int* changeState, const int blankTileLocation);
	void MoveLeft(int* changeState, const int blankTileLocation);
	void MoveRight(int* changeState, const int blankTileLocation);
	void ChangeState(int* changeState, int indexFrom, int indexTo);
	int FindBlankTile();

	//--------------------------------------//
	
	//----------------> Data <---------------//

	// parent link.
	Node* pParent;

	// child links.
	std::vector<Node*> pChild;

	// current state
	int currentState[9];

	// data of node
	NodeData* pData;

	//---------------------------------------//
};



#endif NODE_H
