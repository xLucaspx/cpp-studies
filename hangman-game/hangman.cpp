#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string> // needed for using strings in c++
#include <vector>
#include "hangman.h"
#include "out.h"

using namespace std;

string chooseSecretWord(vector<string> &words) {
	srand(time(nullptr));

	int sortedIndex = rand() % words.size();
	return words[sortedIndex];
}

bool stringContains(string &s, char element) {
/* a string is char vector. E.g.:
 * string s = "string" -> | s | t | r | i | n | g |
 *                        | 0 | 1 | 2 | 3 | 4 | 5 |
 * s[0] -> "S"
 * s[1] -> "T"
 * etc.
 */
	for (char c : s) {
		if (c == element) {
			return true;
		}
	}
	return false;
}

void guess(string &word, map<char, bool> &guessed, vector<char> &errors) {
	char guess;
	cout << "What's your guess? ";
	cin >> guess;

	if (!isalpha(guess)) {
		cout << "\nInvalid guess...\n" << endl;
		return;
	}

	guess = toupper(guess);

	if (guessed[guess]) {
		cout << "\nYou've already typed that letter...\n" << endl;
		return;
	}

	guessed[guess] = true;
	if (!stringContains(word, guess)) {
		cout << "\nThe secret word doesn't contain the letter " << guess << endl << endl;
		errors.push_back(guess);
		return;
	}

	cout << "\nAlright! The secret word contains the letter " << guess << endl << endl;
}

bool win(string &secretWord, map<char, bool> &guessed) {
	for (char c : secretWord) {
		if (!guessed[c]) {
			return false;
		}
	}
	return true;
}

bool hanged(int errorCount) {
	return errorCount >= MAX_TRIES;
}

void hangmanGame(vector<string> &words) {
	string secretWord = chooseSecretWord(words);
	// dictionary structure for storing keys and values, used here to verify if a letter was already guessed
	map<char, bool> guessed;
	vector<char> errors;

	do {
		// TODO: clear screen
		printGame(secretWord, guessed, errors);
		guess(secretWord, guessed, errors);
	} while (!(win(secretWord, guessed) || hanged(errors.size())));

	// printing game one more time
	printGame(secretWord, guessed, errors);

	if (hanged(errors.size())) {
		printHanged();
	} else {
		printWin();
	}
	cout << "The secret word was -> " << secretWord << " <-\n" << endl;
}
