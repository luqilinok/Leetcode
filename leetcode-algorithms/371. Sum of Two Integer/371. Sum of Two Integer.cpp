/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */
class Solution
{
public:
    int getSum(int a, int b)
    {
        vector<int> vec{a, b};
        auto sum = accumulate(vec.begin(), vec.end(), 0);
        return sum;
    }
};
