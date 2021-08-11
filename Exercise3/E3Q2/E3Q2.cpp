// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 3, Question 2
// The program receives a date and demos it's operators

#include <iostream>
#include "Date.h"
using namespace std;
enum Choice { SET_DATE = 1, PREFIX_PP, POSTPIX_PP, ADD_DAYS, GRATER, SMALLER, EQUAL, STOP = -1 };
int main()
{
	cout << "Enter a date" << endl;
	Date D, temp;
	cin >> D;
	D.print(); // prints D
	cout << "What do you want to do" << endl;
	int ch;
	cin >> ch; // users choice
	do {
		switch (ch)
		{
		case SET_DATE:
			cout << "Enter a date" << endl;
			cin >> temp; // user's input date
			D.setDate(temp.getDay(), temp.getMonth(), temp.getYear()); // sets the date
			D.print(); // prints D
			//D = temp;
			//cout << D;
			break;
		case PREFIX_PP:
			//cout << D++ << endl;
			(++D).print(); // prints D after ++
			break;
		case POSTPIX_PP:
			//cout << ++D << endl;
			(D++).print(); // prints D before ++
			break;
		case ADD_DAYS:
			cout << "Enter #days" << endl;
			int num;
			cin >> num; // number of days to add
			D += num; // adds the days
			//cout << D;
			D.print(); // prints D
			break;
		case GRATER:
			cout << "Enter a date" << endl;
			cin >> temp;
			(D > temp) ? cout << ">: true" << endl : cout << ":> false" << endl; // checks if grater
			break;
		case SMALLER:
			cout << "Enter a date" << endl;
			cin >> temp;
			(D < temp) ? cout << "<: true" << endl : cout << "<: false" << endl; // checks if smaller
			break;
		case EQUAL:
			cout << "Enter a date" << endl;
			cin >> temp;
			(D == temp) ? cout << "==: true" << endl : cout << "==: false" << endl; // checks if equal
			break;
		default:
			break;
		}
		cout << "What do you want to do" << endl;
		cin >> ch;
	} while (ch != -1);
	return 0;
}


/*
Example:

--- Input ---
-5/1/2012
1
5/7/2010
2
3
4
7
5
14/7/2010
7
14/7/2010
-1

--- Program Output ---
Enter a date
-5/1/2012
Error day
1/1/2012
What do you want to do
1
Enter a date
5/7/2010
5/7/2010
What do you want to do
2
6/7/2010
What do you want to do
3
6/7/2010
What do you want to do
4
Enter #days
7
14/7/2010
What do you want to do
5
Enter a date
14/7/2010
:> false
What do you want to do
7
Enter a date
14/7/2010
==: true
What do you want to do
-1
*/