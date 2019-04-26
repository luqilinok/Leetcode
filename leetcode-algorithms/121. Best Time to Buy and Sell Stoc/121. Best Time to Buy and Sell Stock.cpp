/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        int temp = prices[0];
        for (int i = 1; i < n; i++)
        {
            int diff = prices[i] - temp;
            if (diff >= 0)
            {
                profit = max(profit, diff);
            }
            else
            {
                temp = prices[i];
            }
        }
        return profit;
    }
};
