#include <iostream>

using namespace std;

long long int gcd ( long long int a, long long int b )
{
  long long int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}




int main(int argc, char** argv)
{
	
 
	long long int d,n,m;
	cin >> d;
	cin >> n;
	cin >> m;
	
	
	long long int mianownik = d*n;
	long long int licznik = 7*m;
	
 	long long int divisor = gcd(mianownik, licznik);
	
	licznik /= divisor;
	mianownik /= divisor;	
	
	cout << licznik << "/" << mianownik << endl;
	
	

	return 0;	
}
