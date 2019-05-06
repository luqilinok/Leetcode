/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string temp = "";
        helper(res, temp, n, n);
        return res;
    }
    void helper(vector<string> &res, string temp, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            res.push_back(temp);
            return;
        }
        if (left > 0)
        {
            helper(res, temp + "(", left - 1, right);
        }
        if (right > left)
        {
            helper(res, temp + ")", left, right - 1);
        }
    }
};
