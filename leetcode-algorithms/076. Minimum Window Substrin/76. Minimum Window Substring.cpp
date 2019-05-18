/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (34.79%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    5.1K
 * Total Submissions: 14.8K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。
 * 
 * 示例：
 * 
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 * 
 * 说明：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */
class Solution
{
public:
    string minWindow(string S, string T)
    {
        string result;
        if (S.empty() || T.empty())
        {
            return result;
        }
        unordered_map<char, int> map;
        unordered_map<char, int> window;
        for (int i = 0; i < T.length(); i++)
        {
            map[T[i]]++;
        }
        int minLength = INT_MAX;
        int letterCounter = 0;
        for (int slow = 0, fast = 0; fast < S.length(); fast++)
        {
            char c = S[fast];
            if (map.find(c) != map.end())
            {
                window[c]++;
                if (window[c] <= map[c])
                {
                    letterCounter++;
                }
            }
            if (letterCounter >= T.length())
            {
                while (map.find(S[slow]) == map.end() || window[S[slow]] > map[S[slow]])
                {
                    window[S[slow]]--;
                    slow++;
                }
                if (fast - slow + 1 < minLength)
                {
                    minLength = fast - slow + 1;
                    result = S.substr(slow, minLength);
                }
            }
        }
        return result;
    }
};
