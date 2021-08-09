#include <queue>
#include "CurrentLowestPath.h"

namespace structure_graf
{
	using std::list;
	using std::shared_ptr;
	using std::queue;
	using std::endl;
	using std::cout;
	using std::cin;
	using std::bad_alloc;
	using std::make_shared;

	class currentLowestPath;
	class arc;
	class Node;

	class Graf
	{
	private:
		list<shared_ptr<Node>> NoduriGraf;
		list < shared_ptr<Node> > NodesSearchedInGraf{};

	public:
		//------------------------------------------------------------
		bool GrafVid();
		void InsertNodeParam(int);
		void InsertArcParam(bool, int, int, size_t);
		void Dijkstra();
		bool NodeExistsInNodesSearchedInGraf(shared_ptr<Node>);
		bool NodeExistsInList(shared_ptr<Node>, list < shared_ptr<Node>>&);
		void PrintStructure();
		void afisareNoduriGraf();
		void PrintNodesSearchedInGraf();
		void PrintQueue(queue <shared_ptr<Node>>&);
		size_t sizeof_NoduriGraf() { return NoduriGraf.size(); }
		shared_ptr<arc> smallestPathFromNode(shared_ptr<Node>);
		void clearSearchedList() { NodesSearchedInGraf.clear(); }
		auto getFirstNode() { return this->NoduriGraf.begin(); }
		//------------------------------------------------------------

		Graf()
		{
			NoduriGraf.clear();
			NodesSearchedInGraf.clear();
		}

		~Graf() = default;
	};
}
