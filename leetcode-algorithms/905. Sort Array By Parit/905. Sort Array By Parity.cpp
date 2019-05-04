/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        if (A.empty())
        {
            return A;
        }
        int left = 0;
        int right = A.size() - 1;
        int temp;
        while (left < right)
        {
            if ((A[left] & 1) == 1 && (A[right] & 1) == 0) //&可以用来判断一个整数的奇偶，二进制的最末位为0表示该数是偶数，最末位为1表示该数为奇数
            {
                temp = A[left]; 
                A[left] = A[right];
                A[right] = temp;
            }
            else if ((A[left]&1)==0)
            {
                left++;
            }
            else if((A[right]&1)==1)
            {
                right--;
            }
        }
        return A;
    }
};
