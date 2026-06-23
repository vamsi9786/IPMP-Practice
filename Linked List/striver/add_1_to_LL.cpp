Add 1 to a number represented by LL

Problem Statement: Given the head of a singly linked list representing a positive integer number. 
Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. 
The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.

The number will contain no leading zeroes except when the value represented is zero itself.

class Solution {
public:

    int solve(Node* head) {

        if (head == NULL)
            return 1; // initial +1

        int carry = solve(head->next);

        int sum = head->data + carry;

        head->data = sum % 10;

        return sum / 10;
    }

    Node* addOne(Node* head) {

        int carry = solve(head);

        if (carry) {
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};
