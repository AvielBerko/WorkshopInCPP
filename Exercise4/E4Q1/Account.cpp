#include "Account.h"
#include <cstring>
int Account::sumDeposit = 0;
int Account::sumWithdraw = 0;

Account::Account(int setAcNum, int setCode, int setBal) : accountNumber(setAcNum) { // constructor
	if (setCode > 1000 || setCode < 9999) // wrong code (more or less than 4 digits)
		throw "ERROR: code must be of 4 digits!";
	code = setCode;
	balance = 0;
}

Account::Account() : accountNumber(0), code(0), balance(0) {} // default constructor - sets all to 0


int Account::getAccountNumber() const { return accountNumber; } // accountNumber getter
int Account::getCode() const { return code; } // code getter 
float Account::getBalance() const { return balance; } // balance getter
int Account::getSumWithdraw() { return sumWithdraw; } // sumWithdraw getter
int Account::getSumDeposit() { return sumDeposit; } // SumDeposit getter
void Account::setBalance(float setBal) { balance = setBal; } // balance setter

istream& operator>>(istream& is, Account& A) { // operator >>
	int tempCode;
	is >> A.accountNumber >> tempCode; 
	if (tempCode > 9999 || tempCode < 1000) // wrong code (more or less than 4 digits)
		throw "ERROR: code must be of 4 digits!";
	A.code = tempCode;
	return is;
}

void Account::withdraw(int nis) {
	if (balance - nis < -6000) // error - less than -6000 nis
		throw "ERROR: cannot have less than - 6000 NIS!";
	if (nis > 2500) // error - withdraw more than 2500 nis
		throw "ERROR: cannot withdraw more than 2500 NIS!";
	balance -= nis;
	sumWithdraw += nis;
}
void Account::deposit(int nis) {
	if (nis > 10000) // error - deposit over 10000 nis
		throw "ERROR: cannot deposit more than 10000 NIS!";
	balance += nis;
	sumDeposit += nis;
}