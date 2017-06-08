#include <iostream>
using namespace std;


//Justin Schieck
//200328630
//Might put some serious validation in if bored.

//variables
double amps = 3.5;
double lightAmp = 4.0;

//structures
struct battery_t {
	double voltage;
	double MaxStored;
	double currentLevel;
};

//Function Declaration
double powerDevice(battery_t);
int max_time(battery_t, double);
double recharge(battery_t, int);

//functions
double powerDevice(battery_t battery, int seconds) {

	double totalReserve;

	if (battery.MaxStored <= 0.00) {
		cout << "Battery amount is insufficient.. Please Charge" << endl; 
	}
	else {
		totalReserve = battery.currentLevel - (lightAmp * seconds);
	}
	return totalReserve;
}

int max_time(battery_t battery, double current) {

	int noOfSec;

	noOfSec = battery.currentLevel / current;

	return noOfSec;

}

double recharge(battery_t battery, int timeInSec) {

	double maxCap;
	double watts;
	int joules;


	watts = battery.voltage * amps;

	maxCap = watts * timeInSec;

	return maxCap;

	//watts = 
	
	//maxCap = battery.currentLevel + (watts * joules);

}

void main() {
	
	battery_t battery;
	int timePowered;
	int chargeTime;

	battery.voltage = 12.0;
	battery.MaxStored = 5 * pow(10,6);
	battery.currentLevel = battery.MaxStored;
	
	//2.1 Power light
	battery.currentLevel = powerDevice(battery, 900);
	cout << "The batterys current level is :  " <<  battery.currentLevel<< endl;
	//2.2 remaining
	timePowered = max_time(battery, 8);
	cout << "The device was powered for " << timePowered << endl;
	//2.3 recharge
	cout << "please enter a time in seconds to charge for :" << endl;
	cin >> chargeTime;
	battery.currentLevel = recharge(battery, chargeTime);
	cout << "Battery recharged" << endl;
	//2.4 recalculate how long it could operate
	timePowered = max_time(battery, 8);
	cout << "The device was powered for " << timePowered << endl;

	system("pause");
	
}