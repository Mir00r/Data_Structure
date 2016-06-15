#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 105
#define col 105
#define MAX 100000 + 5
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

#define SIZE 20


int Size, opa;

struct DataItem {
   int data;
   int key;
};

struct DataItem* hashArray[ MAX ];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key){
//   return key % SIZE;

    return key % Size;
}



struct DataItem *Search(int key){
   //get the hash
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL){

      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex];

      //go to next cell
      ++hashIndex;

      //wrap around the table
//      hashIndex %= SIZE;
        hashIndex %= Size;
   }

   return NULL;
}

void Insert(int key,int data){

    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;

    //get the hash
    int hashIndex = hashCode(key);

    //move in array until an empty or Deleted cell
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){
      //go to next cell
      ++hashIndex;

      //wrap around the table
      //hashIndex %= SIZE;
        hashIndex %= Size;
    }

    hashArray[hashIndex] = item;
}

struct DataItem* Delete(struct DataItem* item){
    int key = item->key;

    //get the hash
    int hashIndex = hashCode(key);

    //move in array until an empty
    while(hashArray[hashIndex] != NULL){

      if(hashArray[hashIndex]->key == key){
         struct DataItem* temp = hashArray[hashIndex];

         //assign a dummy item at Deleted position
         hashArray[hashIndex] = dummyItem;
         return temp;
      }

      //go to next cell
      ++hashIndex;

      //wrap around the table
      //hashIndex %= SIZE;
        hashIndex %= Size;
    }

    return NULL;
}

void Display(){
    int i = 0;

    for( i = 0; i < Size; i++ ) {

      if(hashArray[i] != NULL)
         printf(" (%d,%d)\n",hashArray[i]->key,hashArray[i]->data);
      else
         puts(" ~~ ");
    }
    NL;
}

void init () {
    dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    dummyItem->data = -1;
    dummyItem->key = -1;
}

void Test_Input() {
    init();

    Insert(1, 20);
    Insert(2, 70);
    Insert(42, 80);
    Insert(4, 25);
    Insert(12, 44);
    Insert(14, 32);
    Insert(17, 11);
    Insert(13, 78);
    Insert(37, 97);

    Display();

    item = Search(37);

    if(item != NULL){
      printf("Element found: %d\n", item->data);
    }
    else {
      printf("Element not found\n");
    }

    Delete(item);

    item = Search(37);

    if(item != NULL){
      printf("Element found: %d\n", item->data);
    }
    else {
      printf("Element not found\n");
    }
}


void Input () {
   scanf ("%d", &opa);
}

void Operation (){

    puts ("Enter 1 for Search item from HashArray");
    puts ("Enter 2 for Deleting item from HashArray");
    puts ("Enter 3 for Displaying the HashArray");
    puts ("Enter 4 for Exiting the programe");

    //Input();
}



void Opa_Theater ( int O ) {

    if ( O == 1 ) {
        int val;
        puts ("Enter the key value for Search the element from array:");
        scanf ("%d", &val);
        item = Search( val );

        if ( item != NULL )
            printf ("Element found %d\n", item->data );
        else
            puts("Element not found");
    }
    else if ( O == 2 ) {
        int val;
        puts ("Enter the key value for delete the element from arrya: ");
        scanf ("%d", &val);
        item = Search( val );
        Delete( item );
        puts ("Item deleted successfully");
    }
    else if ( O == 3 ) Display();

}


int main(){
    int i, k, v;
    //Test_Input();


    init();

    puts ("Enter the size of Array: ");
    scanf ("%d", &Size);
    puts ("Enter key and value: ");
    for ( i = 0; i < Size; i++ ) {
        scanf ("%d %d", &k, &v);
        Insert( k, v );
    }
    puts ("After inserting the Array is ");
    Display();

    Operation();
    NL;

    while ( 1 ) {
        Input();

        if ( opa == 4 ) break;
        else Opa_Theater( opa );
    }

    return 0;
}
