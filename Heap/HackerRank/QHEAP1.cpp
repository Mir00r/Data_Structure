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

vector < LI > vt;


int main() {
    LLI query, opa, num;
    int i;
    make_heap ( vt.begin(), vt.end(), greater < LLI >() );

    scanf ("%lld", &query);
    for ( i = 0; i < query; i++ ) {
        scanf ("%lld", &opa);
        if ( opa == 1 ){
            scanf ("%lld", &num);
            vt.push_back( num );
            push_heap( vt.begin(), vt.end(), greater < LLI >() );
        }
        else if ( opa ==  2) {
            scanf ("%lld", &num);
            vector < LI > :: iterator itr;
            for ( itr = vt.begin(); itr != vt.end(); itr++ ) {
                if ( *itr == num ) {
                    vt.erase( itr );
                    break;
                }
            }
            make_heap ( itr, vt.end(), greater < LLI >() );
        }
        else 
            printf ("%lld\n", vt.front());
    }

    return 0;
}
