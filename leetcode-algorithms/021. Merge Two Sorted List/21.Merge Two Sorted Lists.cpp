/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *cur = new ListNode(0); //唯一的构造函数 ListNode(int x) 需要单参数才能够调用
        ListNode *newhead = cur;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if (l1 != nullptr)
            cur->next = l1;
        if (l2 != nullptr)
            cur->next = l2;
        return newhead->next;
    }
};
