#include <iostream>
using namespace std;

string getInput();
void toUpper(string &inp, int counter);
string makeString(string in, char ascii);
bool isInUserString(string in, char ascii, int count);

int main() {
	string inp = getInput();
   string asc = makeString(inp, '0');
   
   cout << asc << endl;
	return 0;
}

string getInput(){
	string inputStr = "";

	cout << "Enter in a string: ";
	cin >> inputStr;
	cout << endl;
   
   toUpper(inputStr, 0);
	return inputStr;
}

void toUpper(string &inp, int counter){
   if(counter >= (int)inp.length()){
      return;
   }
   
   if(isalpha(inp[counter]) && islower(inp[counter])){
      inp[counter] = toupper(inp[counter]);
   }
   
   toUpper(inp, counter+1);
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
   } else {
       return isInUserString(in, ascii, count+1);
   }
   
   return false;
}