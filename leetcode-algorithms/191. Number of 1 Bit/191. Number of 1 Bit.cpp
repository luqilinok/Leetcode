/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int i = 0;
        while (n > 0)
        {
            if (n & 1 != 0)
            {
                i++;
            }
            n >>= 1;   //左移1位
        }
        return i;
    }
};
