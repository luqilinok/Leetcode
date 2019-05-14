/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.empty())
            return res;
        res.reserve(matrix.size() * matrix[0].size());  //调整vector容量大小
        int top = 0, left = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;
        auto cur = 0;
        //爱的魔力转圈圈
        while (bottom >= top || right >= left)
        {
            if (bottom >= top)
            {
                for (cur = left; cur <= right; ++cur)
                    res.push_back(matrix[top][cur]);
            }
            //上边框下移
            ++top;
            if (right >= left)
            {
                for (cur = top; cur <= bottom; ++cur)
                    res.push_back(matrix[cur][right]);
            }
            //右边框左移
            --right;
            if (bottom >= top)
            {
                for (cur = right; cur >= left; --cur)
                    res.push_back(matrix[bottom][cur]);
            }
            //底边框上移
            --bottom;
            if (right >= left)
            {
                for (cur = bottom; cur >= top; --cur)
                    res.push_back(matrix[cur][left]);
            }
            //左边框右移
            ++left;
        }
        return res;
    }
};
