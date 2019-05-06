/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿的个数
 */
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        int nums = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int top = 0, down = grid.size() - 1, left = 0, right = grid[0].size() - 1;

        for (int i = top; i <= down; ++i)
        {
            for (int j = left; j <= right; ++j)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    nums++;
                    dfs200(grid, i, j, visited);
                }
            }
        }
        return nums;
    }

    void dfs200(vector<vector<char>> &grid, int x, int y, vector<vector<bool>> &visited)
    {
        if (x < 0 || x > grid.size() - 1 || y < 0 || y > grid[0].size() - 1)
            return;
        if (visited[x][y] || grid[x][y] == '0')
            return;
        visited[x][y] = true;

        // (x,y)的上下左右四个方向分别dfs
        dfs200(grid, x + 1, y, visited);
        dfs200(grid, x - 1, y, visited);
        dfs200(grid, x, y + 1, visited);
        dfs200(grid, x, y - 1, visited);
    }
};
