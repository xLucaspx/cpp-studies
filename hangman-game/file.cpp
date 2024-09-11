#include <fstream>
#include <iostream>
#include "file.hpp"

std::vector<std::string> Hangman::getWords() {
	// input file stream
	std::ifstream file;
	file.open(WORDS_FILE_NAME);

	if (!file.is_open()) {
		std::cerr << "\nWord database unreachable!\n\nexecution terminated" << std::endl;
		exit(-1);
	}

	int wordCount;
	file >> wordCount;

	std::vector<std::string> words;

	for (int i = 0; i < wordCount; i++) {
		std::string word;
		file >> word;
		words.push_back(word);
	}

	file.close();
	return words;
}

void Hangman::writeFile(const std::vector<std::string> &words) {
	// output file stream
	std::ofstream file;
	file.open(WORDS_FILE_NAME);

	if (!file.is_open()) {
		std::cerr << "\nWord database unreachable!\n\nexecution terminated" << std::endl;
		exit(-1);
	}

	int wordCount = (int) words.size();
	file << wordCount << std::endl;

	for (const std::string &word : words) {
		file << word << std::endl;
	}

	file.close();
}
