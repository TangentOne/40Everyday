#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int top = 0;
        int end = nums.size() - 1;
      //二分查找
        while (top<=end)
        {
            int mid = (top + end) / 2;
            if (nums[mid] == mid)
                top = mid + 1;
            else end = mid - 1;
        }
        return top;
    }
};

int main()
{
    Solution tool;
    vector<int>num = { 0,1,2 };
    cout<<tool.missingNumber(num);
}
