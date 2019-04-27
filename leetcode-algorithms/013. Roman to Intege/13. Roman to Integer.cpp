/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
class Solution
{
public:
    int romanToInt(string s) //首先建立一个HashMap来映射符号和值，然后对字符串从左到右来，如果当前字符代表的值不小于其右边，就加上该值；否则就减去该值。以此类推到最左边的数，最终得到的结果即是答案
    {
        map<char, int> romMap;
        romMap['M'] = 1000;
        romMap['D'] = 500;
        romMap['C'] = 100;
        romMap['L'] = 50;
        romMap['X'] = 10;
        romMap['V'] = 5;
        romMap['I'] = 1;

        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (romMap[s[i]] >= romMap[s[i + 1]])
            {
                result += romMap[s[i]];
            }
            else
            {
                result -= romMap[s[i]];
            }
        }
        return result;
    }
};
