#pragma once
#define MAX_TRIES 6

#include <map>
#include <string>
#include <vector>

namespace Hangman {
	/**
	* Choose a random word from the vector of strings passed as argument.
	*
	* @param words a vector of strings containing the available words
	* @return a random string selected from the words vector
	*/
	std::string chooseSecretWord(const std::vector<std::string> &words);

	/**
	* Checks if a string contains the char passed as argument
	*
	* @param s <em>haystack</em>; the string in which to look for the char
	* @param element <em>needle</em>; the element being searched for in the string
	* @return <code>true</code> if the string contains the char passed as argument, <code>false</code> otherwise
	*/
	bool stringContains(const std::string &s, char element);

	/**
	* Procedure that asks the player for it's guess, validates it and updates the game current state by
	* manipulating the references passed as argument.
	*
	* @param word the secret word, used here to check if the player's guess is correct
	* @param guessed map containing already guessed letters, used to keep track of guesses; may be updated
	* with the new guess
	* @param errors vector of chars containing all wrong guesses; may be updated if the new guess is incorrect
	*/
	void guess(const std::string &word, std::map<char, bool> &guessed, std::vector<char> &errors);

	/**
	* Function that determines if the game was won by checking if all the letters from
	* the secret word were guessed.
	*
	* @param secretWord the secret word of the current round
	* @param guessed map containing all guesses; for each letter, contains a boolean value
	* (<code>true</code> for guessed letters, <code>false</code> otherwise)
	* @return <code>true</code> if the player won (i.e. all letters from the secret word were guessed),
	* <code>false</code> otherwise
	*/
	bool win(const std::string &secretWord, const std::map<char, bool> &guessed);

	/**
	* Function that determines if the game was lost by checking if the number of errors
	* exceeds the number of allowed tries, defined by <code>MAX_TRIES</code>.
	*
	* @param errorCount total wrong guesses
	* @return <code>true</code> if the player lost (i.e. the number of error is GTE the number of tries),
	* <code>false</code> otherwise
	*/
	bool hanged(int errorCount);

	/**
	* Runs one round of the hangman game; lasts until the player wins or gets hanged.
	*
	* @param words vector of strings containing all available words; this procedure is
	* going to choose one of them to be the secret word of the round
	*/
	void hangmanGame(const std::vector<std::string> &words);
}
