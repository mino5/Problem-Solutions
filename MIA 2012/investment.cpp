#include <stdio.h>
#include <memory.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) 

int c[11];
int w[11];
int A[450000 + 1]; // * 1000

int main()
{
    
    int n, capital, years, d;
    
    scanf("%d",&n);
    
    while (n--)
    {
                memset(w, 0, sizeof(w));
                memset(c, 0, sizeof(c));
                memset(A, 0, sizeof(A));
                
                scanf("%d",&capital);
                scanf("%d",&years);
                scanf("%d",&d);
                
                for (int i = 1; i <= d; i++)
                {
                    scanf("%d",&w[i]);
                    scanf("%d",&c[i]);
                }
                
                A[0] = 0;
                for (int i = 1000; i <= capital; i+=1000)
                {
                    for (int j = 1; j <= d; j++)
                    {
                             if (w[j] <= i) {
                                A[i / 1000] = MAX(A[i / 1000], A[(i - w[j])/ 1000] + c[j]); 
                                }
                     }
                     
                     if (years > 0 && (i / 1000) == (capital / 1000))
                     {
                               capital += A[i / 1000];
                               i -= 1000;
                               years--;
                      }
                         
                 }

                 printf("%d\n", capital);
          
    }
    
    return 0;   
}
