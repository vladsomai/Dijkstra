#pragma once
#include<iostream>
#include<memory>
#include<list>
#include "Arc.h"

namespace structure_graf
{
	class arc;
	class Node
	{
	private:
		int data;//cheie
		std::list<std::shared_ptr<arc>> next;//lista cu nodurile urmatoare
	public:
		void setData(int);
		int getData();

		void setNextArc(std::shared_ptr<arc>);
		std::list<std::shared_ptr<arc>> getNextArc(); // functie care va returna lista nodurilor la care suntem linkuiti

		void clearNextList();
		void setNextList(std::list<std::shared_ptr<arc>>&);
		std::list<std::shared_ptr<arc>> DeleteNodeInList(std::shared_ptr<Node> deleteNode, std::list<std::shared_ptr<arc>>& li);
		
		Node() 
		{
			this->next.clear();
			this->data = 0;
		}
	};
}