#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int* findRepeatNumber(vector<int>& nums) 
    {
        int n = sizeof(nums) / sizeof(int);
        int i = 0;
        int a = 0;
        for (int j = 0; j < n; j++)
        {
            a = 0;
            for (int k = j + 1; k < n; k++)
            {
                
                if (nums[j] != -1)
                {
                    if (nums[j] == nums[k])
                        nums[k] = -1;
                    a = 1;
                }
            }
            if (a == 1)
            {
                Rnum[i] = nums[j];
                i++;
            }
        }
        p = &Rnum[0];
        return p;  
    }
    int number()
    {
        return sizeof(Rnum) / sizeof(int);
    }
private:
    vector<int>Rnum;
    int* p;
    
};

int main()
{
    Solution tool;
    vector<int>num = { 2, 3, 1, 0, 2, 5, 3 };
    int* point;
    point = tool.findRepeatNumber(num);
    int N = tool.number();
    for (int i = 0; i < N; i++)
    {
        cout << *(point + i) << " ";
    }
}
