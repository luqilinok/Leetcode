/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (33.97%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    5.7K
 * Total Submissions: 16.8K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        //用unordered_set存字典，方便查找
        unordered_set<string> word_set(wordList.begin(), wordList.end());

        unordered_map<string, int> depth; //记录层数  key：单词  value：层数
        depth[beginWord] = 1;

        //检测字典中是否有endWord
        if (word_set.count(endWord) == 0)
            return 0;

        queue<string> q;
        q.push(beginWord);
        //首先将开始单词加入队列，当队列不为空时，进入循环
        while (!q.empty())
        {
            //循环开始时，队首出队
            string cur = q.front();
            q.pop();
            //对于当前字符串，每一位进行从a-z的替换
            for (int i = 0; i < cur.size(); i++)
            {
                string temp = cur;
                for (char x = 'a'; x <= 'z'; x++)
                {
                    if (x == cur[i])
                        continue;
                    temp[i] = x;
                    //若替换后的单词存在于字典中，并且之前没有被访问过（防止变过去又变回来形成环），则将其加入队尾
                    if (word_set.count(temp) && depth[temp] == 0)
                    {
                        depth[temp] = depth[cur] + 1;
                        if (endWord == temp)
                            return depth[temp];
                        q.push(temp);
                    }
                }
            }
        }
        return 0;
    }
};
