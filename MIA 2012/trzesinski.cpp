#include <iostream>
#include <memory.h>

using namespace std;

int wartwiel[22];

int main()
{
    
    int k; // stopien wielomianu
    int val;
    long long int result = 0;
    long long int L, L_up, L_down;
    
    memset(wartwiel, 0, sizeof wartwiel); 
    cin >> k;
    
    // wczytujemy wartoœci wielomianu dla punktów 1,2,...,k+1
    for (int i = 1; i <= k + 1; i++)
    {
        cin >> val;
        wartwiel[i] = val;
    }

    // wyliczamy L_1,L_2,...,L_{k+1}
    for (int i = 1; i <= k + 1; i++)
    {

        L_up = 1;
        L_down = 1;
        L = 1;
        // Dla L_{i} wyliczamy iloczyn j = 1, j!=i, (x - xj) / (xi - xj)
        
        for (int j = 1; j <= k + 1; j++)
        {
             if (j == i) continue;
                         
             L_up *= ( (k+2) - j);           
             
             if (L_up % (i-j) == 0)
                L_up /= (i-j);
             else   
             L_down *= (i - j);
        }
        
        L = L_up / L_down;
        result += wartwiel[i] * L;
    }
 
    cout << result << endl;
 
   return 0; 
}
