/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */
class Solution
{
public:
    int titleToNumber(string s)
    {
        int col = 0;
        for (size_t i = s.size(); i > 0; i--)
        {
            col += (s[i - 1] - 'A' + 1) * pow(26, (s.size() - i));
        }
        return col;
    }
};
