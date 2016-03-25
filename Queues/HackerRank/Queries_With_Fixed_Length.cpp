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

int arr[ MAX ];
deque < int > DQ;

int main() {
    int n, query, d, maxn, i, j;
    scanf("%d %d", &n, &query );
    for (int i = 0; i < n; i++)  scanf("%d", &arr[ i ] );

    for ( j = 0; j < query; j++) {
        scanf("%d", &d);
        DQ.clear();
        maxn = inf;

        for ( i = 0; i < n; i++) {
           //printf ("DQ_Size -> %d\n", DQ.size() );
           // printf ("DQ_Back -> %d      DQ_Pop_Back -> %d\n", DQ.back(), DQ.pop_back() );
            while ( DQ.size() && arr[ DQ.back() ] < arr[ i ]) DQ.pop_back();
            DQ.push_back(i);
            while ( DQ.size() && DQ.front() <= i - d) DQ.pop_front();

            if (i >= d - 1) {
                if ( maxn > arr[ DQ.front() ] ) {
                    maxn = arr[ DQ.front() ];
                }
            }
        }
        printf("%d\n", maxn );
    }
    return 0;
}

