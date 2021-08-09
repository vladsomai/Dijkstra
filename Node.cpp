#include "Node_structure.h"

namespace structure_graf
{
	int Node::getData()
	{
		return this->data;
	}

	void Node::setData(int newData)
	{
		this->data = newData;
	}

	void Node::setNextArc(std::shared_ptr<arc>NextParam)
	{
		this->next.push_back(NextParam);
	}

	std::list<std::shared_ptr<arc>> Node::getNextArc()
	{
		return this->next;
	}

	void Node::clearNextList()
	{
		this->next.clear();
	}

	void Node::setNextList(std::list<std::shared_ptr<arc> >& ListParam)
	{
		this->next = ListParam;
	}

	std::list<std::shared_ptr<arc>> Node::DeleteNodeInList(std::shared_ptr<Node> deleteNode, std::list<std::shared_ptr<arc>>& li)
	{
		for (auto iterator = li.begin(); iterator != li.end(); ++iterator)
		{
			if (iterator->get()->getNextNode() == deleteNode)
			{
				li.erase(iterator);
				return li;
			}
		}
		return li;
	}
}
