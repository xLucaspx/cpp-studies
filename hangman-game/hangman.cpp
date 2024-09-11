#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <regex>
#include "hangman.hpp"
#include "out.hpp"

std::string Hangman::chooseSecretWord(const std::vector<std::string> &words) {
	srand((unsigned) time(nullptr));

	int sortedIndex = (int) (rand() % words.size());
	return words[sortedIndex];
}

bool Hangman::stringContains(const std::string &s, char element) {
/* a string is char vector. E.g.:
 * string s = "string" -> | s | t | r | i | n | g |
 *                        | 0 | 1 | 2 | 3 | 4 | 5 |
 * s[0] -> "S"
 * s[1] -> "T"
 * etc.
 *
 * for (char c : s) {
 * 		if (c == element) {
 * 			return true;
 * 		}
 * 	}
 * 	return false;
 */

	return any_of(s.begin(), s.end(), [element](char c) {
		return c == element;
	});
}

void Hangman::guess(const std::string &word, std::map<char, bool> &guessed, std::vector<char> &errors) {
	char guess;
	std::cout << "What's your guess? ";
	std::cin >> guess;

	if (!isalpha(guess)) {
		std::cout << "\nInvalid guess...\n" << std::endl;
		return;
	}

	guess = (char) toupper(guess);

	if (guessed[guess]) {
		std::cout << "\nYou've already typed that letter...\n" << std::endl;
		return;
	}

	guessed[guess] = true;
	if (!Hangman::stringContains(word, guess)) {
		std::cout << "\nThe secret word doesn't contain the letter " << guess << std::endl << std::endl;
		errors.push_back(guess);
		return;
	}

	std::cout << "\nAlright! The secret word contains the letter " << guess << std::endl << std::endl;
}

bool Hangman::win(const std::string &secretWord, const std::map<char, bool> &guessed) {
	for (char c : secretWord) {
		if (!(guessed.find(c) != guessed.end())) {
			return false;
		}
	}
	return true;
}

bool Hangman::hanged(int errorCount) {
	return errorCount >= MAX_TRIES;
}

void Hangman::hangmanGame(const std::vector<std::string> &words) {
	std::string secretWord = Hangman::chooseSecretWord(words);
	// dictionary structure for storing keys and values, used here to verify if a letter was already guessed
	std::map<char, bool> guessed;
	std::vector<char> errors;

	do {
		// TODO: clear screen
		Hangman::printGame(secretWord, guessed, errors);
		Hangman::guess(secretWord, guessed, errors);
	} while (!(Hangman::win(secretWord, guessed) || Hangman::hanged((int) errors.size())));

	// printing game one more time
	Hangman::printGame(secretWord, guessed, errors);

	if (Hangman::hanged((int) errors.size())) {
		Hangman::printHanged();
	} else {
		Hangman::printWin();
		if (errors.empty()) {
			std::cout << "FLAWLESS VICTORY!" << std::endl;
		}
	}
	std::cout << "\nThe secret word was -> " << secretWord << " <-\n" << std::endl;
}
