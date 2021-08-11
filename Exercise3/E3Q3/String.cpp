// A big portion of the class was written in the course book - so there are no comments
#include "String.h"
#pragma warning (disable:4996)

String String::insert(int index, const char* string) const { // cats 2 strings in the index's location
	if (index <= length()) {
		//static String result; // static because we need to return it by reference - Question Mistake
		String result;
		result.str = new char[length() + strlen(string) + 1]; // allocating the string 
		strncpy(result.str, string, index); // copies the 1st part of the string
		result.str[index] = '\0'; // adding a null-termination
		strcat(result.str, str); // cats the other string in the index's place
		strcat(result.str, string + index); // cats the 2nd part of the original string
		return result;
	}
	else
		cout << "ERROR" << endl;
	return String(""); // returns an empty string
}

char* String::getString() const {
	return str;
}

void String::setString(const char* s) {
	if (s)
	{
		int len = strlen(s) + 1;
		str = new char[len];
		strcpy(str, s);
	}
	else str = NULL;
}

int String::length() const {
	return strlen(str);
}

void String::print() const {
	if (str) cout << str << endl;
}

// constructors etc...
/*String::String(char* s) { // constructor 
	setString(s);
} */

String::String(const char* s) {
	setString(s);
}

String::String(const String& s) {
	setString(s.getString());
}

String::~String() {
	if (str)
		delete[] str;
	str = NULL;
}

// operators
String& String::operator=(const String& s) { // operator =
	if (str)
		delete[] str;
	setString(s.getString());
	return *this;
}

String String::operator+(const String& s) const {
	int sizeI = strlen(str);
	int sizeII = strlen(s.getString());
	char* temp = new char[sizeI + sizeII + 1];
	strcpy(temp, str);
	strcpy(temp + sizeI, s.getString());
	String x(temp);
	return x;
}

String String::operator*(const int num) const {
	char* temp;
	int len = strlen(str);
	temp = new char[len * num + 1];
	for (int i = 0; i < num; i++)
		strcpy(temp + i * len, str);
	String s(temp);
	return s;
}

bool String::operator==(const String& s) const {
	return !strcmp(str, s.getString());
}

bool String::operator!= (const String& other) const { // operator !=
	return !(*this == other);
}

bool String::operator> (const String& other) const { // operator > (using strcmp)
	return (strcmp(this->str, other.str) > 0);
}

bool String::operator< (const String& other) const { // operator < (using strcmp)
	return (strcmp(this->str, other.str) < 0);
}

bool String::operator>= (const String& other) const { // operator >= (using strcmp)
	return (strcmp(this->str, other.str) >= 0);
}

bool String::operator<= (const String& other) const { // operator <= (using strcmp)
	return (strcmp(this->str, other.str) <= 0);
}

ostream& operator<< (ostream& os, const String& S) { // operator <<
	os << S.str;
	return os;
}

istream& operator>>(istream& is, String& S) { // operator >>
	is >> S.str;
	return is;
}