/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (37.47%)
 * Total Accepted:    27.3K
 * Total Submissions: 72.8K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 案例:
 * 
 * 
 * s = "leetcode"
 * 返回 0.
 * 
 * s = "loveleetcode",
 * 返回 2.
 * 
 * 
 * 
 * 
 * 注意事项：您可以假定该字符串只包含小写字母。
 * 
 */
class Solution    //遍历一次字符串，然后找出第一个value为1的key即可。
{
public:
    int firstUniqChar(string s)
    {
        int x[26] = {0};
        for (auto i : s)
        {
            x[i - 'a']++;   //s[i]-'a'表示数组s中下标为i的数和'a'的距离，eg：'b'-'a'==1、'c'-'a'==2,所以表达式x[s[i] - 'a']++可以用来计数
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (x[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
