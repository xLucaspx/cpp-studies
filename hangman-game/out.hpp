#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace Hangman {
	/**
	* Prints the game header.
	*/
	inline void printHeader() {
		std::cout << "  _______ " << std::endl;
		std::cout << " |/      |" << std::endl;
		std::cout << " |" << std::endl;
		std::cout << " |   THE HANGMAN" << std::endl;
		std::cout << " |      GAME" << std::endl;
		std::cout << " |" << std::endl;
		std::cout << " |" << std::endl;
		std::cout << "_|___\n" << std::endl;
	}

	/**
	* Prints the game menu options.
	*/
	inline void printMenu() {
		std::cout << "-- MENU --\n" << std::endl;
		std::cout << "[1] Play game" << std::endl;
		std::cout << "[2] Add word\n" << std::endl;
	}

	/**
	* Procedure for printing a lost game message.
	*/
	inline void printHanged() {
		std::cout << "      _______________" << std::endl;
		std::cout << "     /               \\" << std::endl;
		std::cout << "    /                 \\" << std::endl;
		std::cout << "  //                   \\/\\" << std::endl;
		std::cout << "  \\|    XXX      XXX    | /" << std::endl;
		std::cout << "   |   XXX      XXX    |/" << std::endl;
		std::cout << "   |    XXX      XXX   |" << std::endl;
		std::cout << "   |                   |" << std::endl;
		std::cout << "   \\__      XXX      __/" << std::endl;
		std::cout << "     |\\     XXX     /|" << std::endl;
		std::cout << "     | |           | |" << std::endl;
		std::cout << "     | I I I I I I I |" << std::endl;
		std::cout << "     |  I I I I I I  |" << std::endl;
		std::cout << "     \\_             _/" << std::endl;
		std::cout << "       \\_         _/" << std::endl;
		std::cout << "         \\_______/\n" << std::endl;
		std::cout << "Sorry, you were hanged..." << std::endl;
	}

	/**
	* Procedure for printing a game win message.
	*/
	inline void printWin() {
		std::cout << "       ___________" << std::endl;
		std::cout << "      '._==_==_=_.'" << std::endl;
		std::cout << "      .-\\:      /-." << std::endl;
		std::cout << "     | (|:.     |) |" << std::endl;
		std::cout << "      '-|:.     |-'" << std::endl;
		std::cout << "        \\::.    /" << std::endl;
		std::cout << "         '::. .'" << std::endl;
		std::cout << "           ) (" << std::endl;
		std::cout << "         _.' '._" << std::endl;
		std::cout << "        '-------'\n" << std::endl;
		std::cout << "Congratulations, you won!" << std::endl;
	}

	/**
	* Draws the gibbet according to the error count passed as argument, following the rules:
	*
	* <table>
	* 	<thead>
	* 		<tr>
	* 			<th>Error count</th>
	* 			<th>Body part</th>
	* 		</tr>
	* 	</thead>
	* 	<tbody>
	* 		<tr>
	* 			<td>0</td>
	* 			<td>none</td>
	* 		</tr>
	*  	<tr>
	*  		<td>1</td>
	*  		<td>head</td>
	*  	</tr>
	* 		<tr>
	* 			<td>2</td>
	* 			<td>body</td>
	* 		</tr>
	* 		<tr>
	* 			<td>3</td>
	* 			<td>left arm</td>
	* 		</tr>
	* 		<tr>
	* 			<td>4</td>
	* 			<td>right arm</td>
	* 		</tr>
	* 		<tr>
	* 			<td>5</td>
	* 			<td>left leg</td>
	* 		</tr>
	* 		<tr>
	* 			<td>6</td>
	* 			<td>right leg</td>
	* 		</tr>
	* 	</tbody>
	* </table>
	*
	* @param errorCount total wrong guesses
	*/
	void printGibbet(int errorCount);

	/**
	* Prints the secret word with underscores replacing non guessed letters.
	*
	* @param word the secret word
	* @param guesses map containing, for each letter, a <code>boolean</code> value for guessed
	* (<code>true</code> for guessed letters, <code>false</code> otherwise)
	*/
	void printSecretWord(const std::string &word, const std::map<char, bool> &guesses);

	/**
	* Prints all the wrong guesses passed as argument
	*
	* @param errors the vector containing the wrong guesses
	*/
	void printWrongGuesses(const std::vector<char> &errors);

	/**
	* Calls on other procedures to draw rhe game.
	*
	* @param word the secret word
	* @param guesses map containing, for each letter, a <code>boolean</code> value for guessed
	* (<code>true</code> for guessed letters, <code>false</code> otherwise)
	* @param errors the vector containing the wrong guesses
	*/
	void printGame(const std::string &word, const std::map<char, bool> &guesses, const std::vector<char> &errors);
}
