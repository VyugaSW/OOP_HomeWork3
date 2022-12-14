#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

class String
{
private:
	int count = 0;
	char* str;
public:
	//Move constructor
	String(String&& p) noexcept : 
		str{ nullptr }, count{ NULL }
	{
		str = p.str;
		count = p.count;

		p.str = nullptr;
		p.count = NULL;
	}
	//Default constructor
	String() {
		str = new char[80];
		cout << "Enter a string:\n";
		gets_s(str, 81);
		count++;
	}
	//Constructor with custom size
	String(int size) : String() {
		if (str)
			delete[]str;
		str = new char[size];
		gets_s(str, size+1);
		count++;
	}
	//Custom size string and user's string
	String(char* str, int size) {
		if (str)
			delete[]str;
		str = new char[size];
		gets_s(str, size + 1);
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

