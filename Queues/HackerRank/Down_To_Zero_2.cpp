#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 205
#define col 205
#define MAX 1000002
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define mod 7477777
#define PI 3.1415926535897932384626433832795


int dist[MAX];

int main () {
    int i, n, query;
    int elem, fac;

    scanf ("%d", &query);

    while ( query-- ) {
        scanf ("%d", &n);
        if ( n == 0) {
            puts("0");
            continue;
        }
        queue < int > Q;
        Q.push( n );
        dist[n] = 1;

        while ( Q.empty() == false ) {
            elem = Q.front();
            Q.pop();

            if ( dist[ elem - 1] == 0 ) {
                dist[ elem - 1 ] = dist[ elem ] + 1;
                if ( elem - 1 == 0 ) break;
                Q.push( elem - 1 );
            }
            for ( i = 2; i * i <= elem; i++ ) {
                if ( elem % i == 0 ) {
                    fac = max ( i, elem / i );
                   // printf ("FAC -> %d\n", fac);
                    if ( dist[ fac ] == 0 ) {
                        dist[ fac ] = dist[ elem ] + 1;
                        Q.push( fac );
                    }
                }
            }
        }
        printf ("%d\n", dist[ 0 ] - 1 );
        memo( dist, 0 );
    }

    return 0;
}


