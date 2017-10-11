// Dakota Maura

#include <iostream>
#include <ctime>
using namespace std;

int main() {
	int plr_choice = 0;
	int plr_switch = 0;
	int choices[3] = { 1, 2, 3 };
	double plr_wins = 0;
	bool loop = true;
	srand(time(NULL));
	
	for (int i = 0; i < 10; i++) {
		if (i != 0) {
			cout << "Overall win percentage: " << plr_wins / i * 100 << endl;
		}
		int win_door = rand() % 3 + 1;

		cout << "Pick a door (1-3): ";

		while (!(cin >> plr_choice) && loop) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			for (int i = 0; i < 3; i++) {
				if (choices[i] == plr_choice) {
					loop = false;
					break;
				}
			}
		} 

		for (int wrong_door = 0; wrong_door < 3; wrong_door++) {
			if (choices[wrong_door] != win_door && choices[wrong_door] != plr_choice) {

				for (int change_door = 0; change_door < 3; change_door++) {
					if (choices[change_door] != choices[wrong_door] && choices[change_door] != plr_choice) {

						cout << "The door " << choices[wrong_door] << " contains a goat. Would you like to switch to door " << choices[change_door] << " (Yes: 1 or No: 0)? ";
						do {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cin >> plr_switch;
						} while (plr_switch != 0 && plr_switch != 1);

						if (plr_switch) {
							plr_choice = choices[change_door];
						}

						break;
					}
				}

				break;
			}
		}

		if (plr_choice == win_door) {
			cout << "Congrats you chose the right door!" << endl << endl;
			plr_wins += 1;
		}
		else {
			cout << "You chose the wrong door and got a goat...";
		}
		
		if (i == 10) {
			cout << "Your final win percentage is " << plr_wins / i << "%";
		}

		cout << "Press any key to continue . . .";
		getchar();
		system("CLS");

	}

	cout << "Press any key to exit . . .";
	getchar();
	return 0;
}