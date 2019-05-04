/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result; // 存放结果数组
        map<double, int> map;          // 存放异位词映射
        int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

        for (auto str : strs)
        {
            double feature = 1; // 字符串特征值

            // 计算所有到此与的结果
            for (auto i = 0; i < str.size(); ++i)
            {
                feature *= prime[str.at(i) - 'a']; // 计算字符串的特征值
            }

            auto iter = map.find(feature); // 从hash中查找特征值的字符串是否存在
            if (iter == map.end())
            { // 如果是新特征值的字符串，则添加到新的特征值上
                vector<string> temp{str};
                result.push_back(temp);
                map.insert(make_pair(feature, result.size() - 1)); // 记录相应特征值所对应的索引位置
            }
            else
            { // 如果找到相同特征值的映射，则在相应的位置添加当前字符串
                result.at(iter->second).push_back(str);
            }
        }
        return result;
    }
};
