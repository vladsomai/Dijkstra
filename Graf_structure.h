#include"Node_structure.h"
#include <queue>

namespace structure_graf
{
	class currentLowestPath;

	class Graf
	{
	 private:
		list<shared_ptr<Node>> NoduriGraf;//lista care v-a retine adresele fiecarui nod din graf (fiecare nod este head - capul listei inlantuite)
		list < shared_ptr<Node> > NodesSearchedInGraf{};//lista in care vom insera nodurile parcurse de PRIM.

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

	//cream un tip de date care va contine nodul sursa, nodul target si cel mai mic path care leaga aceste noduri
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




	void currentLowestPath::setSource(shared_ptr<Node>& sourceParam) { this->source = sourceParam; }
	void currentLowestPath::setTarget(shared_ptr<Node>& targetParam) { this->target = targetParam; }
	void currentLowestPath::setWeight(size_t weightParam) { this->weight = weightParam; }

	shared_ptr<Node> currentLowestPath::getSource() { return this->source; }
	shared_ptr<Node> currentLowestPath::getTarget() { return this->target; }
	size_t currentLowestPath::getWeight() { return this->weight; }

	shared_ptr<arc> structure_graf::Graf::smallestPathFromNode(shared_ptr<Node> inputNode)
	{
		size_t currentWeight = 0;
		size_t currentSmallestWeight = SIZE_MAX;
		size_t counter = 0;
		list<shared_ptr<arc>> listOfArches = inputNode->getNextArc();
		queue<shared_ptr<arc>> que;

		shared_ptr<arc> returnArc = nullptr;

		if (listOfArches.size() == 0)
		{
			return nullptr;
		}
		for (auto it = listOfArches.begin(); it != listOfArches.end(); it++)
		{
			currentWeight = it->get()->getNextWeight();
			if (currentWeight < currentSmallestWeight)
			{
				currentSmallestWeight = currentWeight;
				returnArc = *it;
			}
		}
		return returnArc;
	}

	//functie de afisare a numerelor vizitate
	void  structure_graf::Graf::PrintNodesSearchedInGraf()
	{
		for (auto iterator = this->NodesSearchedInGraf.begin(); iterator != this->NodesSearchedInGraf.end(); ++iterator)
		{
			cout << iterator->get()->getData() << "  ";
		}
	}

	void structure_graf::Graf::PrintQueue(queue <shared_ptr<Node>>& actualQueue)
	{
		queue<shared_ptr<Node>> temp = actualQueue;
		while (!temp.empty())
		{
			std::cout << temp.front()->getData()<< " ";
			temp.pop();
		}
		std::cout << std::endl;
	}

	//functia de verificare graf vid
	bool Graf::GrafVid()
	{
		if (NoduriGraf.empty())
		{
			cout << "Graf Vid!" << endl;
			return true;
		}
		else
		{
			return false;
		}
	}

	//functie de stergere nod parametru dintr-o lista parametru
	void DeleteNodeInList(shared_ptr<Node>& deleteNode, list < shared_ptr<Node>>& li)
	{
		for (auto iterator = li.begin(); iterator != li.end(); ++iterator)
		{
			if (*iterator == deleteNode)
			{
				li.erase(iterator);
				return;
			}
		}
	}

	//functie de afisare a coadei
	void print_queue(queue<shared_ptr<Node>>& q)
	{
		cout << "Queue: ";
		while (!q.empty())
		{
			cout << q.front()->getData() << "\t";
			q.pop();
		}
	}

	//functie de afisare a unei liste oarecare
	void print_list(list<shared_ptr<arc>>& li)
	{
		for (auto iterator = li.begin(); iterator != li.end(); ++iterator)
		{
			cout <<iterator->get()->getNextNode()->getData() << "(w:" <<iterator->get()->getNextWeight()<<')' << "->";
		}
		cout << endl;
	}

	//functie de afisare lista cu adresele fiecarui element din lista
	void print_list_verbose(list<shared_ptr<arc>>& li)
	{
		for (auto iterator = li.begin(); iterator != li.end(); ++iterator)
		{
			cout << iterator->get()->getNextNode()->getData()
				<< " (" << iterator->get()->getNextNode() << ") "
				<< "->";
		}
		cout << endl;
	}

	//functia de afisare noduri graf, iteram in lista care retine adresa nodurilor, aici afisam doar nodurile prezente in graf, nu si structura grafului
	void Graf::afisareNoduriGraf()
	{
		if (this->GrafVid())
		{
			return;
		}
		else
		{
			cout << "Graful contine:\n";
			shared_ptr<Node> temp{};
			for (auto i = NoduriGraf.begin(); i != NoduriGraf.end(); ++i)
			{
				cout << i->get()->getData() << endl;
			}
		}
	}

	//functie de afisare structura a grafului - afisam fiecare arc pe care il are un nod pe o linie
	void Graf::PrintStructure()
	{
		if (this->GrafVid())
		{
			return;
		}
		bool optiune{ false };
		cout << "Doriti sa afisati si adresele nodurilor? (1 - DA / 0 - NU)" << endl;
		cin >> optiune;
		cout <<"====================Structura graf===================="<< endl;
		if (optiune)
		{
			for (auto actual = NoduriGraf.begin(); actual != NoduriGraf.end(); ++actual)
			{
				auto tempList = actual->get()->getNextArc();

				cout << actual->get()->getData()
					<< " (" << *actual << ") "
					<< "  ->";
				print_list_verbose(tempList);

				cout << endl;
			}
			return;
		}
		else
		{
			for (auto actual = NoduriGraf.begin(); actual != NoduriGraf.end(); ++actual)
			{
				auto tempList = actual->get()->getNextArc();

				cout << actual->get()->getData()<< "  ->";
				print_list(tempList);

				cout << endl;
			}
			return;
		}
	}
	
	void Graf::InsertNodeParam(int newNumber)
	{
		try
		{
			bool numberAlreadyExists{ false };
			shared_ptr<Node> newNode = make_shared<Node>();

			cout << "\nIntroduceti un numar in noul nod: ";	//cin >> newNumber;
			newNode->setData(newNumber);

			for (auto actual = NoduriGraf.begin(); actual != NoduriGraf.end(); ++actual)
			{
				//daca avem deja numarul in list, deci nu putem face insertia
				if (actual->get()->getData() == newNode->getData())
				{
					numberAlreadyExists = true;
					break;
				}
			}

			if (numberAlreadyExists)
			{
				cout << "Numarul introdus exista deja in graf." << endl;
				return;
			}
			else
			{
				NoduriGraf.push_back(newNode);//introducem noul nod in lista care va retine adresele nodurilor grafului
			}
		}
		//verificam daca alocarea memoriei a avut loc(daca functia "make_shared" nu poate aloca memorie aceasta arunca un obiect de tipul "bad_alloc" -> alocarea memoriei dinamica pentru "newNode" nu mai are loc
		catch (const bad_alloc& e)
		{
			cout << "Nu am putut aloca memorie pentru un nou nod.\n" << e.what() << '\n';
			return;
		}
	}

	//verificam daca un nod exista in lista rezultata din cautarea nodurilor 
	bool  structure_graf::Graf::NodeExistsInNodesSearchedInGraf(shared_ptr<Node> actual)
	{
		for (auto iterator = this->NodesSearchedInGraf.begin(); iterator != this->NodesSearchedInGraf.end(); ++iterator)
		{
			if (iterator->get()->getData() == actual->getData())
			{
				return true;
			}
		}
		return false;
	}

	//verificam daca un nod exista in lista
	bool  structure_graf::Graf::NodeExistsInList(shared_ptr<Node> actual , list<shared_ptr<Node>>& li)
	{
		for (auto iterator = li.begin(); iterator != li.end(); ++iterator)
		{
			if (*iterator == actual)
			{
				return true;
			}
		}
		return false;
	}

    //functia de inserare arc
	void structure_graf::Graf::InsertArcParam(bool ConnectionType, int source, int target, size_t weight)
	{
		if (this->GrafVid())
		{
			return;
		}

		//aceste nodri vor retine adresele nodurilor la care dorim sa inseram un arc (source - target)
		shared_ptr<Node> pointerToSourceNode;
		shared_ptr<Node> pointerToTargetNode;

		int targetWasFound{ false };
		int sourceWasFound{ false };

		cout << "Introduceti doua noduri pe care doriti sa le conectati / deconectati: " << endl;
		cout << "Primul numar: " << source;   // cin >> number1;
		cout << "\nAl doilea numar: " << target << endl;// cin >> number2;

		try
		{
			//ne asiguram prima data ca numerele la care dorim sa introducem un arc exista in graf
			//iteram in lista pana cand gasim nodul la care dorim sa ii adaugam un arc
			for (auto actual = NoduriGraf.begin(); actual != NoduriGraf.end(); ++actual)
			{
				//daca cheia nodului urmator din iteratie este egala cu numarul pe care dorim sa il aflam setam pe true si inregistram adresa nodului in variabila pointerToNode
				if (source == actual->get()->getData())
				{
					cout << "Primul numar a fost gasit in graf" << endl;
					sourceWasFound = true;
					pointerToSourceNode = *actual;//salvam adresa nodului pentru operatii viitoare
				}

				if (target == actual->get()->getData())
				{
					cout << "Al doilea numar a fost gasit in graf" << endl;
					targetWasFound = true;
					pointerToTargetNode = *actual;//salvam adresa nodului pentru operatii viitoare
				}
			}

			//dupa ce am gasit numerele facem legaturile
			if (sourceWasFound && targetWasFound)
			{
				shared_ptr<arc> nextArcSource = make_shared<arc>();
				shared_ptr<arc> nextArcTarget = make_shared<arc>();

				nextArcSource->setNext(pointerToTargetNode, weight);
				nextArcTarget->setNext(pointerToSourceNode, weight);

				//--------------------------------------Nodul 1------------------------------------------------------------
				//daca dorim sa facem legatura apelam functia de set next a nodului source
				if (ConnectionType == true)
				{
					pointerToSourceNode->setNextArc(nextArcSource);//stabilim legaturile source
					pointerToTargetNode->setNextArc(nextArcTarget);//stabilim legaturile target
					cout << "Succes, link creat!" << endl;
					return;
				}
				else//daca dorim sa stergem legatura prima data trebuie sa cautam ca exista un link intre cele doua noduri, dupa care le vom sterge.
				{
					//iteram in lista nodurilor legate la target pentru a verifica daca source exista in aceasta lista, daca exista vom sterge adresa din lista.
					//pentru nodul target
					auto tempListTarget = pointerToTargetNode->getNextArc();
					auto tempListSource = pointerToSourceNode->getNextArc();

					cout << "Lista lui target: ";
					print_list(tempListTarget);
					cout << "Lista lui source: ";
					print_list(tempListSource);

					for (auto iterator = tempListTarget.begin(); iterator != tempListTarget.end(); ++iterator)
					{
						if (iterator->get()->getNextNode() == pointerToSourceNode)
						{
							cout << "Nodul " << iterator->get()->getNextNode()->getData() << " va fi sters!" << endl;
							tempListTarget.erase(iterator);//stergem nodul source din lista
							pointerToTargetNode->clearNextList();//stergem lista principala
							pointerToTargetNode->setNextList(tempListTarget);//trimitem ca si parametru lista temporara in lista principala(refresh list)
							break;
						}
					}

					//pentru nodul source
					for (auto iterator = tempListSource.begin(); iterator != tempListSource.end(); ++iterator)
					{
						if (iterator->get()->getNextNode() == pointerToTargetNode)
						{
							cout << "Nodul " << iterator->get()->getNextNode()->getData() << " va fi sters!" << endl;
							tempListSource.erase(iterator);//stergem nodul source din lista
							pointerToSourceNode->clearNextList();//stergem lista principala
							pointerToSourceNode->setNextList(tempListSource);//trimitem ca si parametru lista temporara in lista principala(refresh list)
							break;
						}
					}
				}
			}
		}
		catch (exception e)
		{
			cout << e.what() << endl;
			return;
		}

		if (!sourceWasFound)
		{
			cout << "Numarul " << source << " nu exista in graf" << endl;
			return;
		}

		if (!targetWasFound)
		{
			cout << "Numarul " << target << " nu exista in graf" << endl;
			return;
		}
	}

	/*
	* Implementam algoritmul lui dijkstra pentru a gasi cel mai mic path de la un nod catre fiecare nod din graf.
	* prima faza a algoritmului consta din crearea unei liste <listOfPaths> care va contine path-ul minim de la un nod la altul, populam aceasta lista cu nodul sursa, target si weight(path minim gasit)
	* in cazul in care exista un weight de la sursa la target populam weight-ul in listOfPaths cu acel weight, altfel il populam cu SIZE_MAX(imitam infinit).
	* dupa ce am terminat faza 1, vom avea listOfPaths populata cu nodul sursa si path catre fiecare nod din graf.
	* 
	* Faza 2 consta in iterarea catre cel mai mic nod vecin, nevizitat
	* retinem path-ul parcurs in "weightToActual" pe care il vom folosi pentru a calcula path-ul pana unde am ajuns la nodurile vecine nevizitate.
	*/
	void structure_graf::Graf::Dijkstra()
	{
		list < shared_ptr<Node> > DijkstraList = this->NoduriGraf;
		list<shared_ptr<arc>> listOfArchesSource;//lista care va retine nodurile legate la un nod
		list<shared_ptr<arc>> listOfArchesTarget;//lista care va retine nodurile legate la un nod
		list<shared_ptr<currentLowestPath>> listOfPaths;//lista care va retine cele mai mici legaturi intre noduri

		shared_ptr<arc> smallestArc = nullptr;
		size_t currentWeight = 0;
		size_t currentSmallestWeight = SIZE_MAX;//initializam cel mai mic weight cu cel mai mare numar pe care il putem aloca  
		const size_t maximumWeight = SIZE_MAX;
		size_t counter = 0;

		shared_ptr<Node> source = nullptr, target = nullptr;
		
		//calculam distanta de la fiecare nod la fiecare nod din graf
		for (auto eachGrafNode = DijkstraList.begin(); eachGrafNode != DijkstraList.end(); eachGrafNode++)
		{

			cout << "\n\n\nA new item will be applied by DIJKSTRA:\n";

			smallestArc = nullptr;
			currentWeight = 0;
			currentSmallestWeight = SIZE_MAX;
			counter = 0;
			source = nullptr, target = nullptr;

			NodesSearchedInGraf.clear();//stergem lista parcursa
			listOfPaths.clear();

			source = *eachGrafNode;//source
			smallestArc = smallestPathFromNode(source);

			//iteram in lista de noduri ale grafului pentru a gasi un arc cu weightul cel mai mic
			for (auto actualNode = DijkstraList.begin(); actualNode != DijkstraList.end(); actualNode++)
			{
				counter = 0;
				listOfArchesSource = eachGrafNode->get()->getNextArc();//lista de noduri catre care avem arc din eachGrafNode
				listOfArchesTarget = actualNode->get()->getNextArc();//lista de noduri catre care avem arc din actualNode
				if (*eachGrafNode != *actualNode)
				{
					target = *actualNode;
					shared_ptr<currentLowestPath> newPath = make_shared<currentLowestPath>();
					listOfPaths.push_back(newPath);//introducem tipul de date in lista
					newPath->setSource(source);
					newPath->setTarget(target);

					//iteram in lista de noduri ale actualNode pentru a verifica care weight este cel mai mic,
					//in momentul in care gasim un weight mai mic decat "currentSmallestWeight", vom seta "currentSmallestWeight" cu actualWeight
					for (auto actualArch = listOfArchesTarget.begin(); actualArch != listOfArchesTarget.end(); actualArch++)
					{
						//cout << source->getData() << " - " << target->getData() << endl;
					    //cout << actualArch->get()->getNextNode()->getData() << ",\t";

						//avem path catre source
						if (actualArch->get()->getNextNode() == source)
						{
							currentWeight = actualArch->get()->getNextWeight();//avem un weight valabil

							//retinem ca de la source la target avem path-ul current weight
							newPath->setSource(source);
							newPath->setTarget(target);
							newPath->setWeight(currentWeight);
						}
					}
				}
			}
			NodesSearchedInGraf.push_back(source);//introducem primul numar vizitat in nodes searched in graf 

			////print list of paths to source
			for (auto it = listOfPaths.begin(); it != listOfPaths.end(); it++)
			{
				cout << it->get()->getSource()->getData() << " ---- " << it->get()->getWeight() << " ---- ";
				cout << it->get()->getTarget()->getData() << endl;
			}
			cout << "\nPHASE 1 FINISHED...\n\n";

			source = smallestArc->getNextNode();//intram in nodul cu path-ul cel mai mic
			size_t weightToActual = smallestArc->getNextWeight();

			while (NoduriGraf.size() != NodesSearchedInGraf.size())
			{
		    	size_t acumulatedWeight = 0;
				size_t tempWeight{};
				listOfArchesSource = source->getNextArc();//lista de noduri catre care avem arc
				smallestArc = smallestPathFromNode(source);//cel mai mic arc din nodul sursa

				//cout << "The smallest will become the new source: " << source->getData() << endl;

				//iteram in lista de noduri ale actualNode pentru a verifica care weight este cel mai mic,
				//in momentul in care gasim un weight mai mic decat "currentSmallestWeight", vom seta "currentSmallestWeight" cu actualWeight
				for (auto actualArch = listOfArchesSource.begin(); actualArch != listOfArchesSource.end(); actualArch++)
				{
					shared_ptr<Node> actualNode = actualArch->get()->getNextNode();
					
					//nodul nu trebuie sa fie in nodurile vizitate deja
					if (!NodeExistsInNodesSearchedInGraf(actualNode))
					{
						for (auto it = listOfPaths.begin(); it != listOfPaths.end(); it++)
						{
							if (it->get()->getTarget() == actualNode)
							{
								//cout << it->get()->getSource()->getData() << '\t';
								//cout << it->get()->getWeight() << '\t';
								//cout << it->get()->getTarget()->getData() << "\t\n";

								//weight acumulat trebuie sa fie egal cu cel mai mic path al lui source + patth la actualNode
								acumulatedWeight = weightToActual + actualArch->get()->getNextWeight();
								
								//cout << "Total weight from " << it->get()->getSource()->getData() << " to " << it->get()->getTarget()->getData() << " is " << acumulatedWeight << endl;
								//cout << "because " << weightToActual << " + " << actualArch->get()->getNextWeight() << " = " << acumulatedWeight << endl;

								if (acumulatedWeight < it->get()->getWeight())
								{ 
								//	cout << "We are setting the distance from " << it->get()->getSource()->getData() << " to " << it->get()->getTarget()->getData()<<" with "<< acumulatedWeight <<"\n\n";
									it->get()->setWeight(acumulatedWeight);//setam noul weight in lista
								}
								else
								{
									//cout << "No changes were made for the above items" <<"\n\n";
								}
							}
						}
					}
				}
				//vom crea un nod temporar a carei lista de next nu va contine nodurile vizitate
				shared_ptr<Node> temp = make_shared<Node>();
				
				temp->setData(source->getData());
				temp->setNextList(listOfArchesSource);
				auto listOfArchestemp = temp->getNextArc();//retine nodurile de next intr-o variabila
			
				//pentru fiecare nod care a fost vizitat vom sterge acel link pentru a nu vizita inca odata
				for (auto it : NodesSearchedInGraf)
				{
					listOfArchestemp = temp->DeleteNodeInList(it, listOfArchestemp);
				}

				temp->setNextList(listOfArchestemp);//setam lista modificata in nodul nou
				smallestArc = smallestPathFromNode(temp);//cel mai mic nod nevizitat al nodului la care suntem in iteratie
				if (smallestArc == nullptr)
				{
					NodesSearchedInGraf.push_back(source);
					cout << "All nodes were visited for " << eachGrafNode->get()->getData() << ".\n\n\n\n\n====================DIJKSTRA RETURNED THE FOLLOWING=========================\n";
					cout << "\nS ---- W ---- T\n" << endl;
					break;
				}
				else
				{
					cout << "Smallest node from " << source->getData() << " is " << smallestArc->getNextNode()->getData() << "\n";

					NodesSearchedInGraf.push_back(source);
					source = smallestArc->getNextNode();
					weightToActual += smallestArc->getNextWeight();

					for (auto it = listOfPaths.begin(); it != listOfPaths.end(); it++)
					{
						cout << it->get()->getSource()->getData() << " ---- " << it->get()->getWeight() << " ---- ";
						cout << it->get()->getTarget()->getData() << endl;
					}
				}
			}

			//print list of paths to source
			for (auto it = listOfPaths.begin(); it != listOfPaths.end(); it++)
			{

				cout << it->get()->getSource()->getData() << " ---- " << it->get()->getWeight() << " ---- ";
				cout << it->get()->getTarget()->getData() << endl;

			}
			cout << "Visited nodes:\n";
			PrintNodesSearchedInGraf();
			cout << endl;
			system("pause");
		}
		cout << endl;
	}
}

