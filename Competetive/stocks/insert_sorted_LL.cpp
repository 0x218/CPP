#include <bits/stdc++.h>

using namespace std;

typedef struct Node{
    int data;
    Node *next;
}Node;

////Good for liniar singly link list
// Node* CreateList(Node* node, const int& nodeVal){
//     if (node == NULL){
//         Node *temp = new Node();
//         temp->data = nodeVal;
//         temp->next = NULL;
//         return temp;
//     }
//     else{
//         node->next = CreateList(node->next, nodeVal);
//     }
// }

void CreateSortedList(Node** head_ref, Node** tail){
    Node* curNode;
    if(     ((*head_ref) == NULL) || ((*head_ref)->data >= ((*tail)->data) )   ){
        (*tail)->next =  *head_ref;
        *head_ref = *tail;
    }else{
        curNode = *head_ref;
        while(curNode->next != NULL && curNode->next->data < (*tail)->data){
            curNode = curNode->next;
        }
        (*tail)->next = curNode->next;
        curNode->next= *tail;
    }
}


void PrintList(const Node *node){
    if(node != NULL){
        cout<<node->data<<" ";
        PrintList(node->next);
    }
}

int main(){
    cout<<"number of nodes insering? ";
    int count, nodeVal; 
    cin>>count;

    Node *head = NULL;
    Node *tail;

    while(count --){
        cout<<"Enter an integer as node value : ";
        cin>>nodeVal;
        //head = CreateList(head, nodeVal);
        tail = new Node();
        tail->data = nodeVal;
        tail->next = NULL;
        CreateSortedList(&head, &tail);

    }

    PrintList(head);
}