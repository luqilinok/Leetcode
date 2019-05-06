/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> rtn;
        solve(0, nums, rtn);
        return rtn;
    }

    void solve(int index, vector<int> &nums, vector<vector<int>> &rtn)
    {
        if (index == nums.size() - 1)
        {
            rtn.push_back(nums);
            return;
        }
        else
        {
            for (int i = index; i < nums.size(); i++)
            {
                swap(nums[index], nums[i]);
                solve(index + 1, nums, rtn);
                swap(nums[index], nums[i]);
            }
        }
    }
};
