#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        int n = arr.size();
        int tem;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < n - i-1; j++)
            {
                if (arr[j] > arr[j+1])
                {
                    tem = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tem;
                }
                    
            }
        }
        vector<int>res;
        res.assign(arr.begin(), arr.begin() + k);
        return res;
    }
};
int main()
{
    Solution tool;
    vector<int>array = { 12,2,3,45,55,6,67 };
    vector<int>res = tool.getLeastNumbers(array,3);
    for (int i = 0; i < 3; i++)
    {
        cout << res[i] << " ";
    }
}
