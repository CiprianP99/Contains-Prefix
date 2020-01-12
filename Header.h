#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define CHAR_SIZE 128
class StringSET
{
public:
	bool isLeaf;
	StringSET* character[CHAR_SIZE];

	StringSET();

	void add(string key); //put key into the set
	bool Delete(StringSET*& root, string key, bool& erased); //remove key from the set
	bool contains(string key); //is key in the set?
	bool isNotEmpty(StringSET const* root); //is the set empty ?
	void printWord(char* str, int n);
	void toString(StringSET*& root, char* wordArray, int pos); //string representation of the set
	int Size(StringSET* root); //number of keys in the set
	bool containsPrefix(StringSET* root,char prefix[10]); //returns true if there is a string in the set that contains s as a prefix.
};