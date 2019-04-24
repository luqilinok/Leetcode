/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.89%)
 * Total Accepted:    73.1K
 * Total Submissions: 222K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // 纵向扫描
        string str = "";
        if (strs.empty())
            return "";
        int i, j;
        int v_size = strs.size();
        int min_length = strs[0].size();
        for (int k = 1; k < v_size; k++)
        {
            int len = strs[k].size();
            if (len < min_length)
                min_length = len;
        }

        for (i = 0; i < min_length; i++)
        {
            for (j = 0; j < v_size - 1; j++)
            {
                if (strs[j][i] != strs[j + 1][i])
                {
                    return str;
                }
            }
            str += strs[j][i];
        }
        return str;
    }
};
