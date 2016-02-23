#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 205
#define col 205
#define MAX 1000000 + 1
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define MOD 7477777
#define PI 3.1415926535897932384626433832795


int arr[ MAX ];

int Solve ( int n ){
    int res = -inf, curr, i, tmp;
    stack < int > st;

    for ( i = 0; i < n; i++ ){
        //curr = inf;
        while ( !st.empty() && st.top() >= arr[i] ){
            curr = inf;
            tmp = st.top();
        //    printf ("TOP = %d\n", tmp);
            st.pop();

            if ( tmp < curr ) {
                curr = tmp;
                res = max ( res, curr ^ arr[i] );
            }
        }

        if ( !st.empty() )
            res = max ( res, arr[i] ^ st.top() );
        st.push( arr[i] );
      //  printf ("PUSH = %d\n", st.top() );
    }
    return res;
}


int main (){
    int i, n;

    scanf ("%d", &n);

    for ( i = 0; i < n; i++ )
        scanf ("%d", &arr[i]);

    printf ("%d\n", Solve( n ) );
    return 0;
}
