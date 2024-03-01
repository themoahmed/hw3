#include <iostream>
using namespace std;

// Assuming this is a simplified version of the Node structure from llrec.h
struct Node {
    int val;
    Node *next;
    Node(int v, Node* n = nullptr) : val(v), next(n) {} // Constructor for convenience
};

// Direct inclusion of llpivot function for testing

// void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot){
//     if (head == NULL){
//         if (smaller != nullptr){
//             smaller -> next = nullptr;
//         }
//         if (larger != nullptr){
//             larger -> next = nullptr;
//         }
//         return;

//     }
//     if(head->val > pivot){
       
//         if (larger == NULL){
//             larger = head;
//             head = head -> next;
//         }else{
//             larger->next = head;
//             head = head -> next; 
//         }
//         llpivot(head, smaller, larger, pivot);
//     }

//     if(head->val <= pivot){

        
//         if (smaller == NULL){
//             smaller = head;
//             head = head -> next;
//         }else{
//             smaller->next = head;
//             head = head -> next; 
//         }
//         llpivot(head, smaller, larger, pivot);
//     }
// }

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    // Base case: when head is NULL, we are done
    if (head == NULL) {
        return;
    }

    // Save the next node because we're going to modify head->next
    Node* next = head->next;

    if (head->val <= pivot) {
        // Append to the smaller list
        head->next = smaller; // Point the current node to the front of the smaller list
        smaller = head; // Move the head of the smaller list to the current node
    } else {
        // Append to the larger list
        head->next = larger; // Point the current node to the front of the larger list
        larger = head; // Move the head of the larger list to the current node
    }

    // Recursively process the next node in the list
    llpivot(next, smaller, larger, pivot);
}





// Helper function to print the list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Main function for testing
int main() {
    // Example list: 5 -> 1 -> 8 -> 3 -> 2 -> NULL
    Node* head = new Node(5, new Node(1, new Node(8, new Node(3, new Node(2)))));
    Node* smaller = nullptr;
    Node* larger = nullptr;

    llpivot(head, smaller, larger, 4); // Use 4 as pivot for this example

    std::cout << "Smaller or equal to pivot: ";
    printList(smaller);
    std::cout << "Larger than pivot: ";
    printList(larger);
    std::cout << head << endl;

    // Remember to free the allocated memory here
    // (For simplicity, memory deallocation is not included)

    return 0;
}
