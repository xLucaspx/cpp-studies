#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 20

#include <format>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include "out.hpp"
#include "file.hpp"
#include "hangman.hpp"

using namespace std;

void addWord(vector<string> &words) {
	cout << "Type in the new word: ";
	string newWord;
	cin >> newWord;

	// ^[a-zA-Z]{3,20}$ {{ is the escape sequence and {} is where the args are going to be placed
	string newWordRegex = vformat("^[a-zA-Z]{{{},{}}}$", make_format_args(MIN_WORD_LENGTH, MAX_WORD_LENGTH));
	if (!regex_match(newWord, regex(newWordRegex))) {
		printf("\nInvalid value!\nWords must have a length between %d and %d and contain only letters!\n\n",
					 MIN_WORD_LENGTH, MAX_WORD_LENGTH);
		return;
	}

	// ensuring upper case
	for (char &c : newWord) {
		c = (char) toupper(c);
	}

	// no duplicates! find returns `last` param if no iterator is found
	if (find(words.begin(), words.end(), newWord) != words.end()) {
		return;
	}

	words.push_back(newWord);
	writeFile(words);
}

void run() {
	printHeader();
	vector<string> words = getWords();
	while (words.empty()) {
		cout << "There are no words available for playing...\nYou need to add at least one word!\n" << endl;
		addWord(words);
	}

	bool run = true;

	do {
		printMenu();
		cout << "Choose... ";
		int option;
		cin >> option;

		switch (option) {
			case 1:
				hangmanGame(words);
				break;
			case 2:
				addWord(words);
				break;
			default:
				run = false;
				break;
		}
	} while (run);

	cout << "\ngame over\n";
}

int main() {
	run();
	return 0;
}
