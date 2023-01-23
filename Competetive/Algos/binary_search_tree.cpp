//NOTE:
//BST has follwing properties.
//a.  Left sub-tree of node A contain elements that are lesser value than 'A'.
//b.  Right sub-tree of node 'A' contain elements that are higher value than 'A'.

#include <iostream>


struct Node
{
	int data;
	Node* left;
    Node* right;

	Node(int x):data{x}, left{nullptr}, right{nullptr} {}
};

Node* append(Node* node, int ival){
    if (node == nullptr) return new Node(ival);
    
    if (ival > node->data) { //value > node_val, so put to node's right
        node->right = append(node->right, ival);
    }else {//put it in its left
        node->left = append(node->left, ival);
    }
    return node;
}

void PrintResult(Node *node){
    if (node == NULL) return;

    PrintResult(node->left);
    std::cout<<node->data<<" -> ";
    PrintResult(node->right);
}

int main(){

    int ival;
    std::cout<<"Enter elements (-999 to exit) ";
    std::cin>>ival;

    if(ival == -999) return 0;

    Node *head = append(nullptr, ival);
    while (true){
        std::cout<<"Enter elements (-999 to exit) ";
        std::cin>>ival;
        if (ival == -999) break;
        append(head, ival);
    }

    PrintResult(head);
    return 0;
}