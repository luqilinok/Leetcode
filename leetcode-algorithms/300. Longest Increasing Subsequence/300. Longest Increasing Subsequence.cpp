/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return NULL;
        }
        if (nums.size() == 1)
        {
            return 1;
        }

        int count = 1;
        size_t length = nums.size();
        vector<size_t> dp(length, 1);
        for (size_t i = 0; i < length; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        vector<size_t>::iterator max = max_element(dp.begin(), dp.end());
        return *max;
    }
};
