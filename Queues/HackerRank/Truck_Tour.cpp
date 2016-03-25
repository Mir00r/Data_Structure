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
    int n, i, sum, resi, pos, ans, a, b, A, B;

    sum = resi = ans = pos = A = B = 0;
    scanf ("%d", &n);

    for ( i = 0; i < n; i++ ) {
        scanf ("%d %d", &a, &b);
        sum += ( a - b );
        if ( sum < 0 ) {
            resi += sum;
            sum = 0;
            pos = i + 1;
            A = a;
            B = b;
        }

        if ( i == n - 1 ) {
            if ( sum + resi >= 0 )
                printf ("%d\n", pos);
            else {
                if ( pos < n - 1    ) {
                    i = pos + 1;
                    pos = i;
                    sum = 0;
                    resi += ( A + B );
                }
                else
                    puts ("-1");
            }
        }
    }
    //printf ("%d\n", ans);
    return 0;
}


