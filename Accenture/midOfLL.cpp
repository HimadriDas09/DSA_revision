Node *findMiddle(Node *head) {
    // Write your code here
    Node* dummy = new Node(-1);
    dummy->next = head;
    Node* slow = dummy;
    Node* fast = dummy;

    //standard fast and slow approach
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast == NULL) return slow;
    else if(fast->next == NULL) return slow->next;
}