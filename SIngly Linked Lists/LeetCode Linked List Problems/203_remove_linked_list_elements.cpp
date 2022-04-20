Node* removeElements(Node* head, int val) {
    if (!head)
        return head;

    Node* dummyHead = new Node();
    dummyHead->link = head;
    head = dummyHead;

    while (head->link) {
        if (head->link->data == val) {
            Node* temp = head->link;
            head->link = temp->link;
            delete temp;
        }
        else {
            head = head->link;
        }
    }
    return dummyHead->link;
}
