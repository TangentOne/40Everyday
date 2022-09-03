#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums)
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
                return k;
            }
        }
        return -1;
    }

    void DeletePtr()
    {
        delete[] ptr;
    }
private:
    int* ptr;
};

int main()
{
    Solution tool;
    vector<int>num = {1,1,1};
    cout<<tool.findRepeatNumber(num);
    tool.DeletePtr();
   
}
