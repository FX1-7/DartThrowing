#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>
#define SleepSec std::this_thread::sleep_for(std::chrono::milliseconds(500))

using namespace std;

class Player {
public:
	int Round_Darts_thrown = 0;
	int Total_Darts_thrown = 0;
	int Bulls_hit = 0;
	int Success_rate = 0;
	double Sim_Average = 0;

	bool Throw(int S_rate) {
		srand(time(0));
		int roll = 0;
		roll = rand() % 100 + 1;
		if (roll <= S_rate) {
			roll = 0;
			return true;
		}
		else {
			roll = 0;
			return false;
		}
	}
};


string Simulate(int NumOfSimulate) {
	Player Joe;
	Player Sid;
	Player func;
	string Winner;
	bool Throwing;
	do {
		do {
			SleepSec;
			Throwing = func.Throw(Joe.Success_rate);
			if (Throwing == true) {
				Joe.Bulls_hit = Joe.Bulls_hit + 1;
				Joe.Round_Darts_thrown = Joe.Round_Darts_thrown + 1;
			}
			else if (Throwing == false) {
				Joe.Round_Darts_thrown = Joe.Round_Darts_thrown + 1;
			}
		} while (Joe.Round_Darts_thrown != 3);
		cout << "Joe has thrown 3 darts and hit " << Joe.Bulls_hit << " bullseyes" << endl;
		Joe.Total_Darts_thrown = Joe.Total_Darts_thrown + Joe.Round_Darts_thrown;
		Joe.Round_Darts_thrown = 0;
			do {
				SleepSec;
				Throwing = func.Throw(Sid.Success_rate);
				if (Throwing == true) {
					Sid.Bulls_hit = Sid.Bulls_hit + 1;
					Sid.Round_Darts_thrown = Sid.Round_Darts_thrown + 1;
				}
				else if (Throwing == false) {
					Sid.Round_Darts_thrown = Sid.Round_Darts_thrown + 1;
				}
			} while (Sid.Round_Darts_thrown != 3);
			cout << "Sid has thrown 3 darts and hit " << Sid.Bulls_hit << " bullseyes" << endl;
			Sid.Total_Darts_thrown = Sid.Total_Darts_thrown + Sid.Round_Darts_thrown;
			Sid.Round_Darts_thrown = 0;
	} while (Sid.Bulls_hit < 10 || Joe.Bulls_hit < 10);

	if (Sid.Bulls_hit != 0 && Joe.Bulls_hit != 0) {
		Joe.Sim_Average = ((double) Joe.Total_Darts_thrown) / Joe.Bulls_hit;
		Sid.Sim_Average = ((double) Sid.Total_Darts_thrown) / Sid.Bulls_hit;
	}
	else {
		;
	}

	if (Sid.Bulls_hit > Joe.Bulls_hit) {
		Winner = "Sid";
	}
	else if (Joe.Bulls_hit > Sid.Bulls_hit) {
		Winner = "Joe";
	}
	else {
		Winner = "Tie";
	}
	return Winner;

}

int main() {
	Player Joe;
	Player Sid;
	Player func;
	string Winner;
	bool Throwing;
	int Choice;

	cout << "Please enter the Success Rate for Joe:" << endl;
	cin >> Joe.Success_rate;
	cout << endl << "Please enter the Success Rate for Sid:" << endl;
	cin >> Sid.Success_rate;

	cout << "Simulating.. Please wait..." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	system("CLS");

	do {
		do {
			SleepSec;
			Throwing = func.Throw(Joe.Success_rate);
			if (Throwing == true) {
				Joe.Bulls_hit = Joe.Bulls_hit + 1;
				Joe.Round_Darts_thrown = Joe.Round_Darts_thrown + 1;
			}
			else if (Throwing == false) {
				Joe.Round_Darts_thrown = Joe.Round_Darts_thrown + 1;
			}
		} while (Joe.Round_Darts_thrown != 3);
		cout << "Joe has thrown 3 darts and hit " << Joe.Bulls_hit << " bullseyes" << endl;
		Joe.Total_Darts_thrown = Joe.Total_Darts_thrown + Joe.Round_Darts_thrown;
		Joe.Round_Darts_thrown = 0;
		do {
			SleepSec;
			Throwing = func.Throw(Sid.Success_rate);
			if (Throwing == true) {
				Sid.Bulls_hit = Sid.Bulls_hit + 1;
				Sid.Round_Darts_thrown = Sid.Round_Darts_thrown + 1;
			}
			else if (Throwing == false) {
				Sid.Round_Darts_thrown = Sid.Round_Darts_thrown + 1;
			}
		} while (Sid.Round_Darts_thrown != 3);
		cout << "Sid has thrown 3 darts and hit " << Sid.Bulls_hit << " bullseyes in total" << endl;
		cout << "Next round!" << endl;
		cout << endl;
		Sid.Total_Darts_thrown = Sid.Total_Darts_thrown + Sid.Round_Darts_thrown;
		Sid.Round_Darts_thrown = 0;
	} while ((Sid.Bulls_hit < 10) || (Joe.Bulls_hit < 10));


	if (Sid.Bulls_hit > Joe.Bulls_hit) {
		Winner = "Sid";
	}
	else if (Joe.Bulls_hit > Sid.Bulls_hit) {
		Winner = "Joe";
	}
	else {
		Winner = "Tie";
	}
	
	cout << "The winner is " << Winner << endl;
	cout << "Would you like to simulate a game? If so, please enter a number, if not: please enter 0." << endl;
	cin >> Choice;
	if (Choice > 0) {
		Simulate(Choice);
		cout << "The average hit % of each person is as follows:" << endl;
		cout << "Joe: " << Joe.Sim_Average << "%" << endl;
		cout << "Sid: " << Sid.Sim_Average << "%" << endl;
	}


	return 0;
}
