#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
#define row 100
#define col 100
#define NL puts("")

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node *hA;

void Print(Node *matha) {
	struct Node* temp = matha;
	printf("Forward: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}


Node* SortedInsert(Node *matha, int data){
	
	Node *head = matha, *prev;
	//Node *newNode = new Node; // for C++
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));	// for C
		
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	// Handle empty list
	if (matha == NULL) {
		return newNode;
	}

	// Handle newNode being the new head
	if (data <= matha->data) {
		newNode->next = matha;
		matha->prev = newNode;
		return newNode;
	}

	while (matha != NULL) {
		// Place the newNode before the current
		// matha if its data is less than the current
		// matha's data
		if (data <= matha->data) {
			matha->prev->next = newNode;
			newNode->prev = matha->prev;
			newNode->next = matha;
			matha->prev = newNode;
			return head;
		}

		// Store the previous matha in the case
		// the matha should be placed last
		prev = matha;
		matha = matha->next;
	}

	// Add the matha to the end of the list
	matha = prev;
	matha->next = newNode;
	newNode->prev = matha;
	return head;
}
	
int main(){
	int n, i, num_A;
	//head = NULL;
	hA = NULL;
	
	printf ("Enter the size of List A\n");
	scanf ("%d", &n);
	NL;
		
	printf ("Enter %d Numbers in head A: ", n);
	for (i = 0; i < n; i++){
		scanf ("%d", &num_A);
		
		hA = SortedInsert (hA, num_A);
		Print (hA);
	}
	return 0;
}


