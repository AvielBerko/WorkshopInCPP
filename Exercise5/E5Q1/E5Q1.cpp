// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 5 Question 1
// The program simulates a linked list

// most of the main program is copied from the question so there are no comments
#include <iostream>
#include "List.h"
using namespace std;


int main()
{
	List lst;
	int choice, val;
	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-2\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1:cout << "enter a value to insert\n";
			cin >> val;
			lst.insert(val);
			break;
		case 2:cout << "enter a value to remove\n";
			cin >> val;
			try {
				lst.remove(val);
			}
			catch (char* msg)
			{
				cout << msg << endl;
			}
			break;
		default:cout << "ERROR\n";
		}
		cout << lst << endl;
		cout << "choose 0-2\n";
		cin >> choice;
	}
	return 0;

}

/*
Example:

--- Input ---
1 2 3 3
2
2
1
4
1
2
0

--- Program Output ---
enter the list values
1 2 3 3
choose 0 - 2
2
enter a value to remove
2
1 3
choose 0 - 2
1
enter a value to insert
4
1 3 4
choose 0 - 2
1
enter a value to insert
2
1 2 3 4
choose 0 - 2
0

*/