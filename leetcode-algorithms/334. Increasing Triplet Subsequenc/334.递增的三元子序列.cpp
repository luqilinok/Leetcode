/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int a = INT_MAX;
        int b = INT_MAX;

        for (auto e : nums)
        {
            if (e <= a)
            {
                a = e;
            }
            else if (e <= b)
            {
                b = e;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
