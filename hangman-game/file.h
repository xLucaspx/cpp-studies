#ifndef HANGMAN_GAME_FILE_H
#define HANGMAN_GAME_FILE_H

#define WORDS_FILE_NAME "words.txt"

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
void writeFile(std::vector<std::string> &words);

#endif //HANGMAN_GAME_FILE_H
