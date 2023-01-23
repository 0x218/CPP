//get leaf count of a binary search tree.
#include <bits/stdc++.h>
using namespace std;
  
/* A binary tree node has data, 
pointer to left child and 
a pointer to right child */
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};


/* Function to get the count of leaf nodes in a binary tree*/
int getLeafCount(const Node* node){
    if (node == NULL) return 0;
    
    if (node->left == NULL && node->right == NULL){
        return 1;
    }
    else {
        return (getLeafCount(node->left) + getLeafCount(node->right));
    }
}

  
/* Helper function that allocates a new node with the given data and NULL left and right pointers. */
struct Node* newNode(int data){
    struct Node* node = new Node;
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    
    return node;
}
  
/*Driver code*/
int main() 
{ 
    /*create a tree*/
    Node *root = newNode(1);
    root->left = newNode(2);    
    root->right = newNode(3);
    root->left->left = newNode (4); 
    root->left->right=newNode(5);
    /*get leaf count of the above created tree*/
    cout << "Leaf count of the tree is : "<< getLeafCount(root) << endl; 
    return 0; 
} 