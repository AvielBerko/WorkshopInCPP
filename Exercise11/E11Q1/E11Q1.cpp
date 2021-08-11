// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 11 Quesstion 1
// The program simulates a binary search tree 
#include "SearchTree.h"

int main() {
	SearchTree<int> T1;
	cout << "enter 10 numbers\n";
	int x, y;
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		T1.add(x);
	}
	cout << "inorder: ";
	T1.inOrder();
	cout << "\nenter 0-6:\n";
	cin >> x;
	while (x != 0)
	{
		switch (x)
		{
		case 1: cout << "# of leaves: " << T1.leaves() << endl;
			break;
		case 2: cout << "height of tree: " << T1.height() << endl;
			break;
		case 3:T1.reflect();
			cout << "reflected tree: ";
			T1.inOrder();
			T1.reflect();
			cout << endl;
			break;
		case 4: cout << "# left sons only: " << T1.onlyLeftSon() << endl;
			break;
		case 5: cout << "enter a number ";
			cin >> y;
			cout << "level of " << y << " on tree: " << T1.level(y) << endl;
			break;
		case 6: cout << "enter a number ";
			cin >> y;
			T1.remove(y);
			cout << "after removing " << y << ": ";
			T1.inOrder();
			cout << endl;
		}
		cout << "enter 0-6:\n";
		cin >> x;
	}
	return 0;
}

/*
Example:

--- Input ---
enter 10 numbers
1 6 3 9 10 2 5 4 17 8
1
2
3
4
6
9
0
--- Program Output ---
enter 10 numbers
1 6 3 9 10 2 5 4 17 8
inorder: 1 2 3 4 5 6 8 9 10 17
enter 0-6:
1
# of leaves: 4
enter 0-6:
2
height of tree: 5
enter 0-6:
3
reflected tree: 17 10 9 8 6 5 4 3 2 1
enter 0-6:
4
# left sons only: 1
enter 0-6:
6
enter a number 9
after removing 9: 1 2 3 4 5 6 8 10 17
enter 0-6:
0

*/
