/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode *root)
    {
        vector<int> values;
        inOrder(root, values);
        return isIncrease(values);
    }
    void inOrder(TreeNode *root, vector<int> &values)
    {
        if (!root)
        {
            return;
        }
        inOrder(root->left, values);
        values.push_back(root->val);
        inOrder(root->right, values);
    }
    bool isIncrease(vector<int> &values)
    {
        if (values.size() == 0)
        {
            return true;
        }
        int value = values[0];
        for (int i = 1; i < values.size(); i++)
        {
            if (values[i] <= value)
            {
                return false;
            }
            value = values[i];
        }
        return true;
    }
};
