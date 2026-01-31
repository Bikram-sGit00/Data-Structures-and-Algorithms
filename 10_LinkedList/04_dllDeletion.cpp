Node* deleteHead(Node* head){
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head -> next;

    head -> back = nullptr;
    prev -> next = nullptr;

    delete prev;
    return head;

}

