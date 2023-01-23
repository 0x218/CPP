#include <bits/stdc++.h>

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void insertIntoList(Node *node, int &num)
{
    if (node->next == NULL)
    {
        Node *tmp = new Node;
        tmp->data = num;
        tmp->prev = node;
        tmp->next = NULL;
        node->next = tmp;
    }
    else
    {
        insertIntoList(node->next, num);
    }
}

void printList(Node *node)
{
    if (node == NULL) return;
    std::cout<<node->data<<" -> ";
    printList(node->next);
}

void deleteNode(Node *&node, int num)
{
    if (node == NULL)
    {
        std::cout << "data not found.";
        return;
    }
    if (node->data == num)
    {
        Node *deleteThis = node;
        node = node->next;

        delete deleteThis;
        return;
    }
    else
    {
        deleteNode(node->next, num);
    }
}

int main()
{
    Node *head = NULL;
    // Node *next = NULL;
    Node *tail = NULL;
    int num = 0;
    while (num != 999)
    {
        std::cout << "enter numbers (999 to exit): ";
        std::cin >> num;
        if (head == NULL)
        {
            head = new Node;
            head->data = num;
            head->next = NULL;
            head->prev = NULL;
        }
        else
        {
            // insertIntoList(head, &tail, num);
            insertIntoList(head, num);
        }
    }

    printList(head);
 
    // std::cout<<"\nenter a node value to delete";
    // std::cin>>num;
    // deleteNode(head, num);

    // printList(head);

    return 0;
}