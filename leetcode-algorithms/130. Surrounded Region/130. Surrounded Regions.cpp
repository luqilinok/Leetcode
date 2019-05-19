/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (35.88%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    5.1K
 * Total Submissions: 14.1K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 示例:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 运行你的函数后，矩阵变为：
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * 解释:
 * 
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 */
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int i, j;
        int row = board.size();
        if (!row)
        {
            return;
        }
        int col = board[0].size();

        for (int i = 0; i < row; i++)
        {
            check(board, i, 0, row, col);
            if (col > 1)
            {
                check(board, i, col - 1, row, col);
            }
        }
        for (j = 1; j + 1 < col; j++)
        {
            check(board, 0, j, row, col);
            if (row > 1)
            {
                check(board, row - 1, j, row, col);
            }
        }
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (board[i][j] == '1')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void check(vector<vector<char>> &vec, int i, int j, int row, int col)
    {
        if (vec[i][j] == 'O')
        {
            vec[i][j] = '1';
            if (i > 1)
            {
                check(vec, i - 1, j, row, col);
            }
            if (j > 1)
            {
                check(vec, i, j - 1, row, col);
            }
            if (i + 1 < row)
            {
                check(vec, i + 1, j, row, col);
            }
            if (j + 1 < col)
            {
                check(vec, i, j + 1, row, col);
            }
        }
    }
};
