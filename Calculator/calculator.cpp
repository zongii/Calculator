#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

float finalCalculation(string c)
{
	stringstream ss;

	ss.str(c);

	float number, reasult;
	char sign;

	bool eOF = false;

	ss >> reasult;

	while (!eOF)
	{
		ss >> sign;

		if (sign == '-')
		{
			ss >> number;
			reasult -= number;
		}
		if (sign == '+')
		{
			ss >> number;
			reasult += number;
		}
		if (sign == '=')
		{
			eOF = true;
		}
	}
	return reasult;
}

int mulDivOperation(string& c)
{
	stringstream ss;
	ss.str(c);
	vector<string> operation;

	int counter = 0;
	for (int i = 0; i < c.length(); i++) if (c[i] == ' ') counter++;

	for (int i = 0; i < counter + 1; i++)
	{
		string temp;
		ss >> temp;
		operation.push_back(temp);
	}

	int iterator = 0;

	for (string s : operation)
	{
		if (s == "*")
		{
			float temp = (float)((float)stof(operation.at(iterator - 1)) * (float)stof(operation.at(iterator + 1)));
			stringstream sst;
			sst << temp;

			operation[iterator] = sst.str();
			operation.erase(operation.begin() + iterator + 1);
			operation.erase(operation.begin() + iterator - 1);

			string tempstr = "";
			for (string s : operation)
			{
				tempstr += s + " ";
			}
			c = tempstr;

			return 0;
		}

		if (s == "/")
		{
			float temp = (float)((float)stof(operation.at(iterator - 1)) / (float)stof(operation.at(iterator + 1)));
			stringstream sst;
			sst << temp;

			operation[iterator] = sst.str();
			operation.erase(operation.begin() + iterator + 1);
			operation.erase(operation.begin() + iterator - 1);

			string tempstr = "";
			for (string s : operation)
			{
				tempstr += s + " ";
			}
			c = tempstr;

			return 0;
		}

		iterator++;
	}
}

int main()
{
	fstream file;
	file.open("wzory.txt");

	string line;
	while (getline(file, line))
	{
		bool looper = true;
		cout << line;

		while (looper)
		{
			looper = false;
			for (char c : line) if (c == '*' || c == '/') looper = true;
			int testint = mulDivOperation(line);
		}
		cout << " " << finalCalculation(line) << endl;
	}
}