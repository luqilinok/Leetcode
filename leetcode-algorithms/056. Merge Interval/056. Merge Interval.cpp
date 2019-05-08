/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
        {
            return intervals;
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (result.back().back() < intervals[i].front())
            {
                result.push_back(intervals[i]);
            }
            else
            {
                result.back().back() = max(result.back().back(), intervals[i].back());
            }
        }
        return result;
    }
};
