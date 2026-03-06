Given a doubly linked list containing n nodes, each node is at most k-indices away from its target position. 
The problem is to sort the given doubly linked list. The distance can be assumed in either of the directions (left and right).

Algorithm:  [Naive Approach] Using Insertion sort - O(n*k) time and O(1) space
      The idea is to use insertion sort to sort the doubly linked list. 
      While inserting each element in the sorted part of the list, there will be atmost k swaps to place the element to its correct position 
      since every node is is atmost k steps away from its correct position.

Step 1: Take first/head ele as part of sorted arr
Step 2: while(curr!=NULL){
            (i). store present(i.e before swapping) curr->next value
                    next=curr->next;
            (ii). while(curr->prev != NULL && curr->data < curr->prev->data) {
                      swap curr and curr->prev
                  }
            (iii). if(curr is newHead i.e curr->prev==NULL) then update head
            (iv). curr=next;
        }


/*class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};*/

// Function to sort a k-sorted doubly linked list
Node *sortAKSortedDLL(Node *head, int k) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *node = head->next;

    // Perform on all the nodes in the list
    while (node != nullptr) {
        Node *next = node->next;
        Node *curr = node;

        while (curr->prev != nullptr &&
               curr->data < curr->prev->data) {

            // Swap curr and curr->prev node
            Node *node1 = curr->prev->prev; 
            Node *node2 = curr->prev;      
            Node *node3 = curr->next;      
            if (node1 != nullptr)
                node1->next = curr;
            curr->prev = node1;

            node2->next = node3;
            if (node3 != nullptr)
                node3->prev = node2;

            curr->next = node2;
            node2->prev = curr;
        }

        // If curr is now the new head, 
      	// then reset head
        if (curr->prev == nullptr)
            head = curr;

        node = next;
    }
    return head;
}

void printList(Node *curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
