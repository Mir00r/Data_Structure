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

void Print (){
	//struct Node* tmp = head; // for C
	Node* tmp = head; // for C++
	printf ("The list is: ");
	while ( tmp != NULL ){
		printf (" %d", tmp->data );
		tmp = tmp->next;
	}
	puts ("");
}

void Insert (int val, int pos){
	//struct Node* tmp = (Node*)malloc( sizeof (struct Node) ); // for node delearation in C
	Node* tmp1 = new Node(); // for node delearation in C++
	tmp1->data = val;
	tmp1->next = NULL;

	if (pos == 1){
		tmp1->next = head;
		head = tmp1;
		return;
	}
	
	//Node* tmp2 = new Node();
	Node* tmp2 = head;
	for (int i = 0; i < pos-2; i++){
		tmp2 = tmp2->next;
	}
	
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
}

// Another way to insert element

Node* InsertNth(Node *head, int val, int pos){
  // Complete this method only
  // Do not write main function. 
    
    Node* tmp1 = new Node(); // for node delearation in C++
	tmp1->data = val;
	tmp1->next = head;

	if (pos == 0){
		tmp1->next = head;
		head = tmp1;
		return head;
	}
	
	//Node* tmp2 = new Node();
	Node* tmp2 = head;
	for (int i = 0; i < pos-1; i++){
		tmp2 = tmp2->next;
	}
	
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
    
    return head;
}


int main(){
	int n, i, num, pos;
	head = NULL;
	printf ("How many Numbers?\n");
	scanf ("%d", &n);
	
	for (i = 0; i < n; i++){
		printf ("Enter the Number \n");
		scanf ("%d", &num);
		printf ("Enter the position Number \n");
		scanf ("%d", &pos);
		Insert (num, pos);
		Print ();
	}
	
	//Print ();
	return 0;
}

/*
int main (){
	head = NULL; // initially the list is empty
	
	Insert (2, 1); // list 2
	Insert (3, 2); // list 2, 3
	Insert (4, 1); // lsit 4, 2, 3
	Insert (5, 2); // list 4, 5, 2, 3
	
	Print ();
	return 0;
}*/
