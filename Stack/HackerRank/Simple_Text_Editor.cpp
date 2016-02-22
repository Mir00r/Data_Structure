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
#define MOD 7477777
#define PI 3.1415926535897932384626433832795




int main (){
    int i, j, q, opa, indx;
    //char ch[MAX];

    string text, tmp;
    stack < string > st;

    scanf ("%d", &q);

    while ( q-- ){
        scanf ("%d", &opa );

        if ( opa == 1 ) {
            cin >> tmp;
            st.push( text );
            text.append( tmp );
        }

        if ( opa == 2 ){
            scanf ("%d", &indx);
            st.push( text );
            text.erase( text.length() - indx );
        }

        if ( opa == 3 ){
            scanf ("%d", &indx);
            cout << text[ indx - 1 ] << endl;
        }

        if ( opa == 4 ){
            text = move(st.top());
            st.pop();
        }
    }
    return 0;
}


// Second Way

int main() {
    vector<string> stck;
    string S, append;
    int N, type, arg;
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        scanf ("%d", &type);
        switch(type) {
            case(1):
                stck.push_back(S);
                cin >> append;
                S.append(append);
                break;
            case(2):
                stck.push_back(S);
                scanf ("%d", &arg);
                S.erase(S.length() - arg, S.length());
                break;
            case(3):
                scanf ("%d", &arg);
                cout << S[arg - 1] << endl;;
                break;
            case(4):
                 S = stck.back();
                 stck.pop_back();
                 break;
        }
    }
    return 0;
}


// Third Way 

typedef struct query
{
    int type, remove;
    string add;
}query;

char stak[1000003];

int topp = 0;

void push(string s)
{
    for(int i = 0 ; i < s.length(); i++)
    {
        stak[++topp] = s[i];
    }
    assert(topp <= 1000000);
}

string pop(int remove)
{
    assert(remove >= 0 && remove <= topp);
    string popped = "";
    int del = remove;
    for (int  i = topp; del > 0; i--, del--) {
        popped = stak[i] + popped;
    }
    topp -= remove;
    return popped;
}

int main()
{
    int t, type, remove, k;
    stack<query> q_stack;
    cin>>t;
    while(t--)
    {
        cin>>type;
        if(type == 1)
        {
            string add;
            cin>>add;
            push(add);
            query last;
            last.type = type;
            last.add = add;
            q_stack.push(last);
        }
        else if(type == 2)
        {
            cin>>remove;
            string popped = pop(remove);
            query last;
            last.type = type;
            last.remove = remove;
            last.add = popped;
            q_stack.push(last);
        }
        else if(type == 3)
        {
            cin>>k;
            assert(k >= 1 && k <= topp);
            cout<<stak[k]<<endl;
        }
        else
        {
            query last = q_stack.top();
            q_stack.pop();
            if(last.type == 1)
            {
                int remove = (last.add).length();
                string popped = pop(remove);
            }
            else
            {
                push(last.add);
                assert(topp >= 1 && topp <= 1000000);
            }
        }
    }
    return 0;
}
