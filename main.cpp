#include <iostream>
#include <string>
#include <fstream>
#include "list_element.h"

using namespace std;

bool try_read_data(string& bufer, string file_name)
{
	ifstream input(file_name);
	if (input.is_open())
	{
		string line;
		while (getline(input, line))
		{
			bufer += line + " ";
		}
	}
	else
	{
		input.close();
		return false;
	}
	input.close();
	return true;
}

void parse(string& bufer, list_element& head, list_element& tail)
{
	bool new_word = true;
	char* symbol = &bufer[0];
	while (*symbol != 0) 
	{
		if (!is_letter(*symbol))
		{
			new_word = true;
		}
		else if (is_letter(*symbol) && new_word)
		{
			add_to_list(symbol, head, tail);
			new_word = false;
		}
		symbol++;
	}
}

int main()
{
	string a;
	list_element head;
	list element tail;
	string file_name;
	string bufer = "";
	cout << "Enter file path: ";
	cout << endl;
	cin >> a;
	file_name = a;
	if (!try_read_data(bufer, file_name))
	{
		cout << "Error read data";
	}
}
