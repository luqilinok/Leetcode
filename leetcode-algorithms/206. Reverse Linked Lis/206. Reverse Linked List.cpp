/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *p = head;
        ListNode *t;

        ListNode *h = new ListNode(0);
        h->next = nullptr;
        head = h;
        while (p != nullptr)
        {
            t = p->next;
            p->next = head->next;
            head->next = p;
            p = t;
        }
        head = head->next;
        return head;
    }
};
