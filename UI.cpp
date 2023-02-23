#include "UI.h"

using namespace std;

UI::UI() {
	//	Open dictionary file for input
	ifstream inFile("dictionary.txt");

	//	If file not open send message
	if (!inFile.is_open()) {
		cout << " File is not open.\n";
	}

	//	Get each line and insert to trie
	
	
	string word;

	while (getline(inFile, word)) {
		istringstream iss(word);

		// cout << word << "\n";
		
		//	Convert str to *char
		char* cstr = _strdup(word.c_str());
		
		insert(root, cstr);

		//	Clean up cstr after each use
		delete[] cstr;
	}

	menu();

	system("Pause");
}

bool UI::isWord(std::string word)
{
	//	Convert str to *char
	char* cstr = _strdup(word.c_str());

	if (search(root, cstr)) {
		return true;
	}
	return false;
}

void UI::menu()
{
	while (!exit) {

		//	Clear screen
		system("cls");
		
		cout << " Please enter a word to verify spelling. \n";
		string word = "";
		cin >> word;

		if (isWord(word)) {
			cout << " " << word << " is spelled correclty. \n";
		}
		else {
			cout << " " << word << " is not spelled correctly. \n";
		}

		cout << " Would you like to try another? \n";
		cout << " Enter '1' for YES or '0' for NO. \n";
		
		//	Take input from user
		cin >> exit;

		//	Flip input for loop 
		exit = !exit;
		
	}

}
