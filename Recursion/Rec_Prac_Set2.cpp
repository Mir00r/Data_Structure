#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 5
#define col 5
#define MAX 100000
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define MOD 7477777
#define PI 3.1415926535897932384626433832795
#define PrimeRange 1000000
#define CharRange 255
#define LIMIT 1000

/*
Answer: The function calculates and returns log2floor.
For example, if n is between 8 and 15 then fun1() returns 3.
If n is between 16 to 31 then fun1() returns 4.
*/

int fun1( int n ) {

  if( n == 1 )
     return 0;
  else
     return 1 + fun1(n/2);
}


/*Answer: The function fun2() prints binary equivalent of n.
For example, if n is 21 then fun2() prints 10101.*/

/* Assume that n is greater than or equal to 0 */
void fun2( int n ) {
    if(n == 0)
        return;

    fun2( n / 2 );
    printf("%d", n % 2 );
}

int main () {

    int x, y, n;

    printf ("Enter the number : "); scanf ("%d", &n );

    printf ( "%d\n", fun1( n ) );
    NL;
    fun2 ( n );
    return 0;
}
