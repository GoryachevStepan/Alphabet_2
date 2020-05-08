#include <iostream>
#include <string>
#include <fstream>

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

int main()
{
	string a;
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
