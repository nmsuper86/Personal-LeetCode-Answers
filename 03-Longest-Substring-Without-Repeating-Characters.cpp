#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) 
{
	size_t position[256];
	size_t maxLength = 0;
	size_t startPosition = 0;

	for (size_t i = 0; i < 256; i++)
	{
		position[i] = -1;
	}

	auto order = [&](int threashold){
		for (int i = 0; i < 256; i++)
		{
			if (position[i] <= threashold)
			{
				position[i] = -1;
			}
		}
	};

	for (size_t index = 0; index < s.size(); index++)
	{
		if (position[s[index]] != -1)
		{
			maxLength = ((index - startPosition) > maxLength) ? (index - startPosition) : maxLength;
			startPosition = position[s[index]] + 1;
			order(startPosition - 1);
			position[s[index]] = index;
		}
		else
		{
			position[s[index]] = index;
		}
	}
	maxLength = ((s.size() - startPosition) > maxLength) ? (s.size() - startPosition) : maxLength;
	return maxLength;
}

int main()
{
	cout << lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]") << endl;
	system("pause");
	return 0;
}