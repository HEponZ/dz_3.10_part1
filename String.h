#pragma once
#include <iostream>

using namespace std;

class String {
private:
	char* string;
	int size;
	static int count;
public:
	String() : String(nullptr, 80) {};
	String(int size) : String(nullptr, size) {};
	String(char* string_S, int size_S) : string{ new char[size_S] }, size{ size_S }
	{
		count++;
		if (string_S)
		{
			strcpy_s(string, size_S, string_S);
		}
	}
	String(String&& string_S) : string{ string_S.string }, size{ string_S.size }
	{
		string_S.string = nullptr;
		string_S.size = 0;
		count++;
	}

	const char* get_string()
	{
		return string;
	}
	const int get_size()
	{
		return size;
	}
	void set_string(const char* string_S)
	{
		size = strlen(string) + 1;

		if (string)
		{
			delete[] string;
		}
		string = new char[size];
		strcpy_s(string, size, string_S);
	}

	void print();
	static int get_count()
	{
		return count;
	}

	char& operator[](int index)
	{
		return string[index];
	}

	char& operator[](int index) const
	{
		return string[index];
	}

	int operator()(char symbol)
	{
		/*if (strchr(string, symbol) != 0)
		{
			
		}*/

		for (int i{ 0 }; i < strlen(string); i++)
		{
			if (string[i] == symbol)
			{
				return i;
			}
		}

		return -1;
	}

	friend istream& operator>> (istream& my_cin, String& str)
	{
		char buffer[100]{};

		gets_s(buffer);
		strcpy_s(str.string, strlen(buffer) + 1, buffer);

		return my_cin;
	}

	~String()
	{
		count--;
		delete[] string;
	}
};
