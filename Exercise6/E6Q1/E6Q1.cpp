// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 6 Question 1
// The program simulates a Rounded linked list

//The main program is copied from the question so there are no comments
#include <iostream>
#include "List.h"
#include "RoundList.h"
using namespace std;
enum CHOICES {
	EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY
};
int main()
{
	RoundList ls1;
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	while (choice != EXIT)
	{
		int num;
		switch (choice) {
		case ADD: cout << "Enter 5 numbers: ";
			for (int i = 0; i < 5; i++)
			{
				cin >> num;
				ls1.add(num);
			}
			break;
		case ADD_TO_END:cout << "Enter 5 numbers: ";
			for (int i = 0; i < 5; i++)
			{
				cin >> num;
				ls1.addToEnd(num);
			}
			break;
		case REMOVE_FIRST: ls1.removeFirst();
			break;
		case SEARCH: cout << "Enter a number: ";
			cin >> num;
			cout << ls1.search(num) << endl;
			break;
		case CLEAR: ls1.clear();
			break;
		case EMPTY: if (ls1.isEmpty())
			cout << "Empty" << endl;
				  else
			cout << "Not empty" << endl;
			break;
		default: cout << "ERROR!" << endl;
		}
		cout << "Enter your choice: ";
		cin >> choice;
	}
	return 0;
}

/*
Example:

--- Input ---
1
1 2 3 4 5
2
5 4 3 2 1
3
4
2
3
4
2
4
6
6
5
6
0

--- Program Output ---
Enter your choice: 1
Enter 5 numbers:   1 2 3 4 5
Enter your choice: 2
Enter 5 numbers:   5 4 3 2 1
Enter your choice: 3
Enter your choice: 4
Enter a number:    2
2
Enter your choice: 3
Enter your choice: 4
Enter a number:    2
1
Enter your choice: 4
Enter a number:    6
2
Enter your choice: 6
Not empty
Enter your choice: 5
Enter your choice: 6
Empty
Enter your choice: 0

*/
