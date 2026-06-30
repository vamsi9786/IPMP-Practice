https://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/

Given a Doubly Linked List which has data members sorted in ascending order. 
Construct a Balanced Binary Search Tree which has same data members as the given Doubly Linked List. 
The tree must be constructed in-place (No new node should be allocated for tree conversion) 


#include <bits/stdc++.h>
using namespace std;

/* A Doubly Linked List node that
will also be used as a tree node */
class Node 
{ 
    public:
    int data; 

    // For tree, next pointer can be
    // used as right subtree pointer 
    Node* next; 

    // For tree, prev pointer can be
    // used as left subtree pointer 
    Node* prev; 
}; 


/* This function counts the number of 
nodes in Linked List and then calls 
sortedListToBSTRecur() to construct BST */
Node* sortedListToBST(Node *head) 
{ 
    /*Count the number of nodes in Linked List */
    int n = countNodes(head); 

    /* Construct BST */
    return sortedListToBSTRecur(&head, n); 
} 

/* The main function that constructs 
balanced BST and returns root of it. 
head_ref --> Pointer to pointer to
head node of Doubly linked list 
n --> No. of nodes in the Doubly Linked List */
Node* sortedListToBSTRecur(Node **head_ref, int n) 
{ 
    /* Base Case */
    if (n <= 0) 
        return NULL; 

    /* Recursively construct the left subtree */
    Node *left = sortedListToBSTRecur(head_ref, n/2); 

    /* head_ref now refers to middle node,
    make middle node as root of BST*/
    Node *root = *head_ref; 

    // Set pointer to left subtree 
    root->prev = left; 

    /* Change head pointer of Linked List
    for parent recursive calls */
    *head_ref = (*head_ref)->next; 

    /* Recursively construct the right 
    subtree and link it with root 
    The number of nodes in right subtree
    is total nodes - nodes in 
    left subtree - 1 (for root) */
    root->next = sortedListToBSTRecur(head_ref, n-n/2-1); 

    return root; 
} 

/* UTILITY FUNCTIONS */
/* A utility function that returns 
count of nodes in a given Linked List */
int countNodes(Node *head) 
{ 
    int count = 0; 
    Node *temp = head; 
    while(temp) 
    { 
        temp = temp->next; 
        count++; 
    } 
    return count; 
} 


/* Driver code*/
int main() 
{ 
    /* Start with the empty list */
    Node* head = NULL; 

    /* Let us create a sorted linked list to test the functions 
    Created linked list will be 7->6->5->4->3->2->1 */

    /* Convert List to BST */
    Node *root = sortedListToBST(head); 

    return 0; 
} 

// This code is contributed by rathbhupendra
