#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 205
#define col 205
#define MAX 100006
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define mod 7477777
#define PI 3.1415926535897932384626433832795




typedef struct node{
    int v1,v2;
}node;



int  main(){
    int n, i, sc, pr;
    scanf ("%d", &n);

    assert ( n >= 1 && n <= 100000);
    vector <int> vt( n );


    for( i = 0; i < n; i++){

        scanf ("%d", &vt[i]);
        assert( vt[i] >= 0 && vt[i] <= 1000000000 );
        vt[i] =- vt[i];
    }


    stack <node> st;
    int maxn = 0;

    for( i = 0; i < n; i++){
        if( st.empty()){
            st.push({ vt[i], 0 });
        }
        else{

            node tmp = st.top();

            if( vt[i] < tmp.v1 ){
                sc = 1;
                maxn = max( maxn, sc );
                st.push({ vt[i], sc });
            }
            else{

                node v = st.top();
                pr = v.v2;

                while( !st.empty() && v.v1 <= vt[i]){
                    st.pop();
                    if( st.empty() )
                        break;

                    pr = max( pr, v.v2 );
                    v = st.top();
                }

                if( st.empty() ){
                    st.push({ vt[i], 0 });
                }
                else{
                    st.push({ vt[i], pr + 1 });
                    maxn = max( maxn, pr + 1 );
                }


            }
        }
    }
    printf ("%d\n", maxn);
}


/*
    Problem Editorial 
    problem link : https://www.hackerrank.com/challenges/poisonous-plants

    Each plant must not have greater pesticide content than the plant to it's left.
    This problem can be solved by using a stack. Each element on the stack represents
    the poison content of the plant and the number of days that have passed. Initially,
    push {a[0],0} onto the stack.

    Iterate for all the plants. If the stack isn't empty, pop an element from the stack and compare it with a[i].
    If a[i] is greater than this value, then a[i] will be killed. Add {a[i],1} to the stack.
    It takes one day to kill a[i]. If a[i] is smaller, pop till the values in the stack are greater than a[i].
    Update the answer with the second integer of the pair pushed onto the stack.
    If the stack becomes empty then add {a[i],0} to the stack otherwise add a[i],cur_date + 1.
*/
