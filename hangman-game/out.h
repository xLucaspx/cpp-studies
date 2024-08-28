#ifndef HANGMAN_GAME_OUT_H
#define HANGMAN_GAME_OUT_H

/**
 * Prints the game header.
 */
void printHeader();

/**
 * Prints the game menu options.
 */
void printMenu();

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
void printSecretWord(std::string &word, std::map<char, bool> &guesses);

/**
 * Prints all the wrong guesses passed as argument
 *
 * @param errors the vector containing the wrong guesses
 */
void printWrongGuesses(std::vector<char> &errors);

/**
 * Calls on other procedures to draw rhe game.
 *
 * @param word the secret word
 * @param guesses map containing, for each letter, a <code>boolean</code> value for guessed
 * (<code>true</code> for guessed letters, <code>false</code> otherwise)
 * @param errors the vector containing the wrong guesses
 */
void printGame(std::string &word, std::map<char, bool> &guesses, std::vector<char> &errors);

/**
 * Procedure for printing a lost game message.
 */
void printHanged();

/**
 * Procedure for printing a game win message.
 */
void printWin();

#endif //HANGMAN_GAME_OUT_H
