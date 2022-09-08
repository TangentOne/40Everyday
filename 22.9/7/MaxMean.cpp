#include <iostream>
#include <vector>
using namespace std;

class MaxMean
{
private:
	
	vector<int> myData;

public:
	
	MaxMean()
	{
		cout << "请输入数据：";
		int data;
		while (cin>>data)
		{
			myData.push_back(data);
			if (cin.peek() == '\n')
				break;
		}		
	}

	void addNewInt(int x)
	{
		myData.push_back(x);
	}
	int getDataCount()
	{
		return myData.size();
	}
	double getAverage()
	{
		int ave = myData[0];
		for (int i = 1; i < myData.size(); i++)
		{
			ave += myData[i];
		}
		ave = ave / myData.size();
		return ave;
	}
	int getMax()
	{
		int max = myData[0];
		for (int i = 1; i < myData.size(); i++)
		{
			if (myData[i] > max)
				max = myData[i];
		}
		return max;
	}

};
