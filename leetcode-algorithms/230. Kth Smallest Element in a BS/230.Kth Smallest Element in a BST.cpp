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
    vector<int> result;
    void InOrderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left != NULL) //先遍历左子树
        {
            InOrderTraversal(root->left);
        }
        result.push_back(root->val); //遍历当前根节点
        if (root->right != NULL)     //遍历右子树
        {
            InOrderTraversal(root->right);
        }
    }
    int kthSmallest(TreeNode *root, int k)
    {
        InOrderTraversal(root); //中序遍历二叉搜索树
        return result[k - 1];
    }
};
