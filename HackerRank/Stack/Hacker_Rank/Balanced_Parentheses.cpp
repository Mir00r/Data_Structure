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
    int t, i;
    stack <char> st;
    char str[MAX];
    scanf ("%d", &t);
    getchar();
    while (t--){
        gets(str);
        bool cheeck = true;
        for (i = 0; i < strlen(str); i++){
            if (str[i] == '(' || str[i] == '[')
                st.push(str[i]);
            else{
                if (str[i] == ')'){
                    if (! st.empty()){
                        if (st.top() == '('){
                            st.pop();
                            continue;
                        }
                        else{
                            cheeck = false;
                            break;
                        }

                    }
                    else{
                        cheeck = false;
                        break;
                    }
                }
                else if (str[i] == ']'){
                    if (! st.empty()){
                        if (st.top() == '['){
                            st.pop();
                            continue;
                        }
                        else{
                            cheeck = false;
                            break;
                        }
                    }
                    else{
                        cheeck = false;
                        break;
                    }
                }
            }
        }
        if (st.empty() == false)
            cheeck = false;
        if (cheeck)
            printf ("YES\n");
        else
            printf("NO\n");
        while (! st.empty())
            st.pop();
    }
    return 0;
}
