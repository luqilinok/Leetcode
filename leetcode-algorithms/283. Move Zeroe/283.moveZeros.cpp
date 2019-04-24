/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (53.61%)
 * Total Accepted:    42.6K
 * Total Submissions: 79.5K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 说明:
 * 
 * 
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 * 
 * 
 */
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;   //记录0出现的次数
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                count++;
            }
            else
            {
                nums[i - count] = nums[i];
            }
        }
        for (int i = 0; i < count; i++)
        {
            nums[n - 1 - i] = 0;
        }
    }
};
