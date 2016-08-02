#include "TimetoEat.h"

int main(int argc, char *argv[]) 
{
	int start = 0, end = 0;
	ifstream stream(argv[1]);
	vector<string> substr;
	string line, grab, space = " ";
	while (getline(stream, line)) 
	{
		// Do something with the line
		while ((end = line.find(space, start)) != string::npos)
		{
			grab = line.substr(start, end - start);
			substr.push_back(grab);
			start = ++end;
		}

		end = line.length();
		grab = line.substr(start, end - start);
		substr.push_back(grab);

		sort(substr.rbegin(), substr.rend());

		for (int i = 0; i < (int)substr.size(); i++)
		{
			cout << substr[i] << " ";
		}

		cout << endl;

		start = end = 0;
		substr.clear();
	}

	stream.close();

	return 0;
}
