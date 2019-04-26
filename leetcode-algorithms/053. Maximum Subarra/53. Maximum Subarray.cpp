/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int len = nums.size();
        int sum;
        int temp;

        sum = temp = nums[0];

        for (int i = 1; i < len; i++)
        {
            if (temp < 0)
            {
                temp = nums[i];
            }
            else
            {
                temp += nums[i];
            }
            sum = temp > sum ? temp : sum;
        }
        return sum;
    }
};
