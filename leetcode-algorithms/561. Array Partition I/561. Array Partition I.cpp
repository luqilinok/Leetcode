/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size() - 1; i += 2)
        {
            sum += nums[i];
        }
        return sum;
    }
};
