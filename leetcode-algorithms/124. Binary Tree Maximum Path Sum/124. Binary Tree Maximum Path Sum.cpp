/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (35.03%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    7K
 * Total Submissions: 19.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
 * 
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
    int maxPathSum(TreeNode *root)
    {
        int max_val = INT_MIN;
        dfs(root, max_val);
        return max_val;
    }

    int dfs(TreeNode *root, int &max_val)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left_val = dfs(root->left, max_val);
        int right_val = dfs(root->right, max_val);
        if (left_val > 0 && right_val > 0)
        {
            max_val = max(max_val, right_val + root->val + left_val);
            return max(right_val, left_val) + root->val;
        }
        if (right_val > 0)
        {
            max_val = max(max_val, root->val + right_val);
            return root->val + right_val;
        }
        if (left_val > 0)
        {
            max_val = max(max_val, root->val + left_val);
            return root->val + left_val;
        }
        else
        {
            max_val = max(max_val, root->val);
            return root->val;
        }
    }
};
