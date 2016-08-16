#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream infile;
	string line;
	stringstream ss;
	vector<string> arr;

	infile.open(argv[1], ios::in);

	if (!infile.is_open())
	{
		cout << "Unable to open file" << endl;
		exit(1);
	}

	while (getline(infile, line))
	{
		string temp;
		ss << line;

		while (ss >> temp)
		{
			arr.push_back(temp);
		}

		for (int i = ((int)arr.size() - 1); i >= 0; i--)
		{
			cout << arr[i] << " ";
		}

		cout << endl;
		arr.clear(); ss.clear();
	}

	infile.close();
	return 0;
}
