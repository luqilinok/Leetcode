/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (51.90%)
 * Total Accepted:    27.2K
 * Total Submissions: 52.4K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int x[26] = {0};
        int y[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            x[s[i] - 'a']++;    //s[i]-'a'表示数组s中下标为i的数和'a'的距离，eg：'b'-'a'==1、'c'-'a'==2,所以表达式x[s[i] - 'a']++可以用来计数
        }
        for (int i = 0; i < t.size(); i++)
        {
            y[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (x[i] != y[i])
            {
                return false;
            }
        }
        return true;
    }
};
