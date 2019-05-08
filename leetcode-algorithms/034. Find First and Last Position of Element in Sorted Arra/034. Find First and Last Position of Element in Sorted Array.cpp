/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> res = {-1, -1};
        if (n == 0)
        {
            return res;
        }
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                left = mid;
                right = mid;
                while (left > 0 && nums[left] == nums[left - 1])
                {
                    left--;
                }
                while (right < n - 1 && nums[right] == nums[right + 1])
                {
                    right++;
                }
                res[0] = left;
                res[1] = right;
                return res;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return res;
    }
};
