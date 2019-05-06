/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        vector<int> temp;
        helper(nums, 0, temp, res);
        return res;
    }

    void helper(vector<int> &nums, int begin, vector<int> temp, vector<vector<int>> &res)
    {
        if (temp.size() <= nums.size())
        {
            res.push_back(temp);
        }
        for (int i = begin; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            helper(nums, i + 1, temp, res);
            temp.pop_back();
        }
    }
};
