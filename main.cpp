#include "Header.h"

int main()
{
	StringSET* head = new StringSET();

	char wordArray[CHAR_SIZE]; // pt stocarea caracterelor
	char str[20];
	string s; //string pt introducerea unui cuvant
	string p; // string pt cautarea unui cuvant
	string d; //string pt stergerea unui cuvant
	int option = 0;
	bool erased = 0;
	char s[10]; //prefix
label_menu:
	while (option != 8)
	{
		cout << "Meniu: " << endl;
		cout << "1.Introduceti cuvant ";
		cout << endl;
		cout << "2.Stergeti cuvant ";
		cout << endl;
		cout << "3.Verificati daca un cuvant exista in arbore ";
		cout << endl;
		cout << "4.Afisati toate cuvintele din arbore ";
		cout << endl;
		cout << "5.Este arborele gol?";
		cout << endl;
		cout << "6.Afisati numarul de cuvinte din arbore ";
		cout << endl;
		cout << "7. Cautati cuvinte dupa prefix ";
		cout << endl;
		cout << "8.Iesire ";
		cout << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			cout << endl << "Introduceti un cuvant: ";
			cin >> s;

			head->add(s);

			cout << endl;
			cout << endl;
			break;
		case 2:
			cout << endl << "Introduceti cuvantul pe care doriti sa-l stergeti: ";
			cin >> d;
			head->Delete(head, d,erased);
			if (erased == 1)
				cout << "Cuvantul a fost sters din arbore! "<<endl;
			else
				cout << "Cuvantul nu a fost gasit" << endl;

			break; 
		case 3:
			cout << endl << " Introduceti cuvantul pe care doriti sa-l cautati: ";
			cin >> p;
			if (head->contains(p) == 0)
				cout << "Cuvantul nu exista! " << endl;
			else
				cout << " Cuvantul exista! " << endl;
			break;
		case 4:
			cout << endl;

			head->toString(head, wordArray,0);

			cout << endl;
			cout << endl;
			break;
		case 5:
			cout << endl;
			if (head->isNotEmpty(head) == 1)
				cout << " Arborele nu e gol ";
			else cout << " Arborele este gol ";
			cout << endl;
			break;
		case 6:
			cout << endl;

			cout << head->Size(head);
			
			cout<<endl;
			break;
		case 7:
			cout << "Introduceti cuvintele cu prefixul pe care le cautati:" << endl;
			cin >> s;
			cout<<head->containsPrefix(head, s);
			cout << endl;
			break;
		default:
			cout << " Alege din optiunile de mai sus!!! ";
			cout << endl;
			goto label_menu;
		}
	}
	return 0;


}
