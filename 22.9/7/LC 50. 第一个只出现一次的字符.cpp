#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) 
    {
        char Blank = ' ';
        int Record[26] = { 0 };
        int n = s.size();
        int First=0;
        for (int i = 0; i < n; i++)
        {
            int sign = s[i] - 97;
            Record[sign]++;
           

        }
        for (int j = 0; j < n; j++)
        {
             int First = s[j] - 97;
            if (Record[First] == 1)
                return s[j];
        }
        return Blank;
    }
};

int main()
{
    Solution tool;
    string s = "eighthdaytocode";
    cout << tool.firstUniqChar(s);
}
