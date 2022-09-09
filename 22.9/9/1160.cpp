#include<iostream>
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}



class ListItem
{
public:
	void setLeft(int x) { left = x; }
	void setRight(int x) { right = x; }
	int getNext()const { return right; }
	int getLast()const { return left; }
private:
	int left, right;
};
const int maxn = 1e5;
ListItem list[maxn];


void insert(int left, int right)
{

}

void insertLeft(int x)
{

}

void insertRight(int x)
{

}

void ini()
{

}

void work()
{

}

int main()
{
	ini();
	work();

}