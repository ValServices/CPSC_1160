/**
*CPSC 1160 - Assignment 4 
*Author: Madison (Hadfield) Valentine
*Date: January 17th 2018
*
*This program takes a string of input from the user, 
*and outputs the alphanumeric characters in order from 0-9A-Z
*/

#include <iostream>
using namespace std;

string getInput();
string toUpper(string inp, int counter);
string makeString(string in, int ascii);
bool isInUserString(string in, char ascii, int count);

//gets input from user
//converts string to 0-9A-Z once based on what characters are in user string
//outputs new string
int main() {

	string inp = getInput();
   char start = '0';
   string asc = makeString(inp, start);
   
   cout << asc << endl;

	return 0;
}

//gets input from the user 
//@param none
//@return string of input
string getInput(){
	//get input from user
	//get string length

	string inputStr = "";

	cout << "Enter in a string: ";
	cin >> inputStr;
	cout << endl;
   
   inputStr = toUpper(inputStr, '0');

	return inputStr;

}

//coverts all lower case characters in the string to uppercase
//@param string input, int counter
//@returns string of converted input
string toUpper(string inp, int counter){
   int length = inp.length();
   
   if(counter >= length){
      return inp;
   }
   
   if(isalpha(inp[counter]) && islower(inp[counter])){
      inp[counter] = toupper(inp[counter]);
   }
   
   toUpper(inp, counter+1);
   
   return inp;
   
}

//creates a new string from an old one with the new one being from 0-9A-Z 
//based on what ever was in the original string
//@param string input, char ascii 
//@returns finished string with 0-9A-Z
string makeString(string in, char ascii){
   string asc = "";
   
   if(ascii > 'Z'){
      return asc;
   }
   
   if(isInUserString(in, ascii, 0)){
      asc += ascii;
   }
   
   if(ascii == '9'){
      ascii = 'A';
   } else {
      ascii++;
   }
   
   asc += makeString(in, ascii);
   
   return asc;

}

//Checks if the current ascii digit is in the user string
//@params string input, char ascii - current ascii char, int count 
//@return true if it is, false if it's not 
bool isInUserString(string in, char ascii, int count){
   
   if(count >= (int)in.length() || count < 0){
      return false;
   }
   
   char test = in[count];
   
   if(test == ascii){
      return true;
   }
   
   isInUserString(in, ascii, count+1);
   
   return false;
}