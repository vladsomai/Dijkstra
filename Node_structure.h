#pragma once
#include<iostream>
#include<memory>
#include<list>

using namespace std;

namespace structure_graf
{

	class arc;

	class Node
	{
	private:
		int data;//cheie
		list< shared_ptr<arc> > next;//lista cu nodurile urmatoare

	public:
		void setData(int);
		int getData();

		void setNextArc(shared_ptr<arc>&);
		list<shared_ptr<arc>> getNextArc(); // functie care va returna lista nodurilor la care suntem linkuiti

		void clearNextList();
		void setNextList(list < shared_ptr<arc>>&);
		list<shared_ptr<arc>> DeleteNodeInList(shared_ptr<Node>& deleteNode, list < shared_ptr<arc>>& li);


		//constructor pentru Node - initializam cheia la 0
		Node()
		{

			this->next.clear();
			this->data = 0;

		}

	};

	int Node::getData()
	{

		return this->data;

	}


	void Node::setData(int newData)
	{

		this->data = newData;

	}
	
	

	void Node::setNextArc(shared_ptr<arc>& NextParam)
	{

		this->next.push_back(NextParam);

	}


	list<shared_ptr<arc>> Node::getNextArc()
	{

		return this->next;

	}


	void Node::clearNextList()
	{

		this->next.clear();

	}


	void Node::setNextList(list < shared_ptr<arc> > &ListParam)
	{

		this->next = ListParam;

	}




	//=========================================================================


	class arc
	{
	private:
		shared_ptr<structure_graf::Node> nextNode;
		size_t weight;


	public:
		void setNext(shared_ptr<structure_graf::Node>&, size_t&);
		shared_ptr<structure_graf::Node> getNextNode();
		size_t getNextWeight();

		arc()
		{
			this->nextNode = nullptr;
			this->weight = 0;
		}

	};



	void arc::setNext(shared_ptr<structure_graf::Node>& nextNodeParam , size_t& weightParam)
	{

		this->nextNode = nextNodeParam;
		this->weight = weightParam;

	}

	shared_ptr<structure_graf::Node> arc::getNextNode()
	{

		return this->nextNode;

	}

	size_t arc::getNextWeight()
	{

		return this->weight;

	}





	//functie de stergere nod parametru dintr-o lista parametru
	list<shared_ptr<arc>> Node::DeleteNodeInList(shared_ptr<Node>& deleteNode, list < shared_ptr<arc>>& li)
	{

		//folosim un obiect de tipul std::list<>::iterator pentru iteratie in lista parametru
		for (auto iterator = li.begin(); iterator != li.end(); ++iterator)
		{

			//daca nodul pe care dorim sa il stergem este cel la care am ajuns in iteratie apelam functia de erase
			if (iterator->get()->getNextNode() == deleteNode)
			{

				//cout << iterator->get()->getNextNode()->getData() << " will be erased because it was visited already." << endl;
				li.erase(iterator);
				return li;

			}

		}

		return li;

	}

}