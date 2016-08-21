#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream infile;
	string line, compstr, mulstr;
	int mul = 0, comp = 0, total = 0, i = 2;

	infile.open(argv[1], ios::in);

	if (!infile.is_open())
	{
		cout << "Unable to open file" << endl;
		exit(1);
	}

	while (getline(infile, line))
	{
		size_t found = line.find(',');
		mulstr = line.substr(found + 1);
		compstr = line.substr(0, found);

		istringstream isscomp(compstr);
		istringstream issmul(mulstr);

		isscomp >> comp;
		issmul >> mul;

		total = mul;

		while (comp > total)
		{
			total = mul * i;
			i++;
		}
		i = 2;

		cout << total << endl;
	}

	infile.close();
	return 0;
}
