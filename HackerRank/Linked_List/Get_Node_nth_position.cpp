#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
#define row 100
#define col 100

struct Node{
	int data;
	struct Node* next;
};

struct Node *head, *hA, *hB;

Node* Insert (Node* head, int n){
	
	struct Node* tmp = (Node*)malloc( sizeof (struct Node) ); 
	tmp->data = n;
	tmp->next = NULL;
	if (head == NULL){ 
        //tmp->next = head;
	    return tmp;
    }
    
    struct Node* temp = head;
	while (temp->next != NULL) {
	   temp = temp->next;
	}
	temp->next = tmp;
	return head;
}

void Print (Node* head){
	//struct Node* tmp = head;
	
	//printf ("The List is: ");
	
	while ( head != NULL ){
		printf (" %d", head->data );
		head = head->next;	
	}
	puts ("");
}

/*
int GetNode(Node *matha,int pos){
	int indx = 0;
    Node* curr = matha;
    Node* res = matha;
    
    while(curr != NULL){
        curr = curr->next;
        
        if (indx++ > pos ){
            res = res->next;
        }
    }
    return res->data;
  
}
*/

int GetNode(Node *matha, int pos)
{
    int cnt = 0, i;            //keeps the number of nodes
    Node *point;
    point = matha;
    
    while(point != NULL){
        cnt++;
        point = point->next;
    }
    point = matha;

    /* Say there are n nodes
     * And we want mth element from last
     * Then it will be
     * (n-m)th element from start
     */

    for( i = 1; i < cnt-pos; i++){
        point = point->next;
    }
    return (point->data); 
}

int main(){
	int n, p, i, num_A;
	head = NULL;
	
	
	printf ("Enter the size of array A\n");
	scanf ("%d", &n);
	puts ("");
	
	printf ("Enter %d Numbers in head A: ", n);
	for (i = 0; i < n; i++){
		scanf ("%d", &num_A);
		head = Insert (head, num_A);
	}
	puts ("");
	printf ("Enter the posintion Number that you Get: ");
	scanf ("%d", &p);
	
	//head = GetNode (head, p);
	//Print (head);
	printf ("%d\n", GetNode (head, p) );
	return 0;
}


