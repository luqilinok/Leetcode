/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        for(auto &i:A)
        {
            i=i*i;
        }
        sort(A.begin(),A.end());
        return A;
    }
};
