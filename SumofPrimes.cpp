#include <iostream>

using namespace std;

bool isprime(int num);

int main(int argc, char *argv[])
{
	int count = 0, sum = 0, i = 2;

	while (count < 1000)
	{
		if (isprime(i))
		{
			sum += i;
			count++;
		}
		i++;
	}

	cout << sum << endl;
	return 0;
}

bool isprime(int num)
{
	if (num <= 1)
	{
		return false;
	}
	else if (num <= 3)
	{
		return true;
	}
	else if ((num % 2) == 0 || (num % 3) == 0)
	{
		return false;
	}

	int i = 5;
	while (i*i <= num)
	{
		if ((num % i) == 0 || (num % (i + 2)) == 0)
		{
			return false;
		}
		i += 6;
	}

	return true;
}
