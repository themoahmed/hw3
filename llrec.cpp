#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot){
    if (head == NULL){
        return;
    }
    if(head->val > pivot){
        Node*& headNext = head->next;
        head->next == NULL;
        if (larger == NULL){
            larger == head;
        }else{
            larger->next = head;
        }

        llpivot(headNext, smaller, larger, pivot);
    }

    if(head->val < pivot){
        Node*& headNext = head->next;
        head->next == NULL;
        if (smaller == NULL){
            smaller == head;
        }else{
            smaller->next = head;
        }

        llpivot(headNext, smaller, larger, pivot);
    }
}