#pragma once
#include "Node_structure.h"

namespace structure_graf 
{
	class Node;
	class arc
	{
	private:
		std::shared_ptr<structure_graf::Node> nextNode;
		size_t weight;
	public:
		void setNext(std::shared_ptr<structure_graf::Node>&, size_t&);
		std::shared_ptr<structure_graf::Node> getNextNode();
		size_t getNextWeight();

		arc()
		{
			this->nextNode = nullptr;
			this->weight = 0;
		}
	};
}