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

void Insert (int n){
	struct Node* tmp = (Node*)malloc( sizeof (struct Node) ); 
	tmp->data = n;
	tmp->next = head;
	
	// if (head != NULL) tmp->next = head;
	
	head = tmp;
}

void Print (){
	struct Node* tmp = head;
	printf ("The List is: ");
	
	while ( tmp != NULL ){
		printf (" %d", tmp->data );
		tmp = tmp->next;
	}
	puts ("");
}

int main(){
	int n, i, num;
	head = NULL;
	printf ("How many Numbers?\n");
	scanf ("%d", &n);
	
	for (i = 0; i < n; i++){
		printf ("Enter the Number \n");
		scanf ("%d", &num);
		
		Insert (num);
		Print ();
	}
	return 0;
}


// Way Number 2

struct Node{
	int data;
	struct Node* next;
};

//struct Node* head;

Node* Insert (Node* head, int n){
	
	struct Node* tmp = (Node*)malloc( sizeof (struct Node) ); 
	tmp->data = n;
	tmp->next = head;
	if (head != NULL) tmp->next = head;
	head = tmp;
	
	return head;
}

// Insert Element in Tail
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
	
	printf ("The List is: ");
	
	while ( head != NULL ){
		printf (" %d", head->data );
		head = head->next;
	}
	puts ("");
}

int main(){
	int n, i, num;
	//head = NULL;
	struct Node* head = NULL;
	
	printf ("How many Numbers?\n");
	scanf ("%d", &n);
	
	for (i = 0; i < n; i++){
		printf ("Enter the Number \n");
		scanf ("%d", &num);
		
		head = Insert (head, num);
		Print (head);
	}
	return 0;
}
