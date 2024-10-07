#include <iostream>
#include "hangman.hpp"
#include "out.hpp"

void Hangman::printGibbet(const int &errorCount) {
	std::string head = errorCount >= 1 ? "(_)" : "";       // head      -> errors >= 1
	std::string body = errorCount >= 4 ? "/|\\" :          // right arm -> errors >= 4
										 errorCount >= 3 ? "/|" :            // left arm  -> errors >= 3
										 errorCount >= 2 ? " |" : "";        // body      -> errors >= 2
	std::string lowerBody = errorCount >= 2 ? " |" : "";    // body      -> errors >= 2
	std::string legs = errorCount >= 5 ?                   // right leg -> errors >= 5
										 errorCount >= 6 ? "/ \\" : "/" : ""; // left leg  -> errors >= 6

	printf("\nLives: %d of %d\n", MAX_TRIES - errorCount, MAX_TRIES);

	std::cout << "  _______ " << std::endl;
	std::cout << " |/      |" << std::endl;
	std::cout << " |      " << head << std::endl;
	std::cout << " |      " << body << std::endl;
	std::cout << " |      " << lowerBody << std::endl;
	std::cout << " |      " << legs << std::endl;
	std::cout << " |" << std::endl;
	std::cout << "_|___\n\n" << std::endl;
}

void Hangman::printSecretWord(const std::string &word, const std::map<char, bool> &guesses) {
	for (char c : word) {
		// map operator [] to access c (map[c]) defines c as false if it doesn't exist on the map;
		// therefore, using const we cannot use [] operator, so the following code doesn't work
		// cout << (guesses[c] ? c : '_') << " ";
		std::cout << (guesses.contains(c) ? c : '_') << " ";
	}
	std::cout << std::endl;
}

void Hangman::printWrongGuesses(const std::array<char, 6> &errors, const int &errorCount) {
	std::cout << "\nWrong letters:" << std::endl;

	for (int i = 0; i < errorCount; i++) {
		std::cout << errors[i] << (i == errorCount - 1 ? "" : " - ");
	}

	std::cout << std::endl;
}

void Hangman::printGame(const std::string &word, const std::map<char, bool> &guesses, const std::array<char, 6> &errors,
												const int &errorCount) {
	Hangman::printGibbet(errorCount);
	Hangman::printSecretWord(word, guesses);
	Hangman::printWrongGuesses(errors, errorCount);
	std::cout << std::endl;
}
