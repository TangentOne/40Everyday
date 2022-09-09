#include<iostream>
using namespace std;

string postfix;


inline void in() { cin >> postfix; }
const int maxStack=100;

class Stack {
public:
	int pop()
	{
		if (!top) { cerr << "Stack Empty"; exit(1); }
		return stack[top--];
	}

	void push(int x)
	{
		if (top == maxStack) { cerr << "Stack over flow"; exit(1); }
		stack[++top] = x;
		return;
	}

	int getSize() const { return top; }

private:
	int top;
	int stack[maxStack];
};

Stack operand;
//int flag;

void work()
{
	
	for (int i = 0; postfix[i] != '@'; ++i)
	{
		//flag = 1;
		//if (postfix[i] == '-' && isdigit(postfix[i + 1])) { flag = -1; i++; }
		if (isdigit(postfix[i])) 
		{
			int x = 0;
			while (postfix[i] != '.')
			{
				x = x*10+ postfix[i++] -'0';
			}
			operand.push(x);
		}
		else
		{
			int x, y,z;
			x = operand.pop(); y = operand.pop(); z = 0;
			switch (postfix[i])
			{
			case('+'):z = y + x; break;
			case('-'):z = y - x; break;
			case('*'):z = y * x; break;
			case('/'):z = y / x; break;
			}
			operand.push(z);
		}
	}
}

void output()
{
	int ans = operand.pop();
	cout << ans << endl;
}

int main()
{
	in();
	work();
	output();
	return 0;
}