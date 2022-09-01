#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string &s, int n) 
    {
        string Tem;
        for (int i = 0; i < n; i++)
        {
            Tem += s[i];
        }
        //Tem = s.substr(0, n);

        for (int i = 0; i < s.size() - n; i++)
        {
            s[i] = s[i + n];
        }

        for (int i = s.size() - n; i < s.size(); i++)
        {
            s[i] = Tem[i-s.size()+n];
        }

        return s;
    }
};

int main()
{
    Solution tool;
    string s1 = "code 40 linesSecond day to ";
    cout << tool.reverseLeftWords(s1, 13);
}
