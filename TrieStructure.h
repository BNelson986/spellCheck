#pragma once
#define	N 26

#include <unordered_map>

struct trie {
	bool isLeaf;
	std::unordered_map<char, trie*> map;
};

trie* getNewNode();				//	Returns new node of trie
void insert(trie*&, char*);		//	Inserts a string intro trie
bool haveChildren(trie const*);	//	Returns true if node has any children
bool search(trie*, char*);		//	Returns true if string is found
