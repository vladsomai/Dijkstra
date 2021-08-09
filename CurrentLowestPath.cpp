#include "CurrentLowestPath.h"

namespace structure_graf
{
	void currentLowestPath::setSource(shared_ptr<Node>& sourceParam) { this->source = sourceParam; }
	void currentLowestPath::setTarget(shared_ptr<Node>& targetParam) { this->target = targetParam; }
	void currentLowestPath::setWeight(size_t weightParam) { this->weight = weightParam; }

	shared_ptr<Node> currentLowestPath::getSource() { return this->source; }
	shared_ptr<Node> currentLowestPath::getTarget() { return this->target; }
	size_t currentLowestPath::getWeight() { return this->weight; }
}
