/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
class Solution   //
{
public:
    int climbStairs(int n)
    {
        vector<int> ans(n + 1, 1);
        for (int i = 2; i <= n; i++)
        {
            ans[i] = ans[i - 1] + ans[i - 2];   //第i阶可以由第（i-1）阶向上爬1阶或第（i-2）阶向上爬2阶得到，所以到达第i阶就由这两种方法之和得到
        }
        return ans[n];
    }
};
