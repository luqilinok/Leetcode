/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 1 == nums[i])
                continue;
            int x = nums[i];
            while (x >= 1 && x <= nums.size() && x != nums[x - 1])
            {
                swap(x, nums[x - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 1 != nums[i])
                return i + 1;
        }
        return nums.size() + 1;
    }
};
