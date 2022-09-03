#include<iostream>
#include<vector>
using namespace std; 
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        if (n < 1)
            return 0;
        int m = n / 2;
        int count = 0;
        if (nums[m] > target)
        {
            for (int i = 0; i < m; i++)
            {
                if (nums[i] == target)
                {
                    count++;
                }
            }
            return count;
        }

        if (nums[m] < target)
        {
            for (int i = m+1; i < n; i++)
            {
                if (nums[i] == target)
                {
                    count++;
                }
            }
            return count;
        }

        if (nums[m] == target)
        {
            int m1 = m;
            int m2 = m;
            while (m1 >= 0 && nums[m1] == target)
            {             
                    m1--;
                    count++;              
               
            }
            while ( m2 < n && nums[m2] == target)
            {
                m2++;
                count++;
            }
            return count - 1;
        }
        return 0;
    }
};
int main()
{
    Solution tool;
    vector<int>num = { 5,7,7,8,8,10};

    cout << tool.search(num,8);
}
