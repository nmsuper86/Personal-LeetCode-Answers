#include <iostream>

using namespace std;

int reverse(int x) {
	
	try
	{	
		long long tempValue = 0;
		bool minorFlag = (x <= 0);
		if (minorFlag)
		{
			x = -x;
		}

		while (x > 0)
		{
			tempValue *= 10;
			tempValue += x % 10;
			x /= 10;
			if (tempValue >= 2147483648)
			{
				return 0;
			}
		}

		if (minorFlag)
		{
			tempValue = -tempValue;
		}

		if ((tempValue < 0 && !minorFlag))
		{
			return 0;
		}
		else
		{
			return tempValue;
		}
		
	}
	catch (exception e)
	{
		return 0;
	}
	
}

int main()
{
	int x = reverse(1534236469);
	system("pause");
	return 0;
}