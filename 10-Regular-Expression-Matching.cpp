#include <iostream>

using namespace std;

bool isMatch(string s, string p)
{
	int indexS = s.length() - 1, indexP = p.length() - 1;

	if (indexP == -1 && indexS != -1)
	{
		return false;
	}
	else if (indexP == -1 && indexS == -1)
	{
		return true;
	}
/*	else if (indexS == -1)
	{
		return false;
	}*/

	auto matchChar = [&](char c)
	{
		return (c == '.') ?
			indexS >= 0 :
			indexS >= 0 && s[indexS] == c;
	};

	for (; indexP >= 0; indexP--, indexS--)
	{
		if (p[indexP] == '*')
		{
			char preChar = p[indexP - 1];
			string preP = p.substr(0, indexP - 1);

			int matchedCharCount = 0;
			do
			{
				string tempP = preP;
				for (int i = 0; i < matchedCharCount; i++)
				{
					tempP.push_back(p[indexP - 1]);
				}
				
				if (isMatch(s.substr(0, indexS + 1), tempP) == true)
				{
					return true;
				}
				
				if (indexS - matchedCharCount < 0 || ((s[indexS - matchedCharCount] != preChar) && preChar != '.'))
				{
					break;
				}
				else
				{
					matchedCharCount++;
				}

			} while (1);
			return false;
		}
		else if (!matchChar(p[indexP]))
		{
			return false;
		}
	}

	if (indexS >= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}


int main()
{
	bool val = isMatch("", ".*");
	system("pause");
	return 0;
}