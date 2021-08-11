// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 11 Quesstion 2
// The program 
#include "SearchTree.h"
#include "Student.h"

int main() {
	SearchTree<Student> studentsTree; // bst of students
	Student tempS; // temp student
	cout << "enter a-e" << endl;
	char ch;
	cin >> ch;

	while (ch != 'e') {
		switch (ch) {
		case 'a':
			cout << "enter a student" << endl;
			cin >> tempS; // receive a student from user
			studentsTree.add(tempS); // add the student to bst
			break;
		case 'b':
			cout << "enter a student" << endl;
			cin >> tempS; // receive a student from user
			if (studentsTree.search(tempS)) // if student was found
				studentsTree.remove(tempS); // remove
			else
				cout << "not exist" << endl;
			break;
		case 'c':
			cout << "enter a student" << endl;
			cin >> tempS; // receive a student from user
			studentsTree.search(tempS) ? cout << "exist" << endl : cout << "not exist" << endl;
			break;
		case 'd':
			studentsTree.inOrder(); // print inorder
			break;
		default:
			cout << "error" << endl;
		}
		cout << "enter a-e" << endl;
		cin >> ch;
	}
	return 0;
}

/*
Example:

--- Input ---
a
2 b b
a
5 e e
a
1 a a
a
4 d d
a
7 g g
a
3 c c
b
5 e e
d
e
--- Program Output ---
enter a-e
a
enter a student
2 b b
enter a-e
a
enter a student
5 e e
enter a-e
a
enter a student
1 a a
enter a-e
a
enter a student
4 d d
enter a-e
a
enter a student
7 g g
enter a-e
a
enter a student
3 c c
enter a-e
b
enter a student
5 e e
enter a-e
d
1 a a
2 b b
3 c c
4 d d
7 g g
enter a-e
e
*/
