Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr); //(val, next, back);
    if(head != nullptr){
        head -> back = newHead;
    }
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

Node* insertBeforePosition(Node* head, int val, int pos){
    if(pos == 1) return insertBeforeHead(head, val);
    Node* temp =  head;
    int cnt = 0;
    while(temp != NULL){
        if(cnt == pos) break;
        temp = temp -> next;
        cnt++;
    }
    Node *prev = temp -> back;
    Node* newNode = new Node(val, temp, prev); //(val, next, prev);
    prev -> next = newNode;
    temp -> back = newNode;
    
    return head;
}

void insertBeforeNode(Node* givenNode,int val){
    Node* prev = givenNode -> back;
    Node* newNode = new Node(val, givenNode, prev);
    prev -> next = newNode;
    givenNode -> back = newNode;

}