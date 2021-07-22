#include "Node.h"

Node::Node(int* a)
	:
	pParent(nullptr),
	pChild{},
	currentState{0},
	pData(new NodeData())
{
	this->SetCurrentState(a);
}

Node::Node(int* a, Node* parentNode, NodeData* newData)
	:
	pParent(parentNode),
	pChild{},
	currentState{ 0 },
	pData(newData)
{
	this->SetCurrentState(a);
}

Node::~Node()
{
	delete this->pData;
}



int* Node::GetCurrentState() const
{
	return (int*)this->currentState;
}

void Node::SetCurrentState(int* a)
{
	int i = 0;
	while (i < 9)
	{
		this->currentState[i] = a[i];
		i++;
	}
}

void Node::PrintCurrentState()
{
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
		{
			printf("\n");
		}
		printf("\t%d", this->currentState[i]);
	}
	printf("\n");
}

void Node::GenerateChildren()
{
	int changeState[9] = {};
	this->pData->SetExpanded(true);

	int blankTileLocation = FindBlankTile();

	// move up
	this->MoveUp(changeState, blankTileLocation);

	// move down
	this->MoveDown(changeState, blankTileLocation);

	// move left
	this->MoveLeft(changeState, blankTileLocation);

	// move right
	this->MoveRight(changeState, blankTileLocation);

}

Node* Node::GetChild(unsigned int index) const
{
	if (index > (this->pChild.size() - 1))
	{
		return nullptr;
	}
	else
	{
		return this->pChild.at(index);
	}
}



NodeData* Node::GetNodeData() const
{
	return this->pData;
}

Node* Node::GetParent() const
{
	return this->pParent;
}

std::deque<Node*> Node::TrackRoute()
{
	std::deque<Node*> trackRoute;

	Node* pTmp = this;
	trackRoute.push_front(pTmp);

	pTmp = pTmp->GetParent();
	while (pTmp != nullptr)
	{
		trackRoute.push_front(pTmp);
		pTmp = pTmp->GetParent();
	}

	return trackRoute;
}

void Node::MoveUp(int* changeState, const int blankTileLocation)
{
	// check move up
	if ((this->pData->GetOperation() != NodeData::OPERATIONS::MOVE_UP) && (blankTileLocation > 2))
	{
		NodeData* newNodeData = new NodeData(NodeData::OPERATIONS::MOVE_UP, this->pData->GetDepth() + 1, this->currentState[blankTileLocation - 3], false);
		this->ChangeState(changeState, blankTileLocation, (blankTileLocation - 3));
		Node* newChild = new Node(changeState, this, newNodeData);
		this->pChild.push_back(newChild);
	}
}

void Node::MoveDown(int* changeState, const int blankTileLocation)
{
	// check move down
	if ((this->pData->GetOperation() != NodeData::OPERATIONS::MOVE_DOWN) && (blankTileLocation < 6))
	{
		NodeData* newNodeData = new NodeData(NodeData::OPERATIONS::MOVE_DOWN, this->pData->GetDepth() + 1, this->currentState[blankTileLocation + 3], false);
		this->ChangeState(changeState, blankTileLocation, (blankTileLocation + 3));
		Node* newChild = new Node(changeState, this, newNodeData);
		this->pChild.push_back(newChild);
	}
}

void Node::MoveLeft(int* changeState, const int blankTileLocation)
{
	// check move left
	if ((this->pData->GetOperation() != NodeData::OPERATIONS::MOVE_LEFT) && ((blankTileLocation % 3) != 0))
	{
		NodeData* newNodeData = new NodeData(NodeData::OPERATIONS::MOVE_LEFT, this->pData->GetDepth() + 1, this->currentState[blankTileLocation - 1], false);
		this->ChangeState(changeState, blankTileLocation, (blankTileLocation - 1));
		Node* newChild = new Node(changeState, this, newNodeData);
		this->pChild.push_back(newChild);
	}
}

void Node::MoveRight(int* changeState, const int blankTileLocation)
{
	// check  move right
	if ((this->pData->GetOperation() != NodeData::OPERATIONS::MOVE_RIGHT) && (((blankTileLocation + 1) % 3) != 0))
	{
		NodeData* newNodeData = new NodeData(NodeData::OPERATIONS::MOVE_RIGHT, this->pData->GetDepth() + 1, this->currentState[blankTileLocation + 1], false);
		this->ChangeState(changeState, blankTileLocation, (blankTileLocation + 1));
		Node* newChild = new Node(changeState, this, newNodeData);
		this->pChild.push_back(newChild);
	}
}

void Node::ChangeState(int* changeState, int indexFrom, int indexTo)
{
	// copy all data
	for (int i = 0; i < 9; i++)
	{
		changeState[i] = this->currentState[i];
	}

	// change positions
	int temp = changeState[indexFrom];
	changeState[indexFrom] = changeState[indexTo];
	changeState[indexTo] = temp;
}

int Node::FindBlankTile()
{
	for (int i = 0; i < 9; i++)
	{
		if (this->currentState[i] == 0)
		{
			return (i);
		}
	}

	return (0);
}
