/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left != nullptr && root->right != nullptr)
        {
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);

            if (left < right)
            {
                return right + 1;
            }
            else
            {
                return left + 1;
            }
        }
        else if (root->left == nullptr && root->right != nullptr)
        {
            return maxDepth(root->right) + 1;
        }
        if (root->left != nullptr && root->right == nullptr)
        {
            return maxDepth(root->left) + 1;
        }
        else
        {
            return 1;
        }
        }
};
