#pragma once
#include <iostream>
using namespace std;
class Account
{
	int accountNumber;
	int code;
	float balance;
	static int sumWithdraw;
	static int sumDeposit;

	
public:
	Account(int setAcNum, int setCode, int setBal); // constructor
	Account(); // default constructor
	int getAccountNumber() const; // accountNumber getter
	int getCode() const; // code getter
	float getBalance() const; // balance getter
	static int getSumWithdraw(); // sumWithdraw getter
	static int getSumDeposit(); // SumDeposit getter
	void setBalance(float setBal); // balance setter

	friend istream& operator>>(istream& is, Account& A); // operator >>

	void withdraw(int nis); // withdraw money
	void deposit(int nis); // deposit money

};

