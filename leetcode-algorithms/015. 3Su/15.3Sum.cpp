/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> output;

        if (n <= 2)
        {
            return output;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || nums[i] != nums[i - 1])
            {
                int sum = -nums[i];
                int l = i + 1, r = n - 1;
                while (l < r)
                {
                    if (nums[l] + nums[r] == sum)
                    {
                        output.push_back(vector<int>{nums[i], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1])
                        {
                            l++;
                        }
                        while (l < r && nums[r] == nums[r - 1])
                        {
                            r--;
                        }
                        l++, r--;
                    }
                    else if (nums[l] + nums[r] < sum)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }
        return output;
    }
};
