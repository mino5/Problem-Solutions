#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n, m, testCases, cookiezi, speed;
	
	scanf("%d", &testCases);
	
	while (testCases-- > 0)
	{
		scanf("%d %d",&n,&m);
		cookiezi = 0;
		
		for (int i = 0; i < n; i++)
		{
			cin >> speed;
			cookiezi += (86400/speed);
		}
		
		cout << (cookiezi + m - 1) / m << endl;
	
	}
	

	return 0;
}
