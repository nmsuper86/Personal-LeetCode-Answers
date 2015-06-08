#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	ListNode *ptr1 = l1, *ptr2 = l2;

	ListNode *result = new ListNode(0), *resultPtr = result;

	bool add1Flag = false;

	for (; ptr1 != NULL || ptr2 != NULL; ptr1 = ((ptr1) ? ptr1->next : ptr1), ptr2 = ((ptr2) ? ptr2->next : ptr2))
	{
		int val = 0;
		if (add1Flag)
		{
			val++;
			add1Flag = false;
		}

		val += ((ptr1)?ptr1->val:0) + ((ptr2)?ptr2->val:0);
		add1Flag = val / 10;
		val %= 10;

		resultPtr->next = new ListNode(val);
		resultPtr = resultPtr->next;
	}

	if (add1Flag)
	{
		resultPtr->next = new ListNode(1);
	}

/*	if (ptr1)
	{
		for (; ptr1 != NULL; ptr1 = ptr1->next)
		{
			int val = ptr1->val;
			if (add1Flag)
			{
				val++;
				add1Flag = val / 10;
				val %= 10;
			}
			resultPtr->next = new ListNode(val);
			resultPtr = resultPtr->next;
		}
		if (add1Flag)
		{
			resultPtr->next = new ListNode(1);
		}
	}

	if (ptr2)
	{
		for (; ptr2 != NULL; ptr2 = ptr2->next)
		{
			int val = ptr2->val;
			if (add1Flag)
			{
				if (val == 9)
				{
					val == 0;
				}
				else
				{
					val += 1;
					add1Flag = false;
				}
			}
			resultPtr->next = new ListNode(val);
			resultPtr = resultPtr->next;
		}
		if (add1Flag)
		{
			resultPtr->next = new ListNode(1);
		}
	} */

	return result->next;
}

int main()
{
	ListNode* num1 = new ListNode(9);
	num1->next = new ListNode(8);
//	num1->next->next = new ListNode(3);

	ListNode* num2 = new ListNode(1);
//	num2->next = new ListNode(6);
//	num2->next->next = new ListNode(4);

	ListNode* num = addTwoNumbers(num1, num2);

	for (; num != nullptr; num++)
	{
		cout << num->val;
		num = num->next;
	}

	system("pause");
	return 0;
}
