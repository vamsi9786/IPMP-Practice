
Algorithm:
    1. if t->data > pivot->data then remove t and add to end i.e next of tail
        else none
    2. recurrsively sort(left ) and sort(right)
        by finding new head and new tail and 
                sort(newHead,pivot) and 
                link tail(newHead)->next as pivot and
                pivot->next=sort(pivot->next,newTail).

class Solution {
public:

    Node* getTail(Node* cur) {
        while (cur != NULL && cur->next != NULL)
            cur = cur->next;
        return cur;
    }

    Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {

        Node* pivot = end;
        Node* prev = NULL;
        Node* cur = head;
        Node* tail = pivot;

        while (cur != pivot) {

            if (cur->data < pivot->data) {

                if (*newHead == NULL)
                    *newHead = cur;

                prev = cur;
                cur = cur->next;
            }

            else {

                if (prev)
                    prev->next = cur->next;

                Node* temp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = temp;
            }
        }

        if (*newHead == NULL)
            *newHead = pivot;

        *newEnd = tail;

        return pivot;
    }

    Node* quickSortRecur(Node* head, Node* end) {

        if (!head || head == end)
            return head;

        Node* newHead = NULL;
        Node* newEnd = NULL;

        Node* pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot) {

            Node* temp = newHead;

            while (temp->next != pivot)
                temp = temp->next;

            temp->next = NULL;

            newHead = quickSortRecur(newHead, temp);

            temp = getTail(newHead);
            temp->next = pivot;
        }

        pivot->next = quickSortRecur(pivot->next, newEnd);

        return newHead;
    }

    Node* quickSort(Node* head) {
        Node* tail = getTail(head);
        return quickSortRecur(head, tail);
    }
};
