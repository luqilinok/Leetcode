/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};
