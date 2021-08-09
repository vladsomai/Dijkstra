
#include "Arc.h"

namespace structure_graf
{
	void arc::setNext(std::shared_ptr<structure_graf::Node>& nextNodeParam, size_t& weightParam)
	{
		this->nextNode = nextNodeParam;
		this->weight = weightParam;
	}

	std::shared_ptr<structure_graf::Node> arc::getNextNode()
	{
		return this->nextNode;
	}

	size_t arc::getNextWeight()
	{
		return this->weight;
	}
}
