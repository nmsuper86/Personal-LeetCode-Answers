#include <iostream>

using namespace std;

string convert(string s, int numRows) {

	if (numRows == 1)
	{
		return s;
	}
	else
	{
		int groupCount = numRows * 2 - 2;
		string result = "";

		for (size_t row = 0; row < numRows; row++)
		{
			for (size_t group = 0; group < s.size(); group += groupCount)
			{
				if (row + group < s.size())
				{
					result += s[row + group];
				}

				if (row != 0 && row != numRows - 1 && group + groupCount - row < s.size())
				{
					result += s[group + groupCount - row];
				}
			}
		}

		return result;
	}
	
}

int main()
{
	string re = convert("abc", 2);
	system("pause");
	return 0;
}