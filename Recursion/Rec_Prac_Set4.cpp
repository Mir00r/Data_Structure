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


void fun(int x){

    if(x > 0){
        fun(--x);
        printf("%d\t", x);
        fun(--x);
    }
}

int main(){

    int a = 4;
    fun(a);

    return 0;
}

int fun( int i ){
    
    if ( i%2 ) return (i++);
    else return fun(fun( i - 1 ));
}
 

int main(){
    
    printf(" %d ", fun(200));
  
    return 0;
}




int fun(int a[],int n){

    int x;
    if(n == 1) {
       // puts ("First");
        return a[ 0 ];
    }
    else{
        x = fun( a, n - 1 );
        //printf ("X -> %d\n", x );
    }
    if( x > a[ n - 1 ] ) {
       // puts ("X Ret");
        return x;
    }
    else{
        //puts ("Last");
        return a[ n - 1 ];
    }
}

int main(){

  int arr[] = {12, 10, 30, 50, 100};
  printf(" %d ", fun(arr, 5));

  return 0;
}
