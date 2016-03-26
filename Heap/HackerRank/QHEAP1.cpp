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

// Way 1

void MinHeapify( LLI* heap, int HeapSize, int index) {
    int tmp, left, right;

    if ( index >= HeapSize )
        return;
    tmp = index;
    left = 2*tmp+1;
    right = 2*tmp+2;

    if ( left <= HeapSize && heap[ left ] < heap[ tmp ] )
        tmp = left;
    if ( right <= HeapSize && heap[ right ] < heap[ tmp ] )
        tmp = right;
    if ( tmp == index )
        return;
    swap( heap[ tmp ], heap[ index ] );
    MinHeapify(heap, HeapSize, tmp);
    return;
}


void DeleteElement( LLI* heap, int& HeapSize, int val) {
    int index = -1, i;
    for ( i = 0; i <= HeapSize; i++) {
        if (heap[i] == val) {
            index = i;
            break;
        }
    }
    swap( heap[ HeapSize ], heap[ index ] );
    HeapSize--;
    MinHeapify( heap, HeapSize, index );
    return;
}


int main() {
    int queries, i;
    int qType;
    int HeapSize = -1;

    scanf ("%d", &queries);
    LLI heap[queries];
    LLI num;

    for ( i = 0; i < queries; i++) {
        scanf ("%d", &qType);
        if (qType == 1) {
            scanf ("%lld", &num);
            HeapSize++;
            int tmp = HeapSize;
            heap[ tmp ] = num;
            int parent = ( tmp - 1) / 2;

            while ( parent >= 0 && heap[ parent ] > heap[ tmp ] ) {
                swap( heap[ parent ], heap[ tmp ] );
                tmp = parent;
                parent = (tmp - 1) / 2;
            }
        }
        else if (qType == 2) {
            scanf ("%lld", &num);
            DeleteElement(heap, HeapSize, num);
        }
        else if (qType == 3)
            printf ("%lld\n", heap[ 0 ]);
    }
    return 0;
}





// Way 2
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
