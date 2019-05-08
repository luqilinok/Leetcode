/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int length = nums.size();
        if (length < 1)
        {
            return;
        }
        int start = -1, end = length - 1, index = 0;
        while (index <= end)
        {
            if (nums[index] == 2)
            {
                int temp = nums[index];
                nums[index] = nums[end];
                nums[end] = temp;
                end--;
            }
            else if (nums[index] == 0)
            {
                start++;
                if (index != start)
                {
                    int temp = nums[index];
                    nums[index] = nums[start];
                    nums[start] = temp;
                }
                else
                {
                    index++;
                }
            }
            else
            {
                index++;
            }
        }
    }
};
