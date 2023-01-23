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

Node *pairWiseSwap(Node *head)
{
    if (head == NULL || head->next == NULL) return head; //nothing to swap
 
    //Explicitly fix the head and its next node
    Node *third = head->next->next;  //Node third = head->next-next
    Node *first = head;              //Node* second = head
    head = head->next;              //head = second.
    head->next = first;              //second->next = first
 
    //Fix remaining nodes
    while (third != NULL && third->next != NULL)
    {
        first->next = third->next;
        first = third;
        Node *next = third->next->next;
        third->next->next = third;
        third = next;
    }
    first->next = third;
 
    return head;
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
	printNode(head);
    head = pairWiseSwap(head);
    printNode(head);
	return 0;
}


