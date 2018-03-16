#include <iostream>
using namespace std;

string getInput();
string toUpper(string inp, int counter);
string makeString(string in, int ascii);
bool isInUserString(string in, char ascii, int count);


int main() {

	string inp = getInput();
   char start = '0';
   string asc = makeString(inp, start);
   
   cout << asc << endl;

	return 0;
}

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