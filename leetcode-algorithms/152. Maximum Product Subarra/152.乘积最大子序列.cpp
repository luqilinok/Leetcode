/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 */
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int a = 1;
        int b = 1;
        int maxVal = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int aa = a * nums[i], bb = b * nums[i];
            a = min(nums[i], min(aa, bb));
            b = max(nums[i], max(aa, bb));

            maxVal = max(maxVal, b);
        }
        return maxVal;
    }
};
