/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        for (auto prq : prerequisites)
        {
            graph[prq[1]].push_back(prq[0]);
        }
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (!judge(graph, visited, i))
            {
                return false;
            }
        }
        return true;
    }

    bool judge(vector<vector<int>> &graph, vector<int> &visited, int i)
    {
        if (visited[i] == -1)
        {
            return false;
        }
        if (visited[i] == 1)
        {
            return true;
        }
        visited[i] = -1;
        for (auto itm : graph[i])
        {
            if (!judge(graph, visited, itm))
            {
                return false;
            }
        }
        visited[i] = 1;
        return true;
    }
};
