#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream infile;
	string line;
	bool flag;
	char temp;

	infile.open(argv[1], ios::in);

	if (!infile.is_open())
	{
		cout << "Unable to open file" << endl;
		return 0;
	}

	while (getline(infile, line))
	{
		flag = false;
		for (char &c : line)
		{
			if (isalpha(c))
			{
				flag = true;
				temp = tolower(c);
				cout << temp;
			}

			if ((flag == true) && (!isalpha(c)))
			{
				flag = false;
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
