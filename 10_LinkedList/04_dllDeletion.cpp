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

Node* deleteTail(Node* head){
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail -> next != NULL){
        tail = tail -> next; // stoped at last node
    }
    node* prev = tail -> back ; // will give us second last node
    tail -> back = nullptr; // disconnect last node from second last node
    prev -> next = nullptr; // disconnect second last node from last node
    
    delete tail;
    return head;
}