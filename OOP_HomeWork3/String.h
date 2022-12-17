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
		str = new char[125];
		cout << "Enter a string:\n";
		gets_s(str, 126);
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
		if (this->str)
			delete[]this->str;
		this->str = new char[size];
		this->str = str;
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
		String::str = str;
		count++;
	}


	char operator[](int index) {
		return str[index];
	}
	int operator()(char letter) {
		if (strchr(str, letter)) {
			for (int i = 0; i < strlen(str); i++) {
				if (letter == str[i]) {
					return i;
					break;
				}
			}
		}
		else
			return -1;
	}

};

