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

typedef struct node{
    int freq;
    char data;
    node *left;
    node *right;
    
}node;

void decode_huff(node *root, string S){

  if(S == "\0" || S.length() == 0 || root == NULL ) 
	  return;

  int len = S.length();
  node *curr = root;
  for(int i = 0; i < len; i++){
      char ch = S.at(i);

      if(ch == '1'){
          curr = curr->right;
      }
      else if(ch == '0'){
          curr = curr->left;
      }

      if(curr->left == NULL && curr->right == NULL){
          printf("%c", curr->data);
          curr = root;
      }
  }
}


int main(){
    decode_huff (*Huffmantree, "10010101010");
    return 0;
}    

/*
int main(){

    char str[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    decode_huff (str, freq, size);
    return 0;
}
*/
