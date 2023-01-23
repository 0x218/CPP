//binary search tree
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left = NULL;
    Node* right = NULL;
};


Node* createNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* generateTree(Node* node, int data){
    if (node == NULL){
        node = createNode(data);
    }
    else if (data <= node->data){
        node->left = generateTree(node->left, data);
    }
    else{
        node->right = generateTree(node->right, data);
    }
    return node;
}


void BuildATree(Node **root){
    int data;
    std::cout<<"Enter numbers (999 to exit) ";
    while (1){
        std::cin>>data;
        
        if (data == 999) break;
        
        *root = generateTree(*root, data);
    }
}

void TraverseTree(const Node* node){
    if(node == NULL) return;
    cout<<node->data<<" ";
    
    TraverseTree(node->left);
    TraverseTree(node->right);
}

bool Search(Node* node, int val){
    if (node == NULL ) {    cout<<"data not found\n"; return true; }
    std::cout<<node->data<<" -> ";
    if(node->data == val) { cout<<"data found\n"; return true; }
    if (val < node->data) {    Search(node->left, val);    }
    else {  Search(node->right, val);   }
    return false;
}

void SearchElement(Node* root){
    cout<<"\nEnter a value to find element ";
    int ival;
    cin>>ival;
    
    Search(root, ival);
}

Node* deleteNode(Node* node, int nodeValue)
{
    // Base case
    if (node == NULL) return node;
  
    // Recursive calls for ancestors of node to be deleted
    if (node->data > nodeValue) {
        node->left = deleteNode(node->left, nodeValue);
        return node;
    }
    else if (node->data < nodeValue) {
        node->right = deleteNode(node->right, nodeValue);
        return node;
    }
  
    // We reach here when root is the node to be deleted. here node->data is nodeValue.    
  
    // If one of the children is empty
    if (node->left == NULL) {
        Node* temp = node->right;
        delete node;
        return temp;
    }
    else if (node->right == NULL) {
        Node* temp = node->left;
        delete node;
        return temp;
    }
  
    // If both children exist
    else {
  
        Node* succParent = node;
  
        // Find successor
        Node* succ = node->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
  
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != node)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
  
        // Copy Successor Data to root
        node->data = succ->data;
  
        // Delete Successor and return root
        delete succ;
        return node;
    }
}

int main(){
    Node *root = NULL;
    BuildATree(&root);
    TraverseTree(root);
    SearchElement(root);
    root = deleteNode(root, 20);
    TraverseTree(root);
    return 0;
}