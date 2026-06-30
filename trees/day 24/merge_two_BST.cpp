https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/

You are given two balanced binary search trees e.g., AVL or Red-Black Tree. 
Write a function that merges the two given balanced BSTs into a balanced binary search tree. 
Let there be m elements in the first tree and n elements in the other tree. Your merge function should take O(m+n) time.

  
Method 1 (Merge Inorder Traversals):
      Do inorder traversal of the first tree and store the traversal in one temp array arr1[]. This step takes O(m) time. 
      Do inorder traversal of the second tree and store the traversal in another temp array arr2[]. This step takes O(n) time. 
      The arrays created in steps 1 and 2 are sorted arrays. Merge the two sorted arrays into one array of size m + n. This step takes O(m+n) time. 
      Construct a balanced tree from the merged array using the technique discussed in this post. This step takes O(m+n) time.

// C++ Code for the above approach

/* A binary tree node has data,
a pointer to left child
and a pointer to right child */
class Node {
public:
    int data;
    Node* left;
    Node* right;
};

// Function to return a new Node
Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}



// Function to merge two sorted linked list
Node* mergeLinkedList(Node* head1, Node* head2)
{

    /*Create head and tail for result list*/
    Node* head = NULL;
    Node* tail = NULL;

    while (head1 && head2) {

        if (head1->data < head2->data) {

            if (!head)
                head = head1;
            else {

                tail->right = head1;
                head1->left = tail;
            }

            tail = head1;
            head1 = head1->right;
        }

        else {

            if (!head)
                head = head2;
            else {
                tail->right = head2;
                head2->left = tail;
            }

            tail = head2;
            head2 = head2->right;
        }
    }

    while (head1) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    // Return the created DLL
    return head;
}

// function to convert list to bst
Node* sortedListToBST(Node*& head, int n)
{
    // if no element is left or head is null
    if (n <= 0 || !head)
        return NULL;

    // Create left part from the list recursively
    Node* left = sortedListToBST(head, n / 2);

    Node* root = head;
    root->left = left;
    head = head->right;

    // Create left part from the list recursively
    root->right = sortedListToBST(head, n - (n / 2) - 1);

    // Return the root of BST
    return root;
}

// This function merges two balanced BSTs
Node* mergeTrees(Node* root1, Node* root2, int m, int n)
{
    // Convert BSTs into sorted Doubly Linked Lists

    Node* head1 = NULL;
    bstTodll(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    bstTodll(root2, head2);
    head2->left = NULL;

    // Merge the two sorted lists into one
    Node* head = mergeLinkedList(head1, head2);

    // Construct a tree from the merged lists
    return sortedListToBST(head, m + n);
}

/* Driver code*/
int main()
{
    /* Create following tree as first balanced BST
       100
       / \
      50 300
     / \
    20 70   */

    /* Create following tree as second balanced BST
             80
            / \
           40 120
    */

      // Function Call
    Node* mergedTree = mergeTrees(root1, root2, 5, 3);

    printInorder(mergedTree);

    return 0;
}

// This code is contributed by Tapesh(tapeshdua420)
