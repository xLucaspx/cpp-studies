#include <format>
#include <iostream>
#include <regex>
#include "app.hpp"
#include "file.hpp"
#include "hangman.hpp"
#include "out.hpp"

void Hangman::addWord(std::vector<std::string> &words)
{
	std::cout << "Type in the new word: ";
	std::string newWord;
	std::cin >> newWord;

	constexpr int minLength = MIN_WORD_LENGTH;
	constexpr int maxLength = MAX_WORD_LENGTH;
	// ^[a-zA-Z]{3,20}$ {{ is the escape sequence and {} is where the args are going to be placed
	std::string newWordRegex = std::vformat("^[a-zA-Z]{{{},{}}}$", std::make_format_args(minLength, maxLength));
	if (!regex_match(newWord, std::regex(newWordRegex))) {
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
	Hangman::writeFile(words);
}

void Hangman::run()
{
	Hangman::printHeader();
	std::vector<std::string> words = Hangman::getWords();
	while (words.empty()) {
		std::cout << "There are no words available for playing...\nYou need to add at least one word!\n" << std::endl;
		Hangman::addWord(words);
	}

	bool run = true;

	do {
		Hangman::printMenu();
		std::cout << "Choose... ";
		int option;
		std::cin >> option;

		switch (option) {
			case 1:
				Hangman::hangmanGame(words);
				break;
			case 2:
				Hangman::addWord(words);
				break;
			default:
				run = false;
				break;
		}
	} while (run);

	std::cout << "\ngame over\n";
}
