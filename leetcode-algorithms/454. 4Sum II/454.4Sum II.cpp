/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int res = 0;
        unordered_map<int, int> map;
        for (const auto &a : A)
        {
            for (const auto &b : B)
            {
                map[a + b]++;
            }
        }
        for (const auto &c : C)
        {
            for (const auto &d : D)
            {
                res += map[-(c + d)];
            }
        }
        return res;
    }
};
