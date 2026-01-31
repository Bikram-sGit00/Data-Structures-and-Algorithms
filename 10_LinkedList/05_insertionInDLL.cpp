Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr); //(val, next, prev);
    head -> prev = newHead;
    return newHead;
}