// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 3, Question 3
// The program receives 2 strings compares them and cats them

#include <iostream>
#include "String.h"
using namespace std;

int main()
{
	char strA[101], strB[101]; // not specified in the question the size of the input
	int index;
	cin >> strA >> strB >> index;
	String a(strA), b(strB);
	if (a == b)
		cout << "a=b" << endl;
	else if (a > b)
		cout << "a>b" << endl;
	else
		cout << "a<b" << endl;
	cout << a.insert(index, b.getString()) << endl;
	return 0;
}


/*
Example:

--- Input ---
Hello
World
4
--- Program Output ---
Hello World 4
a<b
HellWorldo
*/