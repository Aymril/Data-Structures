Node* reverseIterative(Node* list) {
    if (!list) return list;

    Node *prev = nullptr, *next;
    while (temp) {
        next = temp->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    return prev;
}
