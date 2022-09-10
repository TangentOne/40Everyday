#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int top = 0;
        int end = nums.size() - 1;
        int mid = (top + end) / 2;
        while (top <= end)
        {
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                top = mid + 1;
            else end = mid - 1;
            mid = (top + end) / 2;
        }

        return -1;
    }
};

int main()
{
    Solution tool;
    vector<int> num = { -1,0,3,5,9,12 };
    cout << tool.search(num, 3);
}
