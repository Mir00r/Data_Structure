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



int Fibonacci ( int n ) {
    if ( n == 0) return 0;
    else if ( n == 1 ) return 1;
    else
        return ( Fibonacci( n - 1) + Fibonacci( n - 2 ) );
}

int main () {

    int n, i;

    printf ("Enter the number: "); scanf ("%d", &n );

    for ( i = 0; i < n; i++ )
    printf ("%d\n", Fibonacci( i ) );
    return 0;
}
