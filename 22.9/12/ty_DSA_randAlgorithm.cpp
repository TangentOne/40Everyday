#include<iostream>
#include<random>
#define RAND_MAX 2147483647
using namespace std;

int n;
const int maxn = 1e8;
int num[maxn];
std::default_random_engine generator;


class RandomGenerator
{
public:
	int randInt(int i, int j) const { std::uniform_int_distribution<int> distribution(i, j); return distribution(generator); }//×ó±ÕÓÒ¿ª
private:
}r;


time_t getClock()
{
	return clock();
}


namespace Algorithm1
{

	bool isUsed(int x, int end)
	{
		for (int i = 0; i < end; ++i) { if (num[i] == x) return true; }
		return false;
	}
	
	
	void Fill()
	{
		for (int i = 0; i < n; ++i)
		{
			int x = r.randInt(0, n);
			if (!isUsed(x, i)) { num[i] = x; }
			else { i--; continue; }
		}
		return;
	}


	void work()
	{
		int Nval[] = {250,500,1000,2000};
		time_t begin, end;
		for (auto x : Nval)
		{
			n = x;
			double tot=0;
			cout << "	N=" << n << ":\n";
			for (int j = 1; j <= 10; ++j)
			{
				begin = clock();
				Fill();
				end = clock();
				printf("		No.%d  and time=%d\n", j, end - begin);
				tot += end - begin;
			}
			tot /= 10;
			cout << "	Average Time:" << tot<<endl << endl;
		}
	}
	
}

namespace Algorithm2
{
	bool used[maxn];

	bool isUsed(int x)
	{
		return used[x];
	}


	void Fill()
	{
		for (int i = 0; i < n; ++i)
		{
			int x = r.randInt(0, n);
			if (!isUsed(x)) { used[x] = 1; num[i] = x; }
			else { i--; continue; }
		}
		return;
	}

	void initial()
	{
		for (int i = 0; i < n; ++i) used[i] = 0;
	}


	void work()
	{
		int Nval[] = { 2.5e4,5e4,1e5,2e5,4e5,8e5 };
		time_t begin, end;
		for (auto x : Nval)
		{
			n = x;
			double tot = 0;
			cout << "	N=" << n << ":\n";
			for (int j = 1; j <= 10; ++j)
			{
				initial();
				begin = clock();
				Fill();
				end = clock();
				printf("		No.%d  and time=%d\n", j, end - begin);
				tot += end - begin;
			}
			tot /= 10;
			cout << "	Average Time:" << tot << endl << endl;
		}
	}
}

namespace Algorithm3
{
	
	void Fill()
	{
		for (int i = 0; i < n; ++i) num[i] = i + 1;
		for(int i=1;i<n;++i)
		{
			swap(num[i], num[r.randInt(0, i)]);
		}
		return;
	}

	void work()
	{
		int Nval[] = { 1e5,2e5,4e5,8e5,1.6e6,3.2e6,6.4e6 };
		time_t begin, end;
		for (auto x : Nval)
		{
			n = x;
			double tot = 0;
			cout << "	N=" << n << ":\n";
			for (int j = 1; j <= 10; ++j)
			{
				begin = clock();
				Fill();
				end = clock();
				printf("		No.%d  and time=%d\n", j, end - begin);
				tot += end - begin;
			}
			tot /= 10;
			cout << "	Average Time:" << tot << endl << endl;
		}
	}
}

int main()
{
	time_t sta, end;
	cout << "Algorithm 1 Start:-------------------------------\n";
	sta = clock();
	Algorithm1::work();
	end = clock();
	end -= sta;
	cout << "Algorithm 1 used " << end << "ms in tot\n\n";

	cout << "Algorithm 2 Start:-------------------------------\n";
	sta = clock();
	Algorithm2::work();
	end = clock();
	end -= sta;
	cout << "Algorithm 2 used " << end << "ms in tot\n\n";

	cout << "Algorithm 3 Start:-------------------------------\n";
	sta = clock();
	Algorithm3::work();
	end = clock();
	end -= sta;
	cout << "Algorithm 3 used " << end << "ms in tot\n\n";
}