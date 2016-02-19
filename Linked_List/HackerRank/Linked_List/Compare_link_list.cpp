#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
#define row 100
#define col 100

// Way Number 1

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

int CompareLists(Node *head_A, Node *head_B) {
    
    if(head_A == NULL && head_B == NULL){
        return 1;
    }
    else{
        if( ( head_A == NULL && head_B != NULL ) || ( head_A != NULL && head_B == NULL ) || ( head_A->data != head_B->data ) ){
            return 0;
        }
        else{
            return CompareLists(head_A->next, head_B->next);
        }
    }  
}


int main(){
	int n, i, num_A, num_B;
	head = NULL;
	hA = NULL;
	hB = NULL;
	
	printf ("How many Numbers?\n");
	scanf ("%d", &n);
	
	printf ("Enter the %d Number:\n ", n);
	puts ("");
	for (i = 0; i < n; i++){
		printf ("Enter the head A Number: ");
		scanf ("%d", &num_A);
		hA = Insert (hA, num_A);
		puts ("");
		
		printf ("Enter the head B Number: ");
		scanf ("%d", &num_B);
		hB = Insert (hB, num_B);
		
		printf ("After Comparing the list is: ");	
	
		printf ("%d\n", CompareLists (hA, hB) );
	}
	
	return 0;
}

