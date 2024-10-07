#pragma once
#define WORDS_FILE_NAME "words.txt"

#include <string>
#include <vector>

namespace Hangman
{
	/**
	* Retrieves all words available for the game.
	* Terminates program execution in case of error.
	*
	* @returns a vector of strings
	*/
	std::vector<std::string> getWords();

	/**
	* Overwrites the available words with the content from the vector of strings passed as argument.
	* Terminates program execution in case of error.
	*
	* @param words the new list of words available for the game
	*/
	void writeFile(const std::vector<std::string> &words);
}
