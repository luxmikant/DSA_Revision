#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to print the list
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to reverse a doubly linked list
Node* reverseDLL(Node* head) {
    Node* temp = nullptr;
    Node* current = head;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp) {
        head = temp->prev;
    }
    return head;
}

// Function to merge two sorted doubly linked lists
Node* mergeSortedDLL(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;

    if (first->data < second->data) {
        first->next = mergeSortedDLL(first->next, second);
        first->next->prev = first;
        first->prev = nullptr;
        return first;
    } else {
        second->next = mergeSortedDLL(first, second->next);
        second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

// Function to sort a bitonic doubly linked list
Node* sortBitonicDLL(Node* head) {
    if (!head || !head->next) return head;

    // Step 1: Identify the peak node
    Node* peak = head;
    while (peak->next && peak->data < peak->next->data) {
        peak = peak->next;
    }

    // Step 2: Split the list
    Node* second = peak->next;
    if (second) {
        second->prev = nullptr;
    }
    peak->next = nullptr;

    // Step 3: Reverse the second part
    second = reverseDLL(second);

    // Step 4: Merge the two sorted lists
    return mergeSortedDLL(head, second);
}

// Helper function to insert a new node at the end of the list
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int main() {
    Node* head = nullptr;
    insertEnd(head, 1);
    insertEnd(head, 3);
    insertEnd(head, 6);
    insertEnd(head, 9);
    insertEnd(head, 8);
    insertEnd(head, 5);
    insertEnd(head, 2);

    std::cout << "Original Bitonic DLL: ";
    printList(head);

    head = sortBitonicDLL(head);

    std::cout << "Sorted DLL: ";
    printList(head);

    return 0;
}