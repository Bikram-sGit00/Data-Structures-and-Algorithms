Node* deleteHead(Node* head) {
    if (head == nullptr) {
        return nullptr; // List is empty, nothing to delete
    }
    Node* newHead = head->next; // The new head will be the second node
    delete head; // Free memory of the old head or free(head) 
    return newHead; // Return the new head of the list
}