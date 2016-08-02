#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream infile;
	stringstream ss;
	string line;
	int X = 0, Y = 0, N = 0, i = 0;
	infile.open(argv[1], ios::in);

	if (!infile.is_open())
	{
		cout << "File not found" << endl;
		return 0;
	}

	while (getline(infile, line))
	{
		ss << line;
		ss >> X >> Y >> N;

		for (i = 1; i <= N; i++)
		{
			if (((i % X) == 0) && ((i % Y) == 0))
			{
				cout << "FB ";
			}
			else if ((i % X) == 0)
			{
				cout << "F ";
			}
			else if ((i % Y) == 0)
			{
				cout << "B ";
			}
			else if (((i % X) != 0) || ((i % Y) != 0))
			{
				cout << i << " ";
			}
		}

		cout << endl;
		ss.clear();
	}

	infile.close();
	return 0;
}
