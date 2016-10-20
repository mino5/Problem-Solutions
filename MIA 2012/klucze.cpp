#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>

using namespace std;

int L[10001]; // kolory -> ka¿da iteracja ma swój kolor
	
vector<int> V[10001]; // graf -> listy s¹siadów
bool K[10001]; // czy by³ ju¿ anulowany
int res = 0;
	
void dfs(int v, int c)
{
	if (L[v] == c || (L[v] != -1 && !K[L[v]])) return; // ju¿ by³ rozpatrywany w tej iteracji
	
	if (L[v] == v && L[v] != -1 && K[L[v]]) // znaleŸliœmy klucz do tego sejfu ju¿ rozpatruj¹c poprzedniego dfsa
	{
			K[L[v]] = false;
			res--;	

		return;
	}

	L[v] = c;
	
	for (vector<int>::iterator it = V[v].begin(); it != V[v].end(); ++it)
	{
		dfs(*it, c);	
	}
}

int main()
{
	int testCases, nrOfSafes;

	cin >> testCases;
	
	while (testCases--)
	{
		memset(L, -1, sizeof L); 
		memset(K, false, sizeof K);
		
		for (int i = 0; i <= 10000; i++)
		{
			V[i] = vector<int>();
		}
		
		res = 0;
		
		cin >> nrOfSafes;
		
		for (int i = 1; i <= nrOfSafes; i++)
		{
			
			int nrOfKeys;
			cin >> nrOfKeys;
			
			while (nrOfKeys--)
			{
				int s;
				cin >> s;
				
				V[i].push_back(s);
				
			}
			
		}
		
		for (int i = 1; i <= nrOfSafes; i++)
		{
			if (L[i] == -1)
			{	
				//cout << i << ":res++" << endl;
				K[i] = true;
				dfs(i, i);
				res++;
			}
		}
		
		cout << res << endl;
	
	}
	
	return 0;
}
