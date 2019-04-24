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
        ListNode *node = head;
        ListNode *pre = NULL;
        ListNode *next = NULL;

        while (node != NULL)
        {
            next = node->next; //保存下一个节点
            node->next = pre;  //将前一个节点赋给当前节点的下一个
            pre = node;        //当前节点赋值给pre指针
            node = next;       //下一个节点赋值给node指针
        }
        return pre;
    }
};
