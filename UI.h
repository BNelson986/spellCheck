#pragma once
#include "TrieStructure.h"
#include <sstream>
#include <fstream>
#include <iostream>

class UI
{
public:
	UI();
	bool isWord(std::string);	//	Returns true if string found in list
	void menu();				//	Displays menu for UI

	trie* root = nullptr;
	bool exit = false;
};

