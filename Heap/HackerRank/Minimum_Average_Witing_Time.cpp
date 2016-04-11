#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 105
#define col 105
#define MAX 100000 + 5
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


struct info {
    LLI Ti, Li;
};

struct Cmp {
    bool operator () ( info a, info b ) {
        return a.Li > b.Li;
    }
};


bool operator < ( info a, info b ) {
    return a.Ti < b.Ti;
}

vector < info > vt;
priority_queue < info, vector < info >, Cmp > PQ;


int main (){

    LLI i, n, t, l, tot, indx, curr_t;
    info tmp;

    scanf ("%lld", &n);
    for ( i = 0; i < n; i++ ) {
        scanf ("%lld %lld", &t, &l);
        tmp.Ti = t;
        tmp.Li = l;
        vt.pb( tmp );
    }

    sort ( vt.begin(), vt.end() );
    indx = curr_t = tot = 0;

    while ( 1 ) {
        for ( i = indx; i < n; i++ ) {
            if ( vt[ i ].Ti <= curr_t )
                PQ.push ( vt[ i ] );
            else {
                indx = i;
                break;
            }
        }

        if ( i == n )
            indx = n;

        if ( PQ.empty() == false ) {
            info dmp = PQ.top();
           // printf ("DMP -> %lld\n", dmp );

            tot += curr_t + dmp.Li - dmp.Ti;
            curr_t += dmp.Li;

            PQ.pop();
        }
        else {
            if ( indx != n )
                curr_t = vt[ indx ].Ti;
        }

        if ( indx == n && PQ.empty() ) break;
    }

    printf ("%lld\n", tot / n );
    return 0;
}
