#pragma once
#include"Arc.h"

namespace structure_graf
{
	using std::shared_ptr;
	class currentLowestPath
	{
	private:
		shared_ptr<Node> source;
		shared_ptr<Node> target;
		size_t weight;

	public:
		void setSource(shared_ptr<Node>&);
		void setTarget(shared_ptr<Node>&);
		void setWeight(size_t);

		shared_ptr<Node> getSource();
		shared_ptr<Node> getTarget();
		size_t getWeight();

		currentLowestPath()
		{
			this->source = nullptr;
			this->target = nullptr;
			weight = SIZE_MAX;
		}
	};
}
