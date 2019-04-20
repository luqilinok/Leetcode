#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) 
	{
		int n = nums.size();
		if (n==0)
		{
			return 0;
		}
		else
		{
			int j = 0;
			for (int i = 1; i < n; i++)
			{
				if (nums[j]!=nums[i])
				{
					nums[++j] = nums[i];
				}
			}
			return j + 1;
		}
	}
};