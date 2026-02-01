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

Node* insertAtPosition(Node* head, int pos, int val){
    if(head == NULL || pos == 0) return new Node(val, head);
    Node* temp = head;
    int cnt = 0;
    while (temp != NULL && cnt < pos - 1){
        cnt++;
        if(cnt == pos - 1){
            Node* newNode = new Node(val, temp -> next);
            temp -> next = newNode;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int target, int val){
    if(head == NULL) return NULL;
    Node* temp = head;
    while (temp -> next != NULL){
        if(temp -> next -> data == target){
            Node* newNode = new Node(val, temp -> next);
            temp -> next = newNode;
            break;
        }
        temp = temp -> next;
    }
    return head;
}
