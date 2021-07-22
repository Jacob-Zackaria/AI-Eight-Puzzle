#ifndef NODE_DATA_H
#define NODE_DATA_H

class NodeData
{
public:
	enum class OPERATIONS
	{
		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT,
		MOVE_RIGHT,
		NO_MOVE
	};

	//-------> Big Six oeprators <---------//

	// default constructor.
	NodeData();
	// default constructor.
	NodeData(NodeData::OPERATIONS newOp, unsigned int newDepth, unsigned int newPCost, bool expanded);
	// copy assignment constructor.
	NodeData(const NodeData&) = delete;
	// assignment operator.
	const NodeData& operator = (const NodeData&) = delete;
	// move assignment constructor.
	NodeData(const NodeData&&) = delete;
	// move assignment operator.
	const NodeData&& operator = (const NodeData&&) = delete;
	// destructor.
	~NodeData() = default;

	//---------------------------------------//

	//-----> Public member functions <-------//

	const NodeData::OPERATIONS GetOperation() const;
	const char* GetOperationString() const;
	const bool GetExpanded() const;
	void SetExpanded(const bool nExp);
	const unsigned int GetDepth() const;
	const unsigned int GetPathCost() const;
	const unsigned int GetTotalCost() const;
	void SetTotalCost(const unsigned int newCost);

	//---------------------------------------//

private:

	//----------------> Data <---------------//
	
	// current action.
	OPERATIONS currentOperation;

	// length of path from root to node.
	unsigned int depth;

	// cost of path.
	unsigned int path_cost;

	// total cost of path from root.
	unsigned int total_cost;

	// is node expanded.
	bool is_Expanded;

	//---------------------------------------//
};

#endif NODE_DATA_H