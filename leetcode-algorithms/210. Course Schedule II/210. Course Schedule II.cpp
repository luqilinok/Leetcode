/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */


//dfs解法
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        record = vector<int>(numCourses, 0);
        pre = vector<vector<int>>(numCourses);
        for (auto v : prerequisites)
        {
            pre[v[0]].push_back(v[1]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (record[i] == 0 && !dfs(i))
            {
                ans.clear();
                break;
            }
        }
        return ans;
    }

private:
    vector<int> record;
    vector<vector<int>> pre;
    vector<int> ans;
    bool dfs(int index)
    {
        if (record[index] == 2)
        {
            return true;
        }
        if (record[index] == 1)
        {
            return false;
        }
        record[index] = 1;
        for (auto i : pre[index])
        {
            if (!dfs(i))
            {
                return false;
            }
        }
        ans.push_back(index);
        record[index] = 2;
        return true;
    }
};
