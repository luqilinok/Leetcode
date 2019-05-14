/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> v(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                int count = 0;
                if (i - 1 >= 0 && board[i - 1][j] == 1)
                    count++; //左
                if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1)
                    count++; //左上
                if (j - 1 >= 0 && board[i][j - 1] == 1)
                    count++; //上
                if (i - 1 >= 0 && j + 1 < board[0].size() && board[i - 1][j + 1] == 1)
                    count++; //右上
                if (j + 1 < board[0].size() && board[i][j + 1] == 1)
                    count++; //右
                if (i + 1 < board.size() && j + 1 < board[0].size() && board[i + 1][j + 1] == 1)
                    count++; //右下
                if (i + 1 < board.size() && board[i + 1][j] == 1)
                    count++; //下
                if (i + 1 < board.size() && j - 1 >= 0 && board[i + 1][j - 1] == 1)
                    count++;          //左下
                if (board[i][j] == 1) //live
                {
                    if (count != 2 && count != 3)
                    {
                        v[i][j] = 0;
                    }
                    else
                    {
                        v[i][j] = 1;
                    }
                }
                else //dead
                {
                    if (count == 3)
                    {
                        v[i][j] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                board[i][j] = v[i][j];
            }
        }
    }
};
