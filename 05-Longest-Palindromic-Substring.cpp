#include <iostream>

using namespace std;

string longestPalindrome(string s) {

	string resultStr = s.substr(0, 1);
	size_t length = 1;

	if (s.size() <= 1)
	{
		return s;
	}

	for (size_t index = 1; index < s.size(); index++)
	{
		if (s[index] == s[index - 1])
		{
			size_t halfLength = 1;
			for ( ;
				(index - halfLength > 0) && (index + halfLength < s.size());
				 halfLength++
				 )
			{
				if (s[index + halfLength] == s[index - halfLength - 1])
				{
					continue;
				}
				else
				{
					break;
				}

			}

			string temp = s.substr(index - halfLength, halfLength * 2);
			if (temp.size() > length)
			{
				length = temp.size();
				resultStr = temp;
			}

			if (index + halfLength == s.size())
			{
				break;
			}
		}

		if (index < s.size() - 1 && s[index - 1] == s[index + 1])
		{
			size_t halfLengthWithoutPivot = 1;
			for (;
				 (index - halfLengthWithoutPivot >= 0) && (index + halfLengthWithoutPivot < s.size());
				 halfLengthWithoutPivot++
				 )
			{
				if (s[index + halfLengthWithoutPivot] == s[index - halfLengthWithoutPivot])
				{
					continue;
				}
				else
				{
					break;
				}
			}

			string temp = s.substr(index - halfLengthWithoutPivot + 1, halfLengthWithoutPivot * 2 - 1);
			if (temp.size() > length)
			{
				length = temp.size();
				resultStr = temp;
			}

			if (index + halfLengthWithoutPivot == s.size())
			{
				break;
			}
		}
	}

	return resultStr;
}

int main()
{
	string inStr = "aaba";
	string re = longestPalindrome(inStr);
	system("pause");
	return 0;
}