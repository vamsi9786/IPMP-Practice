Given a Doubly linked list containing n nodes. The task is to reverse every group of k nodes in the list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end should be considered as a group and must be reversed.

[Expected Approach - 1] Using Recursion - O(n) Time and O(n) Space:
    The idea is to reverse the first k nodes of the list and update the head of the list to the new head of this reversed segment. 
    Then, connect the tail of this reversed segment to the result of recursively reversing the remaining portion of the list.

[Expected Approach - 2] Using Iterative Method - O(n) Time and O(1) Space:
    The idea is to traverse the list in groups of k nodes, reversing each group. 
    After reversing a group, link it to the previous group by updating the tail pointer. 
    Continue until the entire list is traversed and return the new head.

/*class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/

[Expected Approach - 1] Using Recursion - O(n) Time and O(n) Space:

// Helper function to reverse K nodes
Node *reverseKNodes(Node *head, int k) {
    Node *curr = head, *prev = nullptr, *next = nullptr;
    int count = 0;

    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        curr->prev = nullptr;
        if (prev != nullptr) {
            prev->prev = curr;
        }
        prev = curr;
        curr = next;
        count++;
    }

    return prev;
}

// Recursive function to reverse in groups of K
Node *reverseKGroup(Node *head, int k) {
    if (head == nullptr) {
        return head;
    }
    Node *groupHead = nullptr;
    Node *newHead = nullptr;

    // Move temp to the next group
    Node *temp = head;
    int count = 0;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }

    // Reverse the first K nodes
    groupHead = reverseKNodes(head, k);

    // Connect the reversed group with the next part
    if (newHead == nullptr) {
        newHead = groupHead;
    }

    // Recursion for the next group
    head->next = reverseKGroup(temp, k);
    if (head->next != nullptr) {
        head->next->prev = head;
    }

    return newHead;
}



[Expected Approach - 2] Using Iterative Method - O(n) Time and O(1) Space:

// Helper function to reverse K nodes iteratively
Node *reverseKGroup(Node *head, int k) {
    if (head == nullptr) {
        return head;
    }

    Node *curr = head;
    Node *newHead = nullptr;
    Node *tail = nullptr;

    while (curr != nullptr) {
        Node *groupHead = curr;
        Node *prev = nullptr;
        Node *next = nullptr;
        int count = 0;

        // Reverse the nodes in the current group
        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            curr->prev = nullptr;
            if (prev != nullptr) {
                prev->prev = curr;
            }
            prev = curr;
            curr = next;
            count++;
        }

        // If newHead is null, set it to the
      	// last node of the first group
        if (newHead == nullptr) {
            newHead = prev;
        }

        // Connect the previous group to the 
      	// current reversed group
        if (tail != nullptr) {
            tail->next = prev;
            prev->prev = tail;
        }

        // Move tail to the end of the reversed group
        tail = groupHead;
    }

    return newHead;
}
