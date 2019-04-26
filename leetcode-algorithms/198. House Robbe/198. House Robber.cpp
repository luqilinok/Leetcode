/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (i >= 2)
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]); //状态方程，dp[i]表示小偷到达某一家时目前为止偷窃的最大值，由前一家是否被偷分为两种状态。
            else
                dp[i] = max(dp[i - 1], nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
