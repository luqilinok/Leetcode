/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) //用快慢指针法：快指针一次走2个节点、慢指针一次走1个节点，如果两个指针相遇，证明有环存在
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr && slow != nullptr)
        {
            fast = fast->next->next; //快指针一次走两个节点
            slow = slow->next;       //慢指针一次走一个节点
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};
