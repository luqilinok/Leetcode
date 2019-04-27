/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

using unit32_t = unsigned int;
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        unit32_t ans = 0;
        int i = 32;
        while (i--)
        {
            ans <<= 1;  //将ans向左移动1位
            ans += n & 1;   //与运算中只有两位同时为1结果才为1，否则都是0
            n >>= 1;   //将n向右移动1位
        }
        return ans;
    }
};
