// Name: Aviel Berkovich, ID: 211981105
// Workshop in c++
// Exercise 4
// The program simulates a bank account

// most of the main program is copied from the question so there are no comments

#include "Clock.h"
#include "Account.h"

enum action { STOP = 0, BALANCE, DEPOSIT, WITHDRAW, SUMDEPOSIT, SUMWITHDRAW };
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop\n" << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size)
{
	int number, code;
	cout << "please enter account number: " << endl;
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	if (i == size)
		throw "ERROR: no such account number!";
	cout << "please enter the code: " << endl;
	cin >> code;
	if (code > 9999 || code < 1000 || code != bank[i].getCode())
		throw "ERROR: wrong code!";

	if (bank[i].getCode() == code)
		return i;
}
void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";
	switch (ac)
	{
	case BALANCE: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case DEPOSIT:
	case WITHDRAW: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case SUMDEPOSIT:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case SUMWITHDRAW:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], BALANCE, c);
}
void cashDeposit(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	int amount;
	cout << "enter the amount of the check: " << endl;
	cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], DEPOSIT, c);
}
void cashWithdraw(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	int amount;
	cout << "enter the amount of money to withdraw: " << endl;
	cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], WITHDRAW, c);
}
int main()
{
	Clock c(8);
	Account bank[10];
	cout << "enter account number and code for 10 accounts:\n" << endl;
	for (int i = 0; i < 10; i++)
	{
		try
		{
			cin >> bank[i];
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n";
		}
		catch (const char* msg)
		{
			cout << c << '\t' << msg;
			i--;
		}
	}
	action ac = menu();
	while (ac)
	{
		try
		{
			switch (ac)
			{
			case BALANCE: getBalance(bank, 10, c);
				break;
			case WITHDRAW:cashWithdraw(bank, 10, c);
				break;
			case DEPOSIT:cashDeposit(bank, 10, c);
				break;
			case SUMDEPOSIT:c += 60;
				printTransaction(bank[0], SUMDEPOSIT, c);
				break;
			case SUMWITHDRAW:c += 60;
				printTransaction(bank[0], SUMWITHDRAW, c);
			}
		}
		catch (const char* err)
		{
			cout << c << "\t" << err << endl;
		}

		ac = menu();
	}
	return 0;
}

/*
Example:

--- Input ---
1 1111
2 2222
3 3333
4 4444
5 5555
6 6666
7 7777
8 8888
9 9999
10 1010
2
232
3
3
2222
0
--- Program Output ---
1 11112 2222
3 3333
4 4444
5 5555
6 6666
7 7777
8 8888
9 9999
10 1010
enter	1	to	get	account	balance
enter	2	to	deposit	money
enter	3	to	withdraw	money
enter	4	to	see	the	sum	of	all	withdraws
enter	5	to	see	the	sum	of	all	Deposits
enter	0	to	stop
2
please	enter	account	number:
232
08:00:00 ERROR:	no	such	account	number!
enter	1	to	get	account	balance
enter	2	to	deposit	money
enter	3	to	withdraw	money
enter	4	to	see	the	sum	of	all	withdraws
enter	5	to	see	the	sum	of	all	Deposits
enter	0	to	stop
3
please	enter	account	number:
3
please	enter	the	code:
2222
08:00:00 ERROR:	wrong	code!
enter	1	to	get	account	balance
enter	2	to	deposit	moneyenter	3	to	withdraw	money
enter	4	to	see	the	sum	of	all	withdraws
enter	5	to	see	the	sum	of	all	Deposits
enter	0	to	stop
0
*/