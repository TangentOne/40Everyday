#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        vector<int> numsss(nums.size());
        numsss[0] = nums[0];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            vector<int> numss = nums;
            for (int j = 0; j <= i; j++)
            {
                numss[j + 1] += numss[j];

            }
            numsss[i + 1] = numss[i + 1];

        }
        return numsss;
    }

};
