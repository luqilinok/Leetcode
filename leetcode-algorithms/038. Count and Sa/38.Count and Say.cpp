/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (49.20%)
 * Total Accepted:    28.1K
 * Total Submissions: 57K
 * Testcase Example:  '1'
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 
 * 注意：整数顺序将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 */
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        if (n == 2)
            return "11";


        int i = 0, count = 1;
        string s1={"11"};
        string s2;   //s2作为一个中间变量
        for (i = 3; i <= n; ++i)
        {
            for (size_t j = 0; j < s1.size(); ++j)
            {
                if (s1[j] == s1[j + 1])
                {
                    ++count;
                }
                else
                {
                    string s = to_string(count);
                    s2.append(s);  //将s追加到s2，返回一个指向s2的引用
                    s2.insert(s2.size(), 1, s1[j]);
                    count = 1;
                }
            }
            s1 = s2;
            s2.clear();
        }
        return s1;
    }
};
