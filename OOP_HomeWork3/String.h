#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

class String
{
	

private:
	int count = 0;
	int size = 0;
	char* str = new char[size];
public:
	//Default constructor
	String() {
		String::size = 80;
		char* buffDef = new char[80];
		cout << "Enter a string:\n";
		gets_s(buffDef, 81);
		String::str = buffDef;
		count++;
	}
	//Constructor with custom size
	String(int size) : String() {
		String::size = size;
		char* buffDef = new char[size];
		strcpy_s(buffDef, size + 1, str);
		String::str = buffDef;
	}
	//Custom size string and user's string
	String(char* str, int size) {
		String::size = size;
		char* buff = new char[size];
		buff = str;
		String::str = buff;
		count++;
	}
	//Destructor (I don't know how true, but I hope so)
	~String() {
		delete[] str;
	}

	//Returns the number of strings created
	int getCount() {
		return count;
	}
	//Returns a string
	char* getString() {
		return str;
	}
	//Sets a string
	void setString(char* str) {
		String::size = strlen(str);
		String::str = str;
		count++;
	}


};

