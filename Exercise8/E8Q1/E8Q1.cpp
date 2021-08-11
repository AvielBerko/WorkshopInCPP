// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 8 Question 1
// The program simulates a stack using a linked-list - infix to postfix + calculates the postfix

#include <iostream>
#include <string>
#include "StackList.h"
using namespace std;

string infixToPostfix(string& infix) {
	string postfix = "";
	StackList stk;
	for (int i = 0; i < infix.length(); i++) {
		char ch = infix[i];
		if (ch == '(')
			stk.push(ch);
		else if (ch == ')') {
			while (stk.top() != '(') {
				postfix += " ";
				postfix += (char)stk.pop();
			}
			stk.pop(); // remove the '('
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			postfix += " "; // space between 2 numbers
			if ((ch == '+' || ch == '-') && (stk.top() == '*' || stk.top() == '/')) {
				postfix += (char)stk.pop();
				postfix += " ";
			}
			stk.push(ch);
		}
		else
			postfix += ch;
	}
	while (!stk.isEmpty()) {
		postfix += " ";
		postfix += (char)stk.pop();
	}
	return postfix;
}
int calcPostfix(string& postfix) {
	StackList stk;
	for (int i = 0; i < postfix.length(); i++) {
		char ch = postfix[i];
		if (ch == ' ')
			continue;
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			int num1 = stk.pop(), num2 = stk.pop(); // 2 first numbers in the stack
			switch (ch) {
			case '+':
				stk.push(num2 + num1);
				break;
			case '-':
				stk.push(num2 - num1);
				break;
			case '*':
				stk.push(num2 * num1);
				break;
			case '/':
				stk.push(num2 / num1);
				break;
			}
		}
		else { // number
			stk.push(stoi(postfix.substr(i), NULL, 10)); // save the number from the string
			while (postfix[i] != ' ') // continue to the space
				i++;
		}
	}
	return stk.pop();
}


int main() {
	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << postfix << endl;
	cout << calcPostfix(postfix) << endl;
	return 0;
}

/*
Example:

--- Input ---
(5+3)*((20/10)+(8-6))
--- Program Output ---
enter an infix expression as a string
(5+3)*((20/10)+(8-6))
5 3 + 20 10 / 8 6 - + *
32
*/
