/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode *head)
    {
        string temp;
        ListNode *p = head;
        while (p != nullptr)
        {
            temp += p->val;
            p = p->next;
        }
        string t = temp;
        reverse(temp.begin(), temp.end());
        if (t == temp)
        {
            return true;
        }
        return false;
    }
};
