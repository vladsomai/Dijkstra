﻿#include "Graf_structure.h"


namespace structure_graf
{
	void menu(shared_ptr<structure_graf::Graf>);

	void menu(shared_ptr<structure_graf::Graf> graf)
	{

		bool grafVid{};
		size_t primOption{};
		int optiune = 0;
		auto it = graf->getFirstNode();

		do
		{

			system("cls");
			cout << "\n\n======MENU======\n";

			cout << "1.Dijkstra" << endl;
			cout << "2.Afisare noduri graf.\n";
			cout << "3.Afisare structura.\n";

			cout << "0.Exit.\n";

			cout << "Optiunea dvs. : ";
			cin >> optiune;

			cout << "\n\n======OUTPUT======" << endl;
			switch (optiune)
			{

			case 0:
				cout << "\n\nExiting..." << endl;
				break;

			case 1:
				graf->Dijkstra();
				break;

			case 2:
				graf->afisareNoduriGraf();
				cout << endl;
				break;

			case 3:
				graf->PrintStructure();
				cout << endl;
				break;

			default:
				cout << "Optiune gresita...\n";
				cout << endl;
				break;

			};
			system("pause");
		} while (optiune != 0);
	}
}


	int main()
	{
		using std::shared_ptr;
		using std::make_shared;

		shared_ptr<structure_graf::Graf> structure_grafExample = make_shared<structure_graf::Graf>();
		structure_grafExample->InsertNodeParam(2);
		structure_grafExample->InsertNodeParam(5);
		structure_grafExample->InsertNodeParam(6);
		structure_grafExample->InsertNodeParam(7);
		structure_grafExample->InsertNodeParam(9);
		structure_grafExample->InsertNodeParam(10);
		structure_grafExample->InsertNodeParam(13);

		structure_grafExample->InsertArcParam(true, 2, 10, 2);
		structure_grafExample->InsertArcParam(true, 2, 5, 4);
		structure_grafExample->InsertArcParam(true, 2, 9, 6);
		structure_grafExample->InsertArcParam(true, 5, 6, 9);
		structure_grafExample->InsertArcParam(true, 10, 9, 3);
		structure_grafExample->InsertArcParam(true, 9, 6, 3);
		structure_grafExample->InsertArcParam(true, 9, 13, 2);
		structure_grafExample->InsertArcParam(true, 6, 7, 5);
		structure_grafExample->InsertArcParam(true, 6, 13, 2);
		structure_grafExample->InsertArcParam(true, 7, 13, 5);

		menu(structure_grafExample);

	}
