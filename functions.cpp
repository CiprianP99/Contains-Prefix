#include "Header.h"

StringSET::StringSET()
{
	this->isLeaf = false;
	
	for (int i = 0; i < CHAR_SIZE; i++)
		this->character[i] = NULL;
}

void StringSET::add(string key)
{
	StringSET* root = this; // porneste din radacina

	for (int i = 0; i < key.length(); i++)
	{
		//creaza un nod nou, daca calea nu exista
		if (root->character[key[i]] == NULL)
			root->character[key[i]] = new StringSET();
		root = root->character[key[i]];
	}
	root->isLeaf = true; //marcheaza nodul curent ca si frunza
}

bool StringSET::contains(string key)
{
	//daca arborele este gol => false
	if (this == NULL)
		return false;
	StringSET* root = this;
	for (int i = 0; i < key.length(); i++)
	{
		root = root->character[key[i]]; // merge la nodul urmator

		if (root == NULL)
			return false;
	}
	return root->isLeaf;
}
bool StringSET::isNotEmpty(StringSET const* root)
{
	if (root == NULL)
		return 0;
	else
	for (int i = 0; i < CHAR_SIZE; i++)
		if (root->character[i])
			return true;
	return false;
}
bool StringSET::Delete(StringSET*& root, string key,bool &erased)
{
	
	if (root == nullptr) {
		
		return false;//daca trie-ul este gol, returnam 0;
	}

	if (key.length()) //daca nu am gasit sfarsitul key-ului
	{
		if (root != nullptr && root->character[key[0]] != nullptr && Delete(root->character[key[0]], key.substr(1),erased) && root->isLeaf == false)
		{
			if (!isNotEmpty(root))
			{
				delete root;
				erased = 1;
				root = nullptr;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	if (key.length() == 0 && root->isLeaf) //daca am atins sfarsitul key-ului
	{
		if (!isNotEmpty(root)) //daca nodul este o frunza si nu are copii
		{
			//stergem nodul curent
			delete root;
			erased = 1;
			root = nullptr;
			//stergem parintii non-frunza
			return true;
		}
		//daca nodul curent este frunza si are copii
		else
		{
			root->isLeaf = false; // marcam nodul ca si non frunza, dar nu il stergem
			return false;
		}
	}
	return false;
}
void StringSET::printWord(char* str, int n) //functie helper pentru a printa litera cu litera
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << char(str[i] + 159);
	}
}
void StringSET::toString(StringSET*& root, char* wordArray, int pos = 0)
{
	if (root == NULL)
		return;
	if (root->isLeaf) //daca nodul curent este sfarsitul unui cuvant  atunci printam valorile in array 
	{
		printWord(wordArray, pos);
	}
	for (int i = 0; i < CHAR_SIZE; i++)
	{
		if (root->character[i] != NULL)
		{
			wordArray[pos] = i + 'a'; //adaugam caracterul curent in array
			toString(root->character[i], wordArray, pos + 1); //apelam functia recursiv pentru fiecare nod copil
		}
	}
}

int StringSET::Size(StringSET* root)
{
	int count = 0;
	if (root == NULL)
		return count;
	else
	{
		if (root->isLeaf)
			count++;
		for (int i = 0; i < CHAR_SIZE; i++)
			if (root->character[i])
				count += Size(root->character[i]);
	}
		return count;
	
}
bool StringSET::containsPrefix(StringSET* root,char prefix[10])
{
	if (root == NULL)
		return false;
	
	for (int i = 0; i < strlen(prefix); i++)
	{
		root = root->character[prefix[i]]; 

		if (root == NULL)
			return false;
	}
	return true;

}
