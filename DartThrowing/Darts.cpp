#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>
#define SleepSec std::this_thread::sleep_for(std::chrono::milliseconds(500))

using namespace std;

class Player {
public:
	double Darts_thrown = 0;
	double Bulls_hit = 0;
	int Hit_Chance = 0;
};


bool Throw() {
	srand(time(0));
	int roll = 0;
	roll = rand() % 100 + 1;
	if (roll >= 70) {
		roll = 0;
		return true;
	}
	else if (roll < 70) {
		roll = 0;
		return false;
	}
}

double Simulate(int NumOfSimulate) {
	Player a;
	bool sim_result;
	double calc_result;
	do {
		SleepSec;
		sim_result = Throw();
		if (sim_result == true) {
			a.Bulls_hit = a.Bulls_hit + 1;
			a.Darts_thrown = a.Darts_thrown + 1;
		}
		else if (sim_result == false) {
			a.Darts_thrown = a.Darts_thrown + 1;
		}
		NumOfSimulate = NumOfSimulate - 1;
	} while (NumOfSimulate > 0);
	if (a.Bulls_hit == 0) {
		return 0;
	}
	else {
		calc_result = a.Darts_thrown / a.Bulls_hit;
		return calc_result;
	}
}

int main() {
	Player Joe;
	Player Sid;
	bool Throwing;
	int Choice;
	double sim_results;


	cout << "Simulating.. Please wait..." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	system("CLS");


	do {
		SleepSec;
		Throwing = Throw();
		if (Throwing == true){
			Joe.Bulls_hit = Joe.Bulls_hit + 1;
			Joe.Darts_thrown = Joe.Darts_thrown + 1;
		}
		else if (Throwing == false) {
			Joe.Darts_thrown = Joe.Darts_thrown + 1;
		}
	} while (Joe.Bulls_hit < 10);
	cout << "It took " << Joe.Darts_thrown << " Throws to hit the bull 10 times" << endl;


	cout << "Would you like to simulate a game? If so, please enter a number, if not: please enter 0." << endl;
	cin >> Choice;
	if (Choice > 0) {
		sim_results = Simulate(Choice);
		cout << sim_results << endl;
	}


	return 0;
}
