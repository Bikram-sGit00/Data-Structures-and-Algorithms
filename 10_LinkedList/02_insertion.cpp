Node* insertHead(Node* head,int val){
    return new Node(val,head); // (given_value, next)
}

Node* insertTail(Node* head, int val){
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    Node* newNode = new Node(val);
    temp -> next = newNode;

    return head;
}