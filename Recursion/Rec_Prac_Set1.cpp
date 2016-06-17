#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 5
#define col 5
#define MAX 100000
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
#define LIMIT 1000

int fun1(int x, int y) {

    if( x == 0 ) return y;
    else
        return fun1( x - 1,  x + y );
}


void fun2(int arr[], int start_index, int end_index) {

    if( start_index >= end_index ) return;
    int min_index;
    int temp;

    /* Assume that minIndex() returns index of minimum value in
    array arr[start_index...end_index] */
    min_index = minIndex(arr, start_index, end_index);

    temp = arr[start_index];
    arr[start_index] = arr[min_index];
    arr[min_index] = temp;

    fun2(arr, start_index + 1, end_index);
}


int main () {

    int x, y;

    printf ("Enter the number x and y: "); scanf ("%d %d", &x, &y );

    printf ( "%d\n", fun1( x, y ) );
    NL;
    //fun2 ( 2 );
    return 0;
}
