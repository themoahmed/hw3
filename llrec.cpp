#include "llrec.h"


//*********************************************
// Provide your implementation of llpivot below
//*********************************************



void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {

    // Base case head is NULL
    if (head == nullptr) {
        smaller = nullptr; 
        larger = nullptr;
        return;
    }

    // Detach the current node 
    Node* current = head;
    head = head->next;
    current->next = nullptr;

    // Recursively process
    if (current -> val <= pivot ){
        smaller = current;
        llpivot(head, smaller->next, larger, pivot);
    }else{
        larger = current;
        llpivot(head,smaller, larger->next, pivot);
    }
}

