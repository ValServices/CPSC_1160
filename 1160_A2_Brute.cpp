/**
* Purpose of program: calculates the probability (prob) that two people in the same room will have the same birthday, 
*                                        based on the number of people (numP) in the room. 
*
* Created for CPSC 1160, Assignment 2
* Created on 17/01/2018
*  
* Author: Madison (Hadfield) Valentine
* Student Number: 100287346
*
*
* The smallest value of numP such that prob = 0.5 is 23 on average. 
*
*/

#include <iostream>
#include <time.h>
using namespace std;

void getBdays(int bdays[], int numP);
int compareBdays(const int bdays[], int numP);
int runTrial(const int numP);
int runTrials(int numP, int TIMES);
void getProb(int TIMES, int matches, int numP);
int getTrialNum();
int getStartNum();
int getRange(int num);
int invalidTrialCheck();
int invalidStartNum();
int getRangeErr(int num);


//generates birthdays for each element in the list
//inputs: int bdays[] array, int numP - number of elements in array
//outputs: generated birthdays to array
void getBdays(int bdays[], int numP){
	for(int i = 0; i < numP; i++){
		bdays[i] = rand()%365; 
	}
}


//compares bdays in the array and returns 1 if there is a match 
//inputs: const int bdays[] array of all bdays, int numP of length of array
//outputs: returns 1 if there is a match, 0 if there is not
int compareBdays(const int bdays[], int numP){

	for(int fPerson = 0; fPerson < numP; fPerson++){
		for(int oPerson = fPerson + 1; oPerson < numP; oPerson++){
			if(bdays[fPerson] == bdays[oPerson]){
				return 1;
			}
		}
	}
	

	return 0;
}


//Runs an individual trial, and returns whether there was a match 
//Inputs: const numP - number of people to run the trial for
//Output: returns 1 if the trial had a matching bday, 0 if not
int runTrial(const int numP){
	int* bdays = new int[numP];
	getBdays(bdays, numP);

	return compareBdays(bdays, numP);

}


//Runs as many trials as specified and returns the number of matches out of those trials. 
//Inputs: int numP - number of people to run in each trial, double times - the number of times to run the trial
//Output: Int matches - how many of the trials had matches
int runTrials(const int numP, int TIMES){
	int matches = 0;

	for(int trialCount = 0; trialCount <= TIMES; trialCount++){
		matches += runTrial(numP);
	
	}
	
	return matches;
}


//Finds the probability and prints it to the screen, along with the number of times, matches, and people in the trial
//Inputs: double matches - number of times there was matches in the trial, double times - number of times trial was executed,
//		  int numP - number of people in the trial
//Outputs: None, to console only
void getProb(double matches, double TIMES, int numP){
	double prob =  (matches / TIMES);
	string sProb = to_string(prob);
	string numberP = to_string(numP);

	cout << "For " << TIMES << " times, the probability was " << sProb << " for " << numberP << " people." << endl;
}


int getTrialNum(){
	int n;

	cout << "Please enter the number of trials (must be 3000 or higher): ";
	try {
		cin.clear();
		cin >> n; 
	} catch(...){
		n = invalidTrialCheck();
	}
	cout << endl;

	if (n < 3000){
		n = invalidTrialCheck();
	}

	return n;
}

int invalidTrialCheck(){
	cout << "That is not a valid number. The number of trials must be 3000 or greater." << endl;
	int n = getTrialNum();
	

	return n;
}

int getStartNum(){
	int n;
	cout << "Please enter a starting number of people (2 or more): ";
	
	try {
		cin.clear();
		cin >> n;
	} catch(...){
		n = invalidStartNum();
	}

	if(n < 2){
		n = invalidStartNum();
	}

	return n;
}

int invalidStartNum(){
	cout << "That is not a valid number. The number of people must be 2 or greater. Please press enter first. " << endl;
	return getStartNum();


}

int getRange(int num){
	int get;
	cout << "What would you like the range to be? ";
	try {
		cin >> get;
	} catch(...){
		get = getRangeErr(num);
	}

	if(get < 1){
		get = getRangeErr(num);
	}

	return (get + num);

}


int getRangeErr(int num){
	cout << "Error. Your range needs to be 1 or higher." << endl;
	return getRange(num);

}
//Calls other methods to get the probability of there being a matching birthday in a room with int n people with TIMES trials
//Displays output to console
int main() {
	double matches = 0;
	int times;
	int numP;
	int numPMax; 
	srand(time(0));

	times = getTrialNum();
	numP = getStartNum();
	numPMax = getRange(numP);


	while(numP < numPMax){
		matches = runTrials(numP, times);
		
		getProb((double)matches, (double)times, numP);	
		numP++;	
	}
	 
}