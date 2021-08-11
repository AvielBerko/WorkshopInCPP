// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 5 Question 2
// The program simulates a linked list with 2 functions

// most of the main program is copied from the question so there are no comments
#include <iostream>
#include "List.h"
using namespace std;

List merge(List lst1, List lst2);
void makeSet(List& lst);

int main()
{
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	return 0;
}

List merge(List lst1, List lst2) {
	List newList;
	while (!lst1.isEmpty()) {
		newList.insert(lst1.firstElement()); // the function "insert" inserts the value to the correct place
		lst1.removeFirst(); // removes the first element
	}
	while (!lst2.isEmpty()) {
		newList.insert(lst2.firstElement()); // the function "insert" inserts the value to the correct place
		lst2.removeFirst(); // removes the first element
	}
	return newList;
}

void makeSet(List& lst) {
	List temp;
	while (!lst.isEmpty()) {
		if (!temp.search(lst.firstElement())) // if the first element is not found in the temp list
			temp.insert(lst.firstElement()); // insert the element to temp
		lst.removeFirst(); // removes the first element
	}
	lst = temp;
}


/*
Example:

--- Input ---
1 2 3 5 6 0
3 4 5 7 0

--- Program Output ---
enter sorted values for the first list :
1 2 3 5 6 0
enter sorted values for the second list :
3 4 5 7 0
the new merged list : 1 2 3 3 4 5 5 6 7
the new merged set : 1 2 3 4 5 6 7

*/