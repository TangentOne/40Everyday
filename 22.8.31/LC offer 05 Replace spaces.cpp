#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    const string replaceSpace(const string s)
    {
        string Tem;
        string Fin;
        int x = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]==' ')
            {
            
                Tem=s.substr(x, i-x);
                x = i+1;
                Fin = Fin + Tem + "%20";
            }
            if (s[i+1] == '\0')
            {
                Tem = s.substr(x, i+1 - x);
                Fin = Fin + Tem;
            }
        }
        
        return Fin;
    }
};

int main()
{
    Solution tool;
    string s1 = "It's first day to code 40 lines";
    s1 = tool.replaceSpace(s1);
    cout << s1;
}
