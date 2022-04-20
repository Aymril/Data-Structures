Node* reverseIterative(Node* list) {
    if (!list) return list;

    Node *prev = nullptr, *temp = list, *next;
    while (temp) {
        next = temp->link;
        temp->link = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}
