// Auther:  Abdur Razzak
// Email:   abdur.razzaq06@gmail.com

#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 205
#define col 205
#define MAX 1006
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define mod 7477777
#define PI 3.1415926535897932384626433832795

int main(){
    int n, x, type, i, hi = 0;
    stack < int > st, max_st;

    scanf ("%d", &n);
    for ( i = 0; i < n; i++){
        scanf ("%d", &type );

        if ( type == 1 ) {
            scanf ("%d", &x);
            st.push ( x );


            if ( max_st.empty() )
                max_st.push( x );
            else{
                if ( x > max_st.top() )
                    max_st.push ( x );
                else
                    max_st.push ( max_st.top() );
            }


            /*
            if ( x > hi ){
                hi = x;
                max_st.push ( hi );
            }
            else
                max_st.push ( x );
            */
        }

        else if ( type == 2){
            //int val = st.top ();
            st.pop ();

            max_st.pop ();

            /*
            if ( max_st.empty() )
                hi = 0;
            else
               // hi = max_st.top();
                hi = max_st.size() - 1 ;
            */
        }

        else if ( type == 3){
            printf ("%d\n", max_st.top() );
           // max_st.pop ();
           // printf ("%d\n", max_st.pop(  );
        }
    }
    return 0;
}


