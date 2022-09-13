
#include<iostream>
#include<vector>
using namespace std;

     class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        ptr = NULL;
        ptr = new int[n];
        for (int i = 0; i < n; i++)
        {
            ptr[i] = 0;
        }

        for (int j = 0; j < n; j++)
        {
            ptr[nums[j]] += 1;
        }

        for (int k = 0; k < n; k++)
        {
            if (ptr[k] >= 2)
            {
                return true;
            }
        }
        return false;
    }

    void DeletePtr()
    {
        delete[] ptr;
    }
private:
    int* ptr;
};
    
