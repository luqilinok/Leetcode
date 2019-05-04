/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int even = 0;           //偶数位下标
        int odd = A.size() - 1; //奇数位下标

        while (even < A.size() && odd > 0)
        {
            while (even < A.size() && (A[even] & 1) == 0) //A[even]是偶数
            {
                even += 2;
            }
            while (odd > 0 && (A[odd] & 1) == 1)  //A[odd]是奇数
            {
                odd -= 2;
            }
            if (even < A.size() && odd > 0)   
            {
                int temp = A[even];
                A[even] = A[odd];
                A[odd] = temp;
                even += 2;
                odd -= 2;
            }
        }
        return A;
    }
};
