#include<iostream>
#include<vector>
using namespace std;

struct node
{
	int data;
	node* next;
};
node* index[1000001];//指针数组
vector<int> out;

int main()
{
	node* head;
	node* p;
	int q;
	cin >> q;
	int choice;
	int x, y;
	p = new node;
	p->data = 1;
	p->next = NULL;
	head = p;


	index[1] = head;

	int ancount = 0;

	for (int i = 0; i < q; i++)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			cin >> x >> y;
			p = index[x];
			if (p->next ==NULL)
			{
				p = new node;
				p->data = y;
				index[y] = p;
				p->next = NULL;
				index[x]->next = p;
			
			}
			else
			{
				p = new node;
				p->data = y;
				index[y] = p;
				p->next=index[x]->next;
				index[x]->next = p;
			}
			break;
		case 2:
			cin >> x;
			p = index[x];
			if (p->next == NULL)
			{
				out[ancount] = 0;
				ancount++;
			}
			else
			{
				out[ancount] = (p->next)->data;
				ancount++;
			}
			break;
		case 3:
			cin >> x;
			p = index[x];
			
			if ((p->next) ==NULL)
			{
				
			}
			else
			{
				int tem = (index[x]->next)->data;//x后一位元素
					index[x]->next = index[tem]->next;
					delete index[tem];
			}
			break;
			
		default:
			cout << "error";
			break;
		}
	}
    
	for (int k = 0; k < ancount; k++)
	{
		cout << out[k] << endl;
		
		
	}
}
