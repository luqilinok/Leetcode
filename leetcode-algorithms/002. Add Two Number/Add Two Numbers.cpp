#include<iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution 
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode dummy(0);
		ListNode *p = &dummy;

		int carry = 0;

		while (l1||l2)
		{
			int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);

			carry = sum / 10;;
			sum = sum % 10;

			p->next = new ListNode(sum);
			p = p->next;
			if (l1)
			{
				l1 = l1->next;
			}
			if (l2)
			{
				l2 = l2->next;
			}
		}

		if (carry!=0)
		{
			p->next = new ListNode(carry);
			p = p->next;
		}
		return dummy.next;
	}
};


