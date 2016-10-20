#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{

        int N, T;
	int *R;
	

	cin >> N;
	cin >> T;
	


	R = new int[N];
	short int max;
	short int maxPos;
	
	short int i;
	
	for (i = 0; i < N; i++)
	{	
		cin >> R[i];
		
	}
	
	for (int i = 0; i < T; i++)
	{
	
		max = -1;
		
		for (int j = 0; j < N; j++)
		{
			if (R[j] > max) 
			{	
				max = R[j];
				maxPos = j;
			}				
		}
		
		cout << maxPos + 1 << endl;
		
		int distrubution = max / (N - 1);
		int rest = max - distrubution * (N - 1);
		R[maxPos] = 0;
		
		for (int j = 0; j < N; j++)
		{
			if (j != maxPos)
			{
				if (rest > 0)
				{
					R[j] += 1;
					rest--;
				}
				
				R[j] += distrubution;
			}
		}
	}
	
	return 0;
}
