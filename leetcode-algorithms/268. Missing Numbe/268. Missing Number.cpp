/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = 0;
        for (auto s : nums)
        {

            if (s == n)
            {
                n++;
                continue;
            }
            break;
        }
        return n;
    }
};
