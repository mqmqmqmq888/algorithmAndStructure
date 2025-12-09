#include <iostream>
using namespace std;

void reverse(char& p1, char&p2)
{
	int mid = p1;
	p1 = p2;
	p2 = mid;
}

int main()
{
	string s = "aksnjkndwkdj";
	char* p1 = &s[0];
	char* p2 = &s[s.size() - 1];
	while (p1 < p2)
	{
		reverse(*p1, *p2);
		p1++;
		p2--;
	}
	cout << s;
}