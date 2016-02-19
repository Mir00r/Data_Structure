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



Node* Reverse (Node* head){
	
	struct Node *current, *prev, *next;
	current = head;
	prev = NULL;
	
	while (current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	head = prev;
	return head;
}

int main(){
	int n, i, num;
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
	
	printf ("After Reversing the list: ");
	head = Reverse(head);
	Print (head);
	return 0;
}
