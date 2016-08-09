#include <iostream>

using namespace std;

bool isprime(int num);
bool ispalindrome(int num);

int main(int argc, char*argv[])
{
	int prime;

	for (int i = 2; i < 1000; i++)
	{
		if (isprime(i) && ispalindrome(i))
		{
			prime = i;
		}
	}

	cout << prime << endl;
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

bool ispalindrome(int num)
{
	int check = num, rev = 0, dig = 0;

	while (num)
	{
		dig = num % 10;
		rev = (rev * 10) + dig;
		num = num / 10;
	}

	return (check == rev);
}
