/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

/*
priority_queue<Type, Container, Functional>
Type 就是数据类型，Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector），Functional 就是比较的方式，当需要用自定义的数据类型时才需要传入这三个参数，使用基本数据类型时，只需要传入数据类型，默认是大顶堆
--------------------- 
*/

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq; //最小堆 找 第k大元素
        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++)
        {
            int t = pq.top();
            if (nums[i] > t)
            {
                pq.pop();
                pq.push(nums[i]);
            }
            else
            {
                continue;
            }
        }
        return pq.top();
    }
};
