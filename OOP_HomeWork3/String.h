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
	//��� ���� �������� ������ (80 �������� � ������������� �������) �������, ����� ����� �������,
	String(int mode) {
		if (mode == 1) {
			String::size = 80;
			char* buff = new char[80];
			cout << "Enter a string:\n";
			gets_s(buff, 81);
			String::str = buff;
		}
		else if (mode == 2) {
			int size;
			cout << "Enter a size of string:\n";
			cin >> size;
			String::size = size;
			char* buff = new char[size];
			cout << "Enter a string:\n";
			cin.ignore();
			gets_s(buff, 126);
			String::str = buff;
		}
		count++;
	}
	//������ ������������� �������
	String(char* str, int size) {
		String::size = size;
		char* buff = new char[size];
		buff = str;
		String::str = buff;
		count++;
	}
	//������������� (�� ���� ��������� �����, �� ������� �����)
	~String() {
		delete[] str;
	}


	String() {}; //������� ��� �������� ������� ����
	//��������� ���-�� ��������� �����
	int getCount() {
		return count;
	}
	//��������� ������
	char* getString() {
		return str;
	}
	//����� ������
	void setString(char* str) {
		String::size = strlen(str);
		String::str = str;
		count++;
	}


};

