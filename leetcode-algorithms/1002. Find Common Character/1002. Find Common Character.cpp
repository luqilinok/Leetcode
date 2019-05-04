/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */
class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        vector<unordered_map<int, int>> v;
        vector<string> s;
        for (int i = 0; i < A.size(); i++)
        {
            unordered_map<int, int> m;
            for (auto a : A[i])
                ++m[a];
            v.push_back(m);
        }
        for (int i = 0; i < A[0].size(); i++)
        {
            int c = 0;
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j][A[0][i]] > 0)
                {
                    c++;
                    v[j][A[0][i]]--;
                }
            }
            c = c / v.size();
            if (c)
            {
                string str;
                str.push_back(A[0][i]);
                s.push_back(str);
            }
        }
        return s;
    }
};

