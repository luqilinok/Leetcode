/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */


/*思路：分治法。

左下角的元素是这一行中最小的元素，同时又是这一列中最大的元素。比较左下角元素和目标：
若左下角元素等于目标，则找到
若左下角元素大于目标，则目标不可能存在于当前矩阵的最后一行，问题规模可以减小为在去掉最后一行的子矩阵中寻找目标
若左下角元素小于目标，则目标不可能存在于当前矩阵的第一列，问题规模可以减小为在去掉第一列的子矩阵中寻找目标
若最后矩阵减小为空，则说明不存在
*/
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
        {
            return false;
        }
        int i = 0;
        int j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            if (matrix[i][j] < target)
            {
                i++;
            }
            else if(matrix[i][j]>target)
            {
                j--;
            }
        }
        return false;
    }
};
