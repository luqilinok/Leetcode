/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */
class Solution
{
public:
    int fib(int N)
    {
        if (N >= 2)
        {
            return fib(N - 1) + fib(N - 2);
        }
        else
        {
            return N;
        }
    }
};
