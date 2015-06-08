#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	typedef struct
	{
		int value;
		size_t oriIndex;
	}number;

	vector<number> newNums;
	for (size_t index = 0; index < nums.size(); index++)
	{
		number num;
		num.value = nums[index];
		num.oriIndex = index;
		newNums.push_back(num);
	}

	sort(newNums.begin(), newNums.end(), [](number num1, number num2){return num1.value < num2.value; });
	for (size_t index1 = 0, index2 = newNums.size() - 1;;)
	{
		if (newNums[index1].value + newNums[index2].value == target)
		{
			vector<int> answer;
			answer.push_back(newNums[index1].oriIndex + 1);
			answer.push_back(newNums[index2].oriIndex + 1);
			sort(answer.begin(), answer.end());
			return answer;
		}
		else if (newNums[index1].value + newNums[index2].value > target)
		{
			index2--;
		}
		else
		{
			index1++;
		}
	}
}

int main()
{
	vector<int> testArray = vector < int > {-3,4,3, 90};
	int target = 0;
	vector<int> result = twoSum(testArray, target);

	cout << result[0] << result[1] << endl;
	system("pause");
	return 0;
}