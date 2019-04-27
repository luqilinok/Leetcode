/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 3)
            return 0;
        vector<int> res(n, 1);
        res[0] = res[1] = 0;
        for (int i = 2; i < sqrt(n) + 1; i++)
        {
            if (res[i] == 1)
            {
                for (int j = i * i; j < n; j = j + i)
                    res[j] = 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += res[i];
        }
        return ans;
    }
};
