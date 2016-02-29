#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 205
#define col 205
#define MAX 1000000 + 5
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define MOD 7477777
#define PI 3.1415926535897932384626433832795
#define PrimeRange 1500


LLI num[MAX];
priority_queue < LLI, vector < LLI >, greater < LLI > > PQ;


int main (){
    LLI i, n, k, tmp = 0, digi, curr, elem1, elem2, cnt = 0;

    scanf ("%lld %lld", &n, &k);
    for ( i = 0; i < n; i++ ){
        //scanf ("%d", &num[i] );
        scanf ("%lld", &digi);
        PQ.push ( digi );
    }

    while ( PQ.top() < k ) {
        elem1 = PQ.top();
        PQ.pop();

        if ( PQ.empty() ) {
            puts ("-1");
            //break;
            return 0;
        }

        elem2 = PQ.top();
        PQ.pop();

        PQ.push ( elem1 + 2 * elem2 );
        cnt++;

        if ( PQ.empty() ) {
            puts ("-1");
            // break;
            return 0;
        }
    }

    printf ("%lld\n", cnt);
    return 0;
}
