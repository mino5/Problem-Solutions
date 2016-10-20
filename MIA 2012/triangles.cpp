#include <stdio.h>
//#include <iostream>
#include <memory.h>
#include <algorithm>
//#include <queue>
#include <math.h>
#define CIAGSIZE 1000001
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) 
#define MIN(a, b) (((a) < (b)) ? (a) : (b)) 

int ciag[CIAGSIZE];
int ciagsorted[CIAGSIZE];

using namespace std;

inline bool HasTriangleAlg(int a, int b, int* ciag)
{
          
          while (b > a + 1)
          {
          	if (ciag[b] == -1) { b--; continue; }
          	
                int big = ciag[b];
                int mid = ciag[b-1];
                int low = ciag[b-2];
                
                if (big < mid + low) return true; 
                   else b--;
          } 	
          
          return false;
}

int copy(int interv_l, int interv_r)
{
     int i = 1;
     for (int j = interv_l; j <= interv_r;j++)
         ciagsorted[i++] = ciag[j];
         
     return i - 1;
}

int nodes = 0;

bool checkBetween(int int_left, int int_right)
{
         int size = copy(int_left, int_right);
         sort(ciagsorted, ciagsorted + size + 1);
         return HasTriangleAlg(1, size, ciagsorted);
}

bool HasTriangle(int in_interv_l, int in_interv_r)
{
     if (in_interv_r - in_interv_l < 2) return false;
     if (in_interv_r - in_interv_l > 46) return true;
     
     bool result = checkBetween(in_interv_l, in_interv_r);
         
     return result;
}

int main()
{
    int n, current, p, a, b;
    memset(ciag, 0, sizeof(ciag));
    memset(ciagsorted, 0, sizeof(ciag));
    
    scanf("%d", &n);
    int i = 1;
    
    while (n--)
    {
          scanf("%d", &current);
          ciag[i] = current;
          i++;
          
          
    }
    
    i--;
    
    n = i;
        
    scanf("%d", &p);
    
    
    while (p--)
    {
          scanf("%d %d",&a,&b);
        
          if (HasTriangle(a, b )) 
            printf("TAK");
          else 
              printf("NIE");
          
          printf("\n");
    }
     
    return 0;
}

