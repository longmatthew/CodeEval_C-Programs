#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream infile;
	string line;

	infile.open(argv[1], ios::in);

	if (!infile.is_open())
	{
		cout << "Unable to open file" << endl;
		exit(1);
	}

	while (getline(infile, line))
	{
		int i = 0;
		while (line[i] != '\0')
		{
			if (isupper(line[i]))
			{
				char temp = tolower(line[i]);
				cout << temp;
			}
			else
			{
				cout << line[i];
			}
			i++;
		}
		cout << endl;
	}

	return 0;
}
