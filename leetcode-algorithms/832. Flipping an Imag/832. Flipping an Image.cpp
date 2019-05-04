/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        if (A.size() == 0 || A[0].size() == 0)
        {
            return A;
        }
        int row = A.size();
        int col = A[row - 1].size();

        for (int i = 0; i < row; i++)
        {
            int mid = A[i].size() / 2;
            for (int j = 0; j < mid; j++)
            {
                int temp = A[i][j];
                A[i][j] = A[i][col - j - 1];
                A[i][col - j - 1] = temp;
            }

            for (int j = 0; j < col; j++)
            {
                if (A[i][j] == 0)
                {
                    A[i][j] = 1;
                }
                else if (A[i][j] == 1)
                {
                    A[i][j] = 0;
                }
            }
        }
        return A;
    }
};
