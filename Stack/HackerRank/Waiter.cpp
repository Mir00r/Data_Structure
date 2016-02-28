#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 205
#define col 205
#define MAX 10000 + 5
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define MOD 7477777
#define PI 3.1415926535897932384626433832795
#define PrimeRange 10000 + 5



int prime[ PrimeRange ], cnt;
bool isPrime[ PrimeRange ];


void sieve(){
    int i, j, root;
    root = sqrt ( PrimeRange );

    for ( i = 2; i < PrimeRange; i++ )
        isPrime[i] = true;

    for ( i = 3; i <= root; i++)
        for ( j = i * i; j < PrimeRange; j += i )
            if ( isPrime[ j ] == true )
                isPrime[ j ] = false;
    cnt = 0;
    prime[ cnt++ ] = 2;
    for ( i = 3; i < PrimeRange; i += 2)
        if ( isPrime[i] == true )
            prime[ cnt++ ] = i;

}


int main (){
    int i, n, q, num, tmp, curr, elem;
    sieve();
    stack < int > st1, st2, st3;
//    for ( i = 0; i < cnt; i++ )
//        printf ("%d ", prime[i]);

    scanf ("%d %d", &n, &q);
    for ( i = 0; i < n; i++ ){
        scanf ("%d", &num );
        st1.push (num);
    }

    for ( i = 0; i < q; i++ ){
        if ( st1.empty() ) break;
        curr = prime[i];

        while ( !st1.empty() ){
            elem = st1.top();
            st1.pop();

            if ( elem % curr == 0 )
                st2.push( elem );
            else
                st3.push( elem );
        }

        while ( !st2.empty() ){
            printf ("%d\n", st2.top());
            st2.pop();
        }

        st1 = st3;
        while ( !st3.empty() ) st3.pop();
    }

    while ( !st1.empty() ){
        printf ("%d\n", st1.top());
        st1.pop();
    }

    return 0;
}
