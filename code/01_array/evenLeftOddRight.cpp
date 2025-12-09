#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	int *p1 = &v[0];
	int *p2 = &v[v.size() - 1];

	while (p1 < p2)
	{
		if ((*p1 & 1) == 0)
		{
			p1++;
		}
		else if ((*p2 & 1) == 1)
		{
			p2--;
		}
		else
		{
			swap(*p1, *p2);
		}
	}
	
	for (int val : v)
	{
		cout << val << " ";
	}
}