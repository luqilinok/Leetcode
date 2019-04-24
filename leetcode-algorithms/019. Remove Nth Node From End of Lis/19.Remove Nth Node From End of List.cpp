/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head, *slow = head;
        ListNode *pre = nullptr;
        if (head == nullptr)
            return nullptr;
        while (n > 1)
        {
            fast = fast->next;
            n--;
        }
        while (fast->next != nullptr)
        {
            pre = slow;
            fast = fast->next;
            slow = slow->next;
        }
        if (pre == nullptr)
            return slow->next;
        pre->next = slow->next;
        return head;
    }
};
