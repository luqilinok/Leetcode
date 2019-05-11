/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int len = tasks.size();
        vector<int> hash(26, 0);
        for (int i = 0; i < len; i++)
        {
            hash[tasks[i] - 'A']++;
        }
        sort(hash.begin(), hash.end());
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            if (hash[i] == hash.back())
            {
                cnt++;
            }
        }
        return max(len, (n + 1) * (hash.back() - 1) + cnt);
    }
};
