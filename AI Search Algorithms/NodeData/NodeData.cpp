#include "NodeData.h"

NodeData::NodeData()
	:
	currentOperation(OPERATIONS::NO_MOVE),
	depth(0),
	path_cost(0),
	total_cost(0),
	is_Expanded(false)
{
}

NodeData::NodeData(NodeData::OPERATIONS newOp, unsigned int newDepth, unsigned int newPCost, bool expanded)
	:
	currentOperation(newOp),
	depth(newDepth),
	path_cost(newPCost),
	total_cost(0),
	is_Expanded(expanded)
{
}

const NodeData::OPERATIONS NodeData::GetOperation() const
{
	return this->currentOperation;
}

const char* NodeData::GetOperationString() const
{
	switch (this->currentOperation)
	{
	case OPERATIONS::MOVE_UP: return ("MOVE_UP");
	case OPERATIONS::MOVE_DOWN: return ("MOVE_DOWN");
	case OPERATIONS::MOVE_LEFT: return ("MOVE_LEFT");
	case OPERATIONS::MOVE_RIGHT: return ("MOVE_RIGHT");
	default: return ("NO MOVE");
	}
}

const bool NodeData::GetExpanded() const
{
	return this->is_Expanded;
}

void NodeData::SetExpanded(const bool nExp)
{
	this->is_Expanded = nExp;
}

const unsigned int NodeData::GetDepth() const
{
	return this->depth;
}

const unsigned int NodeData::GetPathCost() const
{
	return this->path_cost;
}

const unsigned int NodeData::GetTotalCost() const
{
	return this->total_cost;
}

void NodeData::SetTotalCost(const unsigned int newCost)
{
	this->total_cost = newCost;
}
