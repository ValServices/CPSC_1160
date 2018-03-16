/**
Name: Madison (Hadfield) Valentine
Student Number: 100287346

Program Name: ExpEqu_A1.cpp
Program Description:
   This program asks for user input for a, b, c, and d of equation (ax+by)(cx +dy).
   This program then expands the equation  so that is displays  (a*c)x2+(a*d+b*c)*xy+(b*d)y2, 
      with the appropriate variables calculated based on user input.
      
Sources:
   Topics covered in 1160
   TutorialsPoint "Learn C++"  https://www.tutorialspoint.com/cplusplus
   cplusplus.com Tutorials

Features: 
   This program does not allow non-integer input for the a, b, c, or d inputs and instead reprompts. 
   This program does not allow non 'y' or 'n' input for the continue input and instead reprompts.

Errors:
   I revised my code so that non-integer variables as in input would reprompt the user.
   On console this automatically reprompts, however on SciTE you need to push enter after the "invalid" message.

*/

#include <iostream>
#include <string>
using namespace std;


//I made a lot of methods... 
void getCoeff(int *userDig, const int USER_SIZE);
void coeffNotValid();
void calcCoeff(int *coeff, const int *userDig);
void displayEqu(int *coeff, int COEFF_SIZE); //coeff can't be constant to be passed
int printNumber(int curPos, int hasPrin, int *coeff,  int COEFF_SIZE); //coeff can't be constant to be passed
void ifNone(int curPos, int hasPrin, const int *coeff, int COEFF_SIZE);
int printSingle(int hasPrin, int curPos);
int printTogether(int curPos, int hasPrin, const int *coeff); 
void printSpace(int hasPrin);
void printSpace(int hasPrin, int coeffVar);
void printText(int curPos);
char timeToStop();



//Input: int userDig[] -> array for user's entered digits, const int USER_SIZE -> the length of the array
//Output:  saves input of user to array
//Purpose: Get input from user and store in array that can be accessed by main. 
void getCoeff(int *userDig, const int USER_SIZE) {
   cout << "\n\nGive the a, b, c, and d for the equation (ax + by)*(cx + dy):" << endl; 
   int i = 0;
   
   while (i < USER_SIZE){
      cin >> userDig[i];
      
      while(!cin){
         coeffNotValid();
         cin >> userDig[i];
      }
      
      i++;
   }
   
   cout << endl;
}

//Input: none
//Output: Void 
//Purpose: Warns user and cleans the input area to prevent invalid input
void coeffNotValid(){
   cout << "\n\nPlease enter integers only.\n\nIf you are executing this in SciTE press enter to continue.";
   cin.clear();
   cin.ignore(999,'\n');
   cout << "\nGive the a, b, c, and d for the equation (ax + by)*(cx + dy):" << endl;
}

   

//Input: Int coeff[] -> array for calculated expanded equation coefficients, const int userDig[] -> input array of user's entered digits
//Output:  Saves calculations for coefficients to int coeff[] 
//Purpose: Calculates coefficients for the expanded equation
void calcCoeff(int *coeff, const int *userDig) {
   coeff[0] = userDig[0]*userDig[2];
   coeff[1] = ((userDig[0]*userDig[3]) + (userDig[1]*userDig[2]));
   coeff[2] = userDig[1]*userDig[3];
}


//Input:  Int coeff[] -> array of expanded coefficients, int COEFF_SIZE -> preset constant of array size
//Output:  Void
//Purpose: Calls other functions to display the equation by circling through x possibilites and passing on the values.
void displayEqu(int *coeff, int COEFF_SIZE){ //I couldn't set coeff as a constant if it was being passed on 
   int curPos = 0;
   int hasPrin = 0;
   
   while (curPos < COEFF_SIZE) {
      hasPrin = printNumber(curPos, hasPrin, coeff, COEFF_SIZE);
      curPos++;
   }
}


//Input: Int curPos - current place in array, int hasPrin - if there is a previously printed coefficient, int coeff[] - array of expanded coefficients, int COEFF_SIZE -> size of array
//Output: Returns if it has printed anything
//Purpose:  Calls functions to print equation sections based on curent position in the array  
int printNumber(int curPos, int hasPrin, int *coeff, int COEFF_SIZE){
   
   if (coeff[curPos] == 1) {
      hasPrin += printSingle(hasPrin, curPos);
      
   } else if (coeff[curPos] != 0){
      hasPrin += printTogether(curPos, hasPrin, coeff);
      
   } else {
      ifNone(curPos, hasPrin, coeff, COEFF_SIZE);
   }
   
   return hasPrin;
}


//Input: int curPos -> current place in array, int hasPrin -> if there is a previously printed coefficient, const int coeff[] -> array of expanded coefficient values, int COEFF_SIZE -> size of array
//Output: Void, prints a line if there was nothing printed.
//Purpose: If nothing was printing the whole equation (all inputs were 0), print 0
void ifNone(int curPos, int hasPrin, const int *coeff, int COEFF_SIZE){//not passing coeff, is fine as const
   
   if ((curPos == (COEFF_SIZE - 1)) && (hasPrin == 0) && (coeff[curPos] == 0)){
      cout << 0 << endl;
   }
}



//Inputs: int curPos - current place in array, int hasPrin - if a previous coefficient has printed,
//Output:  int hasPrin -> indicates that it has printed something to console
//Purpose: if the coefficient is 1, print just the text value
int printSingle(int hasPrin, int curPos){
   printSpace(hasPrin);
   printText(curPos);
   
   return hasPrin += 1;
}


//Inputs: Int curPos - current place in array, int hasPrin -  if a previous coefficient has printed, const int coeff[] - array of expanded coefficients
//Output:  Returns if it has printed, prints text
//Purpose: Prints the coefficient and the text value together
int printTogether(int curPos, int hasPrin, const int *coeff) { //not passing coeff, fine as const
   printSpace(hasPrin, coeff[curPos]);
   
   cout << coeff[curPos];
   printText(curPos);
   
   return hasPrin += 1;
}


//Input: Int hasPrin  - if any previous coefficient has printed
//Output: Text: a plus sign if the previous thing as printed
//Purpose: Add the plus sign between the sections of text to be printed. 
void printSpace(int hasPrin){
   if(hasPrin > 0){
      cout << "+";
   }  
}

//Input: Int hasPrin  - if any previous coefficient has printed, int coeffVar -> current coefficient value. 
//Output:  Text: a plus sign if the previous thing as printed and the next thing to print is not negative
//Purpose: Add the plus sign between the sections of text to be printed. 
void printSpace(int hasPrin, int coeffVar){
   if(hasPrin > 0 && coeffVar > 0){
      cout << "+";
   }  
}


//Input: Int curPos - current place in array
//Output:  Text: prints individual section of equation x + y values based on current position in coefficient array
//Purpose: To print the text parts needed for the equation. 
void printText(int curPos){
   const string textParts[3] = {"x^2", "xy", "y^2\n"}; //so no one can accidentally break it I guess?
   cout << textParts[curPos];
}

//Input: User text to console
//Output: char ans -> user response of 'y' or 'n'
//Purpose: To get text for user if the program should continue or not, and reprompt for text that is not y or n
char  timeToStop(){
	char ans;
	cout << "\nWould you like to continue? y = yes, n = no: \n";
 	cin.clear();
	cin >> ans;

	while(!cin || (ans != 'y' && ans != 'n' )){
		cout << "Not a valid character. Try again." << endl;
		ans = timeToStop();
	}
	return ans;
}


//Input: gets input from user
//Output: outputs users input as expanded equation
//Purpose: executes functions to get user input for factored equation and display expanded equation
int main () { 
   const int USER_SIZE = 4;
   const int COEFF_SIZE = 3;
   int coeff[COEFF_SIZE]; 
   int userDig[USER_SIZE];
   char stop = 'n';
   
   do{
      getCoeff(userDig, USER_SIZE);
      calcCoeff(coeff, userDig);
      displayEqu(coeff, COEFF_SIZE);
      stop = timeToStop();
   } while(stop == 'y');
   
   return 0;
}

