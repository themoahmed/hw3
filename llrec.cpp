#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


// void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
//     // Base case: when head is NULL, we are done
//     if (head == NULL) {
//         return;
//     }

//     // Save the next node because we're going to modify head->next
//     Node* next = head->next;

//     if (head->val <= pivot) {
   
//         head->next = smaller; 
//         smaller = head; 
//     } else {
       
//         head->next = larger; 
//         larger = head; 
//     }

//     // Recursively process the next node in the list
//     llpivot(next, smaller, larger, pivot);
// }

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    std::cout << "new" << std::endl;
    // Base case: when head is NULL, we are done
    if (head == NULL) {
        smaller = nullptr; // Ensure smaller and larger are null at the end of recursion
        larger = nullptr;
        return;
    }

    // Detach the current node from the list
    Node* current = head;
    head = head->next;
    current->next = nullptr;

    // Recursively process the remaining nodes
    Node* tempSmaller = nullptr;
    Node* tempLarger = nullptr;
    llpivot(head, tempSmaller, tempLarger, pivot);

    // Insert the current node into either smaller or larger list
    if (current->val <= pivot) {
        // Insert at the beginning of the smaller list
        current->next = tempSmaller;
        tempSmaller = current;
        smaller = tempSmaller;
    } else {
        // Insert at the beginning of the larger list
        current->next = tempLarger;
        tempLarger = current;
        larger = tempLarger;
    }

    // When processing the first node, ensure head is set to NULL to indicate the original list is empty
    if (head != nullptr) {
        head = nullptr;
    }
}

