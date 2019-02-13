#include<iostream>
#include<unordered_map>
#include<minmax.h>

using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int result = 0, left = -1, n = s.size();
		unordered_map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			if (m.count(s[i])&& m[s[i]]>left)
			{
				left = m[s[i]];
			}
			m[s[i]] = i;
			result = max(result,i-left);
		}
		return result;
	}
};