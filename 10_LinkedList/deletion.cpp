Node* deleteHead(Node* head) {
    if (head == nullptr) {
        return nullptr; // List is empty, nothing to delete
    }
    Node* newHead = head->next; // The new head will be the second node
    delete head; // Free memory of the old head or free(head) 
    return newHead; // Return the new head of the list
}

Node* deleteTail(Node* head){
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    free(temp -> next); // delete temp -> next
    temp -> next = nullptr;
    
    return head;
}