/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
class Solution
{
public:
    vector<int> original;
    Solution(vector<int> &nums)
    {
        original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> ans = original;
        for (int i = 1; i < ans.size(); i++)
        {
            swap(ans[rand() % (i + 1)], ans[i]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
