/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
 */
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> q;
        for (int i = 0; i < matrix.size();i++)
        {
            for (int j = 0; j < matrix[0].size();j++)
            {
                q.emplace(matrix[i][j]);
                if(q.size()>k)
                {
                    q.pop();
                }
            }
        }
        return q.top();
    }
};
