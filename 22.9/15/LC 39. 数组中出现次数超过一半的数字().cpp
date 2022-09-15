#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        int tem;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (nums[j] >= nums[j + 1])
                {
                    tem = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tem;
                }

            }
        }
        return nums[n / 2];
    }
   
};
