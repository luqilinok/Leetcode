/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
class Solution
{
public:
    int numSquares(int n)
    {
        while (n % 4 == 0)
        {
            n /= 4;
        }
        if (n % 8 == 7) //如果一个数除以8余7的话，那么肯定是由4个完全平方数组成
        {
            return 4;
        }
        for (int a = 0; a * a <= n; a++)
        {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n)
            {
                return !!a + !!b; //感叹号!表示逻辑取反，那么一个正整数逻辑取反为0，再取反为1，所以用两个感叹号!!的作用就是看a和b是否为正整数，都为正整数的话返回2，只有一个是正整数的话返回1
            }
        }
        return 3;
    }
};
