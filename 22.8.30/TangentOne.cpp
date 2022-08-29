#include<iostream>
using namespace std;

class _40Everyday 
{
public:
	void sayHello() const
	{
		cout << "Start 40Everyday from now on.\n";
	}
private:
};


int main()
{
	const _40Everyday sol;
	sol.sayHello();
}
