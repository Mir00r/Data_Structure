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


#define MAXN 200010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

int lol[MAXN];

struct Node{
    Node *l, *r;
    int subtree, priority;
    long long sum, val, lazy;

    inline Node(){
        l = r = 0;
    }

    inline Node(long long v){
        l = r = 0;
        priority = rand();
        subtree = 1, val = sum = v, lazy = 0;
    }

    inline Node(long long v, int p){
        l = r = 0;
        priority = p;
        subtree = 1, val = sum = v, lazy = 0;
    }

    inline void update(){
        subtree = 1;
        if (l) subtree += l->subtree;
        if (r) subtree += r->subtree;
    }
} nodes[MAXN]; /// Maximum number of nodes in treap

struct Treap{
    int idx;
    struct Node* root;

    /// Lazy propagation
    inline void push(Node* cur){
        if (!cur || !cur->lazy) return;

        cur->update();
        cur->val += cur->lazy, cur->sum += (cur->lazy * cur->subtree);
        if (cur->l) cur->l->lazy += cur->lazy;
        if (cur->r) cur->r->lazy += cur->lazy;
        cur->lazy = 0;
    }

    /// Update root node from left child, right child and itself!
    inline void join(Node* cur){
        if (!cur) return;

        cur->update();
        cur->sum = cur->val;
        if (cur->l) push(cur->l), cur->sum += cur->l->sum;
        if (cur->r) push(cur->r), cur->sum += cur->r->sum;
    }

    /// Merges two treaps l and r
    inline void merge(Node* &cur, Node* l, Node* r){
        push(l), push(r); /// Lazy propagation
        if (!l || !r) cur = l ? l : r;
        else if (l->priority > r->priority) merge(l->r, l->r, r), cur = l;
        else merge(r->l, l, r->l), cur = r;
        if (cur) join(cur); /// Update root node from left child, right child and itself!
    }

    /// Splits treap cur, counter is the implicit key on subtree size
    inline void split(Node* cur, Node* &l, Node* &r, int key, int counter = 0){
        if (!cur){
            l = r = 0;
            return;
        }

        push(cur); /// Lazy propagation
        int cur_key = counter + (cur->l ? cur->l->subtree : 0);
        if (key <= cur_key) split(cur->l, l, cur->l, key, counter), r = cur;
        else split(cur->r, cur->r, r, key, cur_key + 1), l = cur;
        if (cur) join(cur); /// Update root node from left child, right child and itself!
    }

    inline void build(int i, int v){
        nodes[idx] = Node(v);
        merge(root, root, &nodes[idx++]);
    }

    inline void update1(int a, int b){
        Node *l, *m, *r;
        split(root, l, r, a - 1);
        split(r, m, r, b - a + 1);
        merge(l, l, r);
        merge(root, m, l);
    }

    inline void update2(int a, int b){
        Node *l, *m, *r;
        split(root, l, r, a - 1);
        split(r, m, r, b - a + 1);
        merge(l, l, r);
        merge(root, l, m);
    }

    Treap(){
        srand(time(0));
        idx = 0, root = 0;
    }

    inline void dfs(Node* cur, int& len){
        if (!cur) return;

        if (cur->l) dfs(cur->l, len);
        lol[len++] = cur->val;
        if (cur->r) dfs(cur->r, len);
    }
};

int main(){
    int n, m, i, k, f, l, r;

    Treap T = Treap();
    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++){
        scanf("%d", &k);
        T.build(i, k);
    }

    while (m--){
        scanf("%d %d %d", &f, &l, &r);
        if (f == 1) T.update1(l, r);
        else T.update2(l, r);
    }

    int len = 0;
    T.dfs(T.root, len);
    
    printf("%d\n", abs(lol[0] - lol[len - 1]));
    printf("%d", lol[0]);
    for (i = 1; i < len; i++) printf(" %d", lol[i]);
    puts("");
    
    return 0;
}

