#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream infile;
	string line, sentence, delimiter = ";";
	istringstream iss;
	stringstream ss;
	vector<string> input, output;
	size_t pos = 0;
	int words = 0, *arr;

	infile.open(argv[1], ios::in);

	if (!infile.is_open())
	{
		cout << "Unable to open file" << endl;
		exit(1);
	}

	while (getline(infile, line))
	{
		input.clear(); output.clear(); ss.clear(); iss.clear(); words = 0;
		while ((pos = line.find(delimiter)) != string::npos)
		{
			sentence = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
		}

		for (int i = 0; i < (int)sentence.length(); i++)
		{
			if (sentence[i] == ' ')
			{
				words++;
			}
		}
		words++;

		ss.str(sentence);
		iss.str(line);
		for (int i = 0; i < words; i++)
		{
			string hold;
			ss >> hold;
			input.push_back(hold);
		}
		output.resize(words);

		int val, i = 0;
		arr = new int[words]();
		while (iss >> val)
		{
			output[val - 1] = input[i];
			arr[val - 1]++; i++;
		}

		int j = 0;
		while (arr[j] != 0)
		{
			j++;
		}
		output[j] = input[words - 1];

		for (int i = 0; i < words; i++)
		{
			cout << output[i] << " ";
		}

		cout << endl;
		delete arr;
		arr = NULL;
	}

	return 0;
}
