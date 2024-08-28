#include <iostream>
#include "hangman.hpp"
#include "out.hpp"

using namespace std;

void printGibbet(int errorCount) {
	string head = errorCount >= 1 ? "(_)" : "";       // head      -> errors >= 1
	string body = errorCount >= 4 ? "/|\\" :          // right arm -> errors >= 4
								errorCount >= 3 ? "/|" :            // left arm  -> errors >= 3
								errorCount >= 2 ? " |" : "";        // body      -> errors >= 2
	string lowerBody = errorCount >= 2 ? " |" : "";    // body      -> errors >= 2
	string legs = errorCount >= 5 ?                   // right leg -> errors >= 5
								errorCount >= 6 ? "/\\" : "/" : ""; // left leg  -> errors >= 6

	printf("\nLives: %d of %d\n", MAX_TRIES - errorCount, MAX_TRIES);

	cout << "  _______ " << endl;
	cout << " |/      |" << endl;
	cout << " |      " << head << endl;
	cout << " |      " << body << endl;
	cout << " |      " << lowerBody << endl;
	cout << " |      " << legs << endl;
	cout << " |" << endl;
	cout << "_|___\n\n" << endl;
}

void printSecretWord(string &word, map<char, bool> &guesses) {
	for (char c : word) {
		cout << (guesses[c] ? c : '_') << " ";
	}
	cout << endl;
}

void printWrongGuesses(vector<char> &errors) {
	cout << "\nWrong letters:" << endl;

	for (char c : errors) {
		cout << c << " - ";
	}

	cout << endl;
}

void printGame(string &word, map<char, bool> &guesses, vector<char> &errors) {
	printGibbet((int) errors.size());
	printSecretWord(word, guesses);
	printWrongGuesses(errors);
	cout << endl;
}
