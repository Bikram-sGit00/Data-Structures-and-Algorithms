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

Node* deletePos(Node* head, int k){
    if(head == NULL) return head; 
    if(k == 1){
        head = head -> next;
        return head;
    }
    int cnt = 0; // tell us in which element we're  
    int prev = NULL; // previous of 'cnt' element , set as null while cnt = 0
    Node* temp = head;
    while (temp != NULL)
    {
        cnt++;
        if(cnt == k){
            prev -> next = prev -> next -> next; // skiping one element for deleting
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    
    return head;
}

