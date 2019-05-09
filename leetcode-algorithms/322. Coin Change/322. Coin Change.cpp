/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (coins.size() <= 0)
            return -1;
        vector<int> res(amount + 1, 0);
        for (int i = 1; i < amount + 1; i++)
        {
            res[i] = INT_MAX;
            for (int j = 0; j < coins.size(); j++)
            {
                if (i >= coins[j] && res[i - coins[j]] != -1)
                {
                    res[i] = min(res[i - coins[j]] + 1, res[i]);
                }
            }
            if (res[i] == INT_MAX)
                res[i] = -1;
        }
        return res[amount];
    }
};
