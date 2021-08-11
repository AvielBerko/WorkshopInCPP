// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 3, Question 4
// The program receives 4 words and messes with them (practices string)
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str); // receiving the 4 words
	int pos = str.find(" "); // finds the first space
	while (pos >= 0) { // while there are spaces found in the string
		str.replace(pos, 1, "*"); // replaces the space with '*'
		pos = str.find(" "); // finds the next space
	}
	cout << str; // prints the string
	pos = str.rfind("*") + 1; // after last '*'
	str.replace(pos, str.substr(pos).length(), "#!!@1234"); // replaces the last word with "#!!@1234" 
	cout << endl << str; // prints the string
	pos = str.find("*") ; // finds the first '*'
	while (pos >=0) { // while there are '*' found in the string
		str.erase(0, pos + 1); // erase the first word
		pos = str.find("*"); // finds the next '*'
		cout << endl << str; // prints the string
	}
}


/*
Example:

--- Input ---
My name is aviel

--- Program Output ---
My name is aviel
My*name*is*aviel
My*name*is*#!!@1234
name*is*#!!@1234
is*#!!@1234
#!!@1234
*/
