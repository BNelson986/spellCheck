#include "TrieStructure.h"

trie* getNewNode()
{
	trie* node = new trie;
	node->isLeaf = false;

	return node;
}

void insert(trie*& root, char* word)
{
	//	Base Case
	if (root == nullptr) {
		root = getNewNode();
	}

	//	Start at root node
	trie* currentNode = root;
	while (*word) {

		//	create a new node if path does not exist
		if (currentNode->map.find(*word) == currentNode->map.end()) {
			currentNode->map[*word] = getNewNode();
		}

		//	Go to next node
		currentNode = currentNode->map[*word];

		//	Move to next character
		word++;
	}

	//	Mark currentNode as a leaf
	currentNode->isLeaf = true;
}

bool haveChildren(trie const* currentNode) {
	for (auto it : currentNode->map) {
		//	If a child is found
		if (it.second != nullptr) {
			return true;
		}
	}
	return false;
}

bool search(trie* root, char* word)
{
	//	Base Case
	if (root == nullptr) {
		return false;
	}

	//	Iterate through string, starting at root
	trie* currentNode = root;

	while (*word) {
		//	Go to next node
		currentNode = currentNode->map[*word];

		//	If end of path in trie is reached (No match found)
		if (currentNode == nullptr) {
			return false;
		}

		//	Move to next letter
		word++;
	}

	return currentNode->isLeaf;
}
