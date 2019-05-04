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
        int n = A.size();
        for (int i = 0; i < n; i++)
        {
            if ((i & 1) == 0) //i是偶数
            {
                if ((A[i] & 1) == 0) //如果A[i]是偶数，则进行下一个数的检测i和A[i]是否匹配
                {
                    continue;
                }
                else //如果A[i]不是偶数，则找到A[i]后离A[i]最近的数A[j]和A[i]交换位置
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if ((A[j] & 1) == 0)
                        {
                            int temp = A[i];
                            A[i] = A[j];
                            A[j] = temp;
                            break;
                        }
                    }
                }
            }
            if ((i & 1) == 1) //i是奇数
            {
                if ((A[i] & 1) == 1) //如果A[i]是奇数，则进行下一个数的检测i和A[i]是否匹配
                {
                    continue;
                }
                else //如果A[i]不是奇数，则找到A[i]后离A[i]最近的数A[j]和A[i]交换位置
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if ((A[j] & 1) == 1)
                        {
                            int temp = A[i];
                            A[i] = A[j];
                            A[j] = temp;
                            break;
                        }
                    }
                }
            }
        }
        return A;
    }
};
