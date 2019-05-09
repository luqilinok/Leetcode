/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
class Solution   //组合法：机器人一定会走m+n-2步，即从m+n-2中挑出m-1步向下走不就行了吗？即C（（m+n-2），（m-1））。
{
public:
    int combNumFom(int n, int m)
    {
        if (m > n)
            return 0;
        if (m < n / 2.0)
            m = n - m;
        double arg1 = 0;
        for (int i = m + 1; i <= n; i++)
        {
            arg1 += log(double(i));
        }
        double arg2 = 0;
        for (int i = 1; i <= n - m; i++)
        {
            arg2 += log(double(i));
        }
        double res1 = arg1 - arg2;
        int res = (int)round(exp(res1));
        return res;
    }

    int uniquePaths(int m, int n)
    {
        return combNumFom(m + n - 2, n - 1);
    }
};
