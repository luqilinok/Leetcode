/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution     //利用二分查找
{
public:
    int firstBadVersion(int n)
    {
        long start = 1, end = n;
        int res = -1;
        while (start <= end)
        {
            long mid = (start + end) / 2;
            if (isBadVersion(mid))
            {
                res = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return res;
    }
};
