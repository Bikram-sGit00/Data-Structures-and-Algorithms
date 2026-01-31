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

Node* removeAtPosition(Node* head, int pos){
    if(head == NULL) return NULL;
    if(pos == 0){
        return deleteHead(head);
    }
    Node* kNode = head;
    int cnt = 0;
    while(kNode != NULL ){
        if(cnt == pos) break; // found the position
        kNode = kNode -> next; // iteration 
        cnt++;
    }
    Node* prev = kNode -> back; // node before kNode
    Node* nextNode = kNode -> next; // node after kNode

    if(prev == NULL && nextNode == NULL){
        // only one node present
        delete kNode;
        return NULL;
    }
    else if(prev == NULL){
        // first node
        head = deleteHead(head);
        return head;
    }
    else if(nextNode == NULL){
        // last node
        head = deleteTail(head);
        return head;
    }
    else{
        // middle node
        prev -> next = nextNode; // bypass kNode
        nextNode -> back = prev; // bypass kNode

        kNode -> next = nullptr; // disconnect kNode
        kNode -> back = nullptr; // disconnect kNode

        delete kNode;
        return head;
    }