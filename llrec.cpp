#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************



void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    std::cout << "new" << std::endl;
    // Base case: when head is NULL, we are done
    if (head == nullptr) {
        smaller = nullptr; // Ensure smaller and larger are null at the end of recursion
        larger = nullptr;
        return;
    }

    // Detach the current node from the list
    Node* current = head;
    head = head->next;
    current->next = nullptr;

    // Recursively process the remaining nodes
    if (current -> val <= pivot ){
        smaller = current;
        llpivot(head, smaller->next, larger, pivot);
    }else{
        larger = current;
        llpivot(head,smaller, larger->next, pivot);
    }
}

