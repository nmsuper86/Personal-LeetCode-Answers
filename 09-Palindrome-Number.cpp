#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(int x) {
	
//	x = (x < 0) ? -x : x;
	if (x < 0)
	{
		return false;
	}

	int digitCount = 0;
	int temp = x;
	do
	{
		digitCount++;
		temp /= 10;
	} while (temp != 0);

	char chs[10];
	for (int index = 0; index < digitCount; index++)
	{
		chs[digitCount - index - 1] = x % 10 + '0';

		if (index >= digitCount / 2)
		{
			if (chs[index] != chs[digitCount - index - 1])
			{
				return false;
			}
		}

		x /= 10;
	}

	return true;
}

int main()
{
	bool flag = isPalindrome(-2147447412);
	system("pause");
	return 0;
}