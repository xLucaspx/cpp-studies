#pragma once
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 20

#include <string>
#include <vector>

namespace Hangman {
	/**
	 * Reads the word typed by the user, validates it (only letters, length between <code>MIN_WORD_LENGTH</code>
	 * and <code>MAX_WORD_LENGTH</code> constants), ensures uppercase, check if it doesn't already exist in the
	 * word list and, if it's valid, adds it to the <code>words</code> vector and calls on the <code>writeFile</code>
	 * function passing the vector as argument.
	 *
	 * @param words vector containing all available words; if the user types in a valid word, it will be added to
	 * the vector.
	 */
	void addWord(std::vector<std::string> &words);

	/**
	 * Initialize and run the application.
	 */
	void run();
}
