/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int distance = 0;
        while (x || y)
        {
            if (x % 2 != y % 2)
            {
                distance++;
            }
            x = x >> 1;
            y = y >> 1;
        }
        return distance;
    }
};
