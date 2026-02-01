Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr); //(val, next, prev);
    head -> prev = newHead;
    return newHead;
}

Node* insertBeforeTail(Node* head, int val){
    if(head -> next == NULL){
        return insertBeforeHead(head, val);
    }
    Node* tail = head; // find tail
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    Node* prev = tail -> back;
    Node* newNode = new Node(val, tail, prev); //(val, next, prev);
    prev -> next = newNode;
    tail -> back = newNode;
    return head;
}