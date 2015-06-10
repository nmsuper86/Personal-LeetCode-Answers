#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


size_t binSearch(vector<int> &vec, size_t limLow, size_t limHigh, int valueSearch)
{
	if (vec.size() == 0)
	{
		return 0;
	}

	for (;;)
	{
		size_t temp = (limLow + limHigh) / 2;
		if (vec[temp] == valueSearch)
		{
			return temp;
		}

		if (limLow == limHigh)
		{
			break;
		}
		else if (vec[temp] > valueSearch)
		{
			limHigh = temp;
		}
		else
		{
			limLow = temp + 1;
		}
	}
	return limLow;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

	size_t startPosition = 0;
	for (size_t index = 0; index < nums2.size(); index++)
	{
		if (nums1.size() == 0 || nums2[index] > nums1[nums1.size() - 1])
		{
			for (; index < nums2.size(); index++)
			{
				nums1.push_back(nums2[index]);
			}
			break;
		}

		size_t position = binSearch(nums1, startPosition, nums1.size() - 1, nums2[index]);
		if (nums2[index] > nums1[position])
		{
			nums1.insert(nums1.begin() + position + 1, nums2[index]);
			startPosition = position + 1;
		}
		else
		{
			nums1.insert(nums1.begin() + position, nums2[index]);
			startPosition = position;
		}
	}

	if (nums1.size() % 2 == 1)
	{
		return nums1[nums1.size() / 2];
	}
	else
	{
		return (static_cast<double>(nums1[nums1.size() / 2]) + static_cast<double>(nums1[nums1.size() / 2 - 1])) / 2.0;
	}
}

int main()
{
	vector<int> vec1 = { 1, 1, 2, 3, 6};
	vector<int> vec2 = { 2, 3, 6, 13, 19, 25 };
	
	double median = findMedianSortedArrays(vec1, vec2);

	for (auto it = vec1.begin(); it != vec1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n" << median << endl;

	system("pause");
	return 0;
}