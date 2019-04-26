/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res; //保存结果
        TreeNode *p = root;
        if (!p)
        {
            return res;
        }
        queue<TreeNode *> Queue; //队列保存节点的指针
        Queue.push(p);           //根节点进入队列
        while (!Queue.empty())
        {
            int count = Queue.size();
            vector<int> ivec;
            while (count != 0)
            {
                p = Queue.front();
                Queue.pop();
                ivec.push_back(p->val);
                if (p->left)
                {
                    Queue.push(p->left);
                }
                if (p->right)
                {
                    Queue.push(p->right);
                }
                count--;
            }
            res.push_back(ivec);
        }
        return res;
    }
};
