//is this a binary search tree?

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left = NULL;
    Node *right = NULL;
};


Node* addNewNode(int data){
    Node* tempNode  = new Node;
    tempNode->data = data;
    tempNode->left = NULL;
    tempNode->right = NULL;
    
    return tempNode;
}


//bool isBST(const Node* root, const Node* l = NULL, const Node* r = NULL){
bool isBST(const Node* node){
    if (node == NULL) return true;
    if (node->left != NULL && node->left->data >= node->data )  return false;//left value should be less
    if (node->right != NULL && node->right->data <= node->data )  return false;//right value should be greater
    
    return (isBST(node->left) && isBST(node->right));
}

int main(){
    Node* root = addNewNode(3);
    root->left = addNewNode(2);
    root->right = addNewNode(5);
    root->left->left = addNewNode(1);
    root->left->right = addNewNode(4);
    
    bool bBst = isBST(root);
    std::string result = (bBst == true) ? "a Binary Search Tree" : "not a BST tree";
    cout<<"This is "<< result;
    
    return 0;
}
