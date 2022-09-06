#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers)
    {
        int top = 0;
        int end = numbers.size() - 1;
        int mid = (top + end) / 2;
        while (top < end)
        {
            if (numbers[mid] > numbers[end])
                top = mid + 1;
            else if (numbers[mid] < numbers[end])
                end = mid;
            else end--;
            mid = (top + end) / 2;
        }
        return numbers[end];
    }
};


int main()
{
    Solution tool;
    vector<int>num = { 3,4,5,1,2 };
    cout << tool.minArray(num);
}
