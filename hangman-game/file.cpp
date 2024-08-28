#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "file.h"

using namespace std;

vector<string> getWords() {
	// input file stream
	ifstream file;
	file.open(WORDS_FILE_NAME);

	if (!file.is_open()) {
		cerr << "\nWord database unreachable!\n\nexecution terminated" << endl;
		exit(-1);
	}

	int wordCount;
	file >> wordCount;

	vector<string> words;

	for (int i = 0; i < wordCount; i++) {
		string word;
		file >> word;
		words.push_back(word);
	}

	file.close();
	return words;
}

void writeFile(vector<string> &words) {
	// output file stream
	ofstream file;
	file.open(WORDS_FILE_NAME);

	if (!file.is_open()) {
		cerr << "\nWord database unreachable!\n\nexecution terminated" << endl;
		exit(-1);
	}

	int wordCount = words.size();
	file << wordCount << endl;

	for (string word : words) {
		file << word << endl;
	}

	file.close();
}
