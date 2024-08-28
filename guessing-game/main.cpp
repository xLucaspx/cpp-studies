#include <iostream> // input/output

using namespace std; // so that we don't have to call std functions with std::

#define EASY 1
#define EASY_TRIES 15
#define MEDIUM 2
#define MEDIUM_TRIES 10
#define HARD 3
#define HARD_TRIES 5

int main() {
	cout << "****************************************************" << endl;
	cout << "*   _____   _     _   _______    ______    ______  *" << endl;
	cout << "*  / ____| | |   | | | ______|  / _____|  / _____| *" << endl;
	cout << "* | |  __  | |   | | | |___    |  (____  |  (____  *" << endl;
	cout << "* | | |_ | | |   | | | ____|    \\____  \\  \\____  \\ *" << endl;
	cout << "* | |__| | | |___| | | |_____   _____) |  _____) | *" << endl;
	cout << "*  \\_____|  \\_____/  |_______| |_______/ |_______/ *" << endl;
	cout << "*                                                  *" << endl;
	cout << "****************************************************" << endl;
	cout << "Guess the secret number between 1 and 99!" << endl;

	cout << "\nDifficulty level" << endl;
	cout << "[" << EASY << "] Easy (" << EASY_TRIES << " tries)" << endl;
	cout << "[" << MEDIUM << "] Medium (" << MEDIUM_TRIES << " tries)" << endl;
	cout << "[" << HARD << "] Hard (" << HARD_TRIES << " tries)" << endl;
	cout << "Choose... ";

	int difficulty;
	int tries;
	cin >> difficulty;

	switch (difficulty) {
		case EASY:
			tries = EASY_TRIES;
			break;
		case MEDIUM:
			tries = MEDIUM_TRIES;
			break;
		case HARD:
			tries = HARD_TRIES;
			break;
		case 42: // hidden option
			tries = 42;
			break;
		default:
			cout << "\nInvalid option!" << endl;
			tries = 0;
	}

	cout.precision(2);
	cout << fixed;

	srand(time(nullptr));
	const int SECRET_NUMBER = rand() % 100;

	int guess;
	double points = 1000.0;

	for (int i = 0; i < tries; i++) {
		cout << "\nTries: " << i + 1 << " of " << tries << endl;
		cout << "What's your guess? ";
		cin >> guess;

		if (guess <= 0 || guess >= 100) {
			cout << "Invalid value, type an integer number between 1 and 99" << endl;
			i--;
			continue;
		}

		if (guess == SECRET_NUMBER) {
			cout << "\nCongratulations, you've guessed the secret number in " << i + 1 << " tries!" << endl;
			cout << "Points: " << points << endl;
			break;
		}

		if (SECRET_NUMBER > guess) {
			cout << "The secret number is bigger than " << guess << endl;
		} else {
			cout << "The secret number is smaller than " << guess << endl;
		}

		double lostPoints = abs(SECRET_NUMBER - guess) / 2.0;
		points -= lostPoints;

		if (i == tries - 1) {
			cout << "\nYou lost...\nThe secret number was " << SECRET_NUMBER << endl;
			cout << "Points: " << points << endl;
		}
	}

	cout << "game over" << endl;

	return 0;
}
