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

struct Node* head;

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

void Delete (int n){
	struct Node* tmp1 = head;
	
	if (n == 0){
		head = tmp1->next;
		free(tmp1);
		return;
	}
	
	for (int i = 0 ; i < n-1; i++){
		tmp1 = tmp1->next;
	}
	
	struct Node* tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	free(tmp2);
	
}

int main(){
	int n, i, num, pos;
	head = NULL;
	printf ("How many Numbers?\n");
	scanf ("%d", &n);
	
	printf ("Enter the %d Number: ", n);
	for (i = 0; i < n; i++){
		//printf ("Enter the Number \n");
		scanf ("%d", &num);
		head = Insert (head, num);
		//Print (head);
	}
	printf ("The final list is: ");
	Print (head);
	puts ("");
	
	printf ("Enter the position Number \n");
	scanf ("%d", &pos);
	
	Delete (pos);
	
	printf ("After deleting nth node the list is: ");
	Print (head);
	return 0;
}
