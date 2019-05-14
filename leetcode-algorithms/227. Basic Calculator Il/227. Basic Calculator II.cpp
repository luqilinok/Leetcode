/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 *
 * https://leetcode-cn.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (31.05%)
 * Likes:    36
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 9.5K
 * Testcase Example:  '"3+2*2"'
 *
 * 实现一个基本的计算器来计算一个简单的字符串表达式的值。
 * 
 * 字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。
 * 
 * 示例 1:
 * 
 * 输入: "3+2*2"
 * 输出: 7
 * 
 * 
 * 示例 2:
 * 
 * 输入: " 3/2 "
 * 输出: 1
 * 
 * 示例 3:
 * 
 * 输入: " 3+5 / 2 "
 * 输出: 5
 * 
 * 
 * 说明：
 * 
 * 
 * 你可以假设所给定的表达式都是有效的。
 * 请不要使用内置的库函数 eval。
 * 
 * 
 */
class Solution
{
public:
    int calculate(string s)
    {
        stack<char> sign;
        stack<int> nums;
        int i = 0, s_len = s.size();
        int nums_top2, nums_top1;
        char sign_top;
        while (i < s_len)
        {
            if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-')
                sign.push(s[i]);
            else if (isdigit(s[i]))
            {
                int temp = 0;
                while (i < s_len && isdigit(s[i]))
                    temp = temp * 10 + (s[i++] - '0');
                i--;
                if (!sign.empty() && (sign.top() == '*' || sign.top() == '/'))
                {
                    nums_top2 = nums.top();
                    nums.pop();
                    sign_top = sign.top();
                    sign.pop();
                    if (sign_top == '*')
                        nums.push(nums_top2 * temp);
                    else if (sign_top == '/')
                        nums.push(nums_top2 / temp);
                }
                else
                    nums.push(temp);
            }
            i++;
        }
        stack<char> sign_t;
        while (!sign.empty())
        {
            sign_t.push(sign.top());
            sign.pop();
        }
        stack<int> nums_t;
        while (!nums.empty())
        {
            nums_t.push(nums.top());
            nums.pop();
        }
        while (!sign_t.empty())
        {
            nums_top1 = nums_t.top();
            nums_t.pop();
            nums_top2 = nums_t.top();
            nums_t.pop();
            sign_top = sign_t.top();
            sign_t.pop();
            if (sign_top == '+')
                nums_t.push(nums_top1 + nums_top2);
            else if (sign_top == '-')
                nums_t.push(nums_top1 - nums_top2);
        }
        return nums_t.top();
    }
};
