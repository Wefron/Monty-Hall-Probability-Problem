// Dakota Maura

#include <iostream>
#include <ctime>
using namespace std;

void get_plr_choice(int &plr_choice);
void get_plr_switch(int choices[], int wrong_door, int change_door, int &plr_switch);

void display_win_percent(int total_tries, double total_wins);
void display_results(int plr_choice, int win_door, double &total_wins);

double calculate_win_percent(double wins, int attempts);
void pause();

int main() {
	int plr_choice = 0;
	int plr_switch;
	int choices[3] = { 1, 2, 3 };
	double plr_wins = 0;
	srand(time(NULL));
	
	// Go through 10 iterations to determine probability
	for (int i = 0; i < 10; i++) {
		
		display_win_percent(i, plr_wins);
		get_plr_choice(plr_choice);
		
		// Generate the winning door
		int win_door = rand() % 3 + 1;

		// Find a door that is not the winning door and not the chosen door to reveal
		for (int wrong_door = 0; wrong_door < 3; wrong_door++) {
			if (choices[wrong_door] != win_door && choices[wrong_door] != plr_choice) {

				// Find a door that is not the revealed door and not the players door to switch to
				for (int change_door = 0; change_door < 3; change_door++) {
					if (choices[change_door] != choices[wrong_door] && choices[change_door] != plr_choice) {

						get_plr_switch(choices, wrong_door, change_door, plr_switch);

						if (plr_switch) {
							plr_choice = choices[change_door];
						}

						break;
					}
				}

				break;
			}
		}

		display_results(plr_choice, win_door, plr_wins);

		pause();
		system("CLS");
	}

	cout << "Your final win percentage is " << calculate_win_percent(plr_wins, 10) << "%" << endl << endl;
	pause();
	return 0;
}

void get_plr_choice(int &plr_choice) {
	cout << "Pick a door (1-3): ";
	while (!(cin >> plr_choice) || !(plr_choice > 0 && plr_choice < 4)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void get_plr_switch(int choices[], int wrong_door, int change_door, int &plr_switch) {
	cout << "Door " << choices[wrong_door] << " contains a goat. Would you like to switch to door " << choices[change_door] << " (Yes: 1 or No: 0)? ";
	while (!(cin >> plr_switch) || (plr_switch != 0 && plr_switch != 1)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}


void display_win_percent(int total_tries, double total_wins) {
	if (total_tries != 0) {
		cout << "Overall win percentage: " << calculate_win_percent(total_wins, total_tries) << endl;
	}
}


void display_results(int plr_choice, int win_door, double &total_wins) {
	if (plr_choice == win_door) {
		cout << "Congrats you chose the right door!" << endl << endl;
		total_wins += 1;
	}
	else {
		cout << "You chose the wrong door and got a goat...";
	}
}


double calculate_win_percent(double wins, int attempts) {
	return wins / attempts * 100;
}

void pause() {
	cout << "Press any key to continue . . .";
	getchar();
}