#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 105
#define col 105
#define MAX 1000000 + 5
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define MOD 7477777
#define PI 3.1415926535897932384626433832795
#define PrimeRange 1000000

// First Way 
int main () {
    int n, i = 0, num, tmp;
    vector < int > vt;
    double medi;

    scanf ("%d", &n);
    while ( n-- ) {
        scanf ("%d", &num);

        // Keep Every Number Sorted
        vt.insert( lower_bound( vt.begin(), vt.end(), num), num );
        //printf ("LB -> %d\n", vt[i] );

        if ( i % 2 == 0 )
            medi = vt[ i / 2 ];
        else
            medi = ( (double)vt[ i / 2 ] + vt[ i / 2 + 1 ] ) / 2;
        printf ("%.1lf\n", medi);
        i++;
    }

    return 0;
}


// Second Way
int main(){
    priority_queue < int, vector < int >, greater < int > > MinQ;
    priority_queue < int > MaxQ;

    int n, num, i, tmp, a, b;

    scanf ("%d", &n);

    while ( n-- ) {
        scanf ("%d", &num );
        MaxQ.push( num );

       // printf ("MaxQ_Size -> %d\n", MaxQ.size());
       // printf ("MinQ_Size -> %d\n", MinQ.size());

        if ( MaxQ.size() > MinQ.size() + 1 ) {
            //printf ("If -> MaxQ_Top_Value -> %d\n", MaxQ.top() );
            MinQ.push ( MaxQ.top() );
            MaxQ.pop();
        }
        else if ( MinQ.empty() == false && MaxQ.top() > MinQ.top() ) {
            //printf ("Else If -> MinQ_Top_Value -> %d\n", MinQ.top() );
            MaxQ.push( MinQ.top() );
            MinQ.pop();

            //printf ("Else If -> MaxQ_Top_Value -> %d\n", MaxQ.top() );
            MinQ.push( MaxQ.top() );
            MaxQ.pop();
        }

        if ( MaxQ.size() > MinQ.size() )
            printf ("%d.0\n", MaxQ.top() );
        else {
            tmp = MaxQ.top() + MinQ.top();
            //printf ("Tmp -> %d\n", tmp);
            a = tmp / 2;
            if ( tmp % 2 == 0 )
                b = 0;
            else
                b = 5;

            printf ("%d.%d\n", a, b);
        }
    }

    return 0;
}

// third way 
int N;
multiset<int> r;
multiset<int, greater<int> > l;
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int a; scanf("%d", &a);
        if (l.empty()) l.insert(a);
        else {
            if (a > *l.begin()) r.insert(a);
            else l.insert(a);
        }
        if (l.size() > r.size() + 1) {
            r.insert(*l.begin());
            l.erase(l.begin());
        } else if (r.size() > l.size()) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
        if (l.size() > r.size())
            printf("%d.0\n", *l.begin());
        else
            printf("%d.%c\n", (*l.begin() + *r.begin()) / 2, ((*l.begin() + *r.begin()) & 1) ? '5': '0');
    }
    return 0;
}

/*
Time Limit Exit Code 
int main(){
    int n, i, j, tmp, arr[ MAX ], brr[ MAX ];
    double sum = 0.0, ans[ MAX ];

    scanf ("%d", &n);
    for ( i = 0; i < n; i++ ) {
        scanf ("%d", &arr[ i ]);

        if ( i >= 1 ) {
            tmp = arr[ i ];
            j = i - 1;
            while ( ( j >= 0 ) && tmp < arr[ j ] ) {
                arr[ j + 1 ] = arr[ j ];
                arr[ j ] = tmp;
                j--;
            }
        }

        if ( i % 2 != 0 )
            sum = (double) (arr[ i / 2 ] + arr[ (i + 1) / 2 ] ) / 2;
        else
            sum = (double) arr[ i / 2 ];
        ans[ i ] = sum;
    }

    for ( i = 0; i < n; i++ ) printf ("%.1lf\n", ans[ i ]);
    return 0;
}
*/




