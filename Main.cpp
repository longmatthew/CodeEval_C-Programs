#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	// ifstream infile(argv[1], ifstream::ate);

	ifstream infile(argv[1], ifstream::binary);

	infile.seekg(0, infile.end);

	cout << infile.tellg() << endl;

	infile.close();
	system("pause");

	return 0;
}