#include <iostream>
#include "hangman.hpp"
#include "out.hpp"

using namespace std;

void printHeader() {
	cout << "  _______ " << endl;
	cout << " |/      |" << endl;
	cout << " |" << endl;
	cout << " |          THE HANGMAN" << endl;
	cout << " |             GAME" << endl;
	cout << " |" << endl;
	cout << " |" << endl;
	cout << "_|___\n" << endl;
}

void printMenu() {
	cout << "-- MENU --\n" << endl;
	cout << "[1] Play game" << endl;
	cout << "[2] Add word\n" << endl;
}

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
	printGibbet(errors.size());
	printSecretWord(word, guesses);
	printWrongGuesses(errors);
	cout << endl;
}

void printHanged() {
	cout << "      _______________" << endl;
	cout << "     /               \\" << endl;
	cout << "    /                 \\" << endl;
	cout << "  //                   \\/\\" << endl;
	cout << "  \\|   XXXX     XXXX   | /" << endl;
	cout << "   |   XXXX     XXXX   |/" << endl;
	cout << "   |   XXX       XXX   |" << endl;
	cout << "   |                   |" << endl;
	cout << "   \\__      XXX      __/" << endl;
	cout << "     |\\     XXX     /|" << endl;
	cout << "     | |           | |" << endl;
	cout << "     | I I I I I I I |" << endl;
	cout << "     |  I I I I I I  |" << endl;
	cout << "     \\_             _/" << endl;
	cout << "       \\_         _/" << endl;
	cout << "         \\_______/\n" << endl;
	cout << "Sorry, you were hanged..." << endl;
}

void printWin() {
	cout << "       ___________" << endl;
	cout << "      '._==_==_=_.'" << endl;
	cout << "      .-\\:      /-." << endl;
	cout << "     | (|:.     |) |" << endl;
	cout << "      '-|:.     |-'" << endl;
	cout << "        \\::.    /" << endl;
	cout << "         '::. .'" << endl;
	cout << "           ) (" << endl;
	cout << "         _.' '._" << endl;
	cout << "        '-------'\n" << endl;
	cout << "Congratulations, you won!" << endl;
}
