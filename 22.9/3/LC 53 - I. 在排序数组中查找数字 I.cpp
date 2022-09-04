#include<iostream>
#include<vector>
using namespace std; 
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int top = 0;
        int end = nums.size()-1;
        int count = 0;
        if (end < 0)
            return 0;
        if (nums[top] > target || nums[end] < target)
            return 0;
        int mid = (top+end) / 2;
        while (nums[mid]<target)
        {
            if (top != end)
            {
                top = mid+1;
            }
            mid = (top + end) / 2;
            if (top == end && top == mid)
                break;
            
        }
        while (nums[mid]>target)
        {
            if (top != end)
            {
                end = mid-1;
            }
            mid=(top + end) / 2;
            if (top == end && top == mid)
                break;
            
        }
      
    for (int i = top; i <= end; i++)
    {
        if (nums[i] == target)
            count++;
    }
    return count;
     
        
    }
};
int main()
{
    Solution tool;
    vector<int>num = {0,1,2,3,4,4,4};

    cout << tool.search(num,2);
}
