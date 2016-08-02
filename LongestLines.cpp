#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct compare
{
	bool operator()(const string &first, const string &last)
	{
		return first.length() < last.length();
	}
};

int main(int argc, char *argv[])
{
	ifstream inputfile;
	string line;
	vector<string> store;
	compare comp;
	int outputnum = 0, i = 0, j = 0;

	inputfile.open(argv[1]);
	getline(inputfile, line);

	istringstream(line) >> outputnum;

	while (getline(inputfile, line))
	{
		store.push_back(line);
	}

	sort(store.rbegin(), store.rend(), comp);

	/*for (i = 0; i < (int)store.size(); i++)
	{
		j = i;
		while (j > 0 && (store[j - 1].length() < store[j].length()))
		{
			swap(store[j], store[j - 1]);
			j--;
		}
	}*/

	for (i = 0; i < outputnum; i++)
	{
		cout << store[i] << endl;
	}

	inputfile.close();
	system("pause");
	return 0;
}
