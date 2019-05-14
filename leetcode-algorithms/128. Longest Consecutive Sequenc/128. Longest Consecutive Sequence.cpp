/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (43.13%)
 * Likes:    103
 * Dislikes: 0
 * Total Accepted:    7.5K
 * Total Submissions: 17.2K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 
 * 要求算法的时间复杂度为 O(n)。
 * 
 * 示例:
 * 
 * 输入: [100, 4, 200, 1, 3, 2]
 * 输出: 4
 * 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 */
class Solution
{
public:
    int max(int a, int b)
    {
        if (a < b)
            return b;
        else
            return a;
    }

    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        vector<int> A(nums.size(), 0);
        A[0] = 1;
        int maxlen = A[0];

        for (int i = 1; i < nums.size(); i++)

        {
            if (nums[i] == nums[i - 1])
            {
                A[i] = A[i - 1];
                continue;
            }
            if (nums[i] - nums[i - 1] == 1)
            {
                A[i] = A[i - 1] + 1;
                maxlen = max(A[i], maxlen);
            }
            else
                A[i] = 1;
        }

        return maxlen;
    }
};
