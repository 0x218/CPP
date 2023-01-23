#include <bits/stdc++.h>

using namespace std;

// Link list node
struct Node
{
	int data;
	struct Node* next;
	Node( int x){
		data = x;
		next = NULL;
	}
};

void append (Node **head_ref, Node** tail_ref, int data ){
	Node *tempNode = new Node (data);
	tempNode->next = NULL;

	if (*head_ref == NULL){
		*head_ref = tempNode;
	}
	else{
		(*tail_ref)->next = tempNode;
	}
	*tail_ref = tempNode;
}

void printNode(const Node *head)
{
	while (head != NULL){
		std::cout<<head->data<<" --> ";
		head = head->next;
	}
	std::cout<<"NILL"<<std::endl;
}


Node *frontPointer = NULL;

bool IsPalindrome(Node *node){
	if (node != NULL){
		if(!IsPalindrome(node->next)) return false; //add call to the stack, and 'return' logic is in line#44.
		if (node->data != frontPointer->data) return false;
		frontPointer = frontPointer->next;
	}
	return true;
}


int main(){

	Node *head, *tail;
	int data_val = 0;
	while (true){
		std::cout<<"Enter a number to insert (NOTE: -999 to terminate) ";
		std::cin>>data_val;

		if (data_val == -999) break;
		append(&head, &tail, data_val);
	}
	//printNode(head);
	
	frontPointer = head;
	if (IsPalindrome(head)){
		std::cout<<"Yes"<<std::endl;
	}
	else{
		std::cout<<"No"<<std::endl;
	}


	return 0;
}


