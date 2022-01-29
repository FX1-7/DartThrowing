#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#define Sleep2Sec std::this_thread::sleep_for(std::chrono::milliseconds(2000))

using namespace std;

class Joe {
public:
	int Darts_thrown = 0;
	int Bulls_hit = 0;
};


int main() {
	srand(time(0));
	int counter = 0;
	int roll = 0;
	Joe a;
	Joe b;
	do {
		roll = rand() % 100 + 1;
		if (roll >= 70) {
			cout << "Joe has hit the bull!" << endl;
			a.Bulls_hit = a.Bulls_hit + 1;
		}
	} while (a.Bulls_hit < 10);
}
