/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前K个高频元素
 */
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        using E = std::pair<int, int>; //
        std::priority_queue<E, std::vector<E>, std::greater<E>> minHeap;
        map<int, int> counter;

        for (auto e : nums)
        {
            counter[e]++;
        }

        for (auto &x : counter)
        {
            auto pair = make_pair(x.second, x.first);
            if (minHeap.size() == k)
            {
                if (pair < minHeap.top())
                {
                    continue;
                }
                minHeap.pop();
            }
            minHeap.push(std::move(pair));
        }
        std::vector<int> res(minHeap.size());
        k = res.size();
        while (!minHeap.empty())
        {
            res[--k] = minHeap.top().second;
            minHeap.pop();
        }
        return res;
    }
};
