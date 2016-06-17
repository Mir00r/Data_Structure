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

int fun(int a, int b){

   if (b == 0)
       return 1;
   if (b % 2 == 0)
       return fun(a*a, b/2);
 
   return fun(a*a, b/2)*a;
}
 
int main(){

  printf("%d", fun(4, 3));

  return 0;
}



int fun(int a, int b){

   if (b == 0)
       return 1;
   if (b % 2 == 0)
       return fun(a*a, b/2);
 
   return fun(a*a, b/2)*a;
}
 
int main(){

  printf("%d", fun(4, 3));

  return 0;
}


int fun(int n) {

   if (n > 100)
     return n - 10;
   return fun(fun(n+11));
}
 
int main(){

  printf(" %d ", fun(99));

  return 0;
}
