#include <bits/stdc++.h>

struct Node{
    int data;
    Node* next;
};

void insertIntoList(Node **node, int num){
    if (*node == NULL){
        *node = new Node;
        (*node)->data = num;
        (*node)->next = NULL;
    }
    else{
        insertIntoList(&(*node)->next, num);
    }
}

void printList(Node *node){
    while (node != NULL){
        std::cout<<node->data <<" -> ";
        node = node->next;
    }
}

void deleteNode(Node *&node, int num){
    if (node == NULL){
        std::cout<<"data not found.";
        return;
    }
    if (node->data == num){
        Node *deleteThis = node;
        node = node->next;
        
        delete deleteThis;
        return;
    }
    else{
        deleteNode(node->next, num);
    }
}



int main(){
    Node* head = NULL;
    
    int num = 0;
    while (num != 999){
        std::cout<<"enter numbers (999 to exit): ";
        std::cin>>num;
        insertIntoList(&head, num);
    }

    printList(head);

    std::cout<<"\nenter a node value to delete";
    std::cin>>num;
    deleteNode(head, num);
    
    printList(head);

    return 0;    
}