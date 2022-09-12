#include<iostream>
#include<ctime> 
using namespace std;

long long sum;
long long n;
namespace program1 {
	int work()
	{
		sum = 0;
		for (int i = 0; i < n; ++i)
			++sum;
		return sum;
	}

};

namespace program2 {
	int work()
	{
		sum = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				++sum;
		return sum;
	}
};

namespace program3 {
	int work()
	{
		sum = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n * n; ++j)
				++sum;
		return sum;
	}
};

namespace program4 {
	int work()
	{
		sum = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < i; ++j)
				++sum;
		return sum;
	}
};

namespace program5 {
	int work()
	{
		sum = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < i * i; ++j)
				for (int k = 0; k < j; ++k)
					++sum;
		return sum;
	}
};

namespace program6 {
	int work()
	{
		sum = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < i * i; ++j)
				if (j % i == 0)
					for (int k = 0; k < j; ++k)
						++sum;
		return sum;
	}
};

double getOneTime()
{
	time_t begin, end;
	double ret;
	begin = clock();
	int tottimes = program6::work();
	end = clock();
	//ret = double(end - begin) / CLOCKS_PER_SEC;
	ret = double(end - begin);
	return ret;
}



int main()
{
	n = 20;
	for (int i = 1; i <= 5; ++i)
	{
		n *= 2;
		cout << "N=" << n << "   Time=" << getOneTime()<<"  ";
		cout << "Sum=" << sum << endl;
	}
}