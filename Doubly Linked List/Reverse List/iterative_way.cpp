Node* reverseIterative(Node* head) {
    Node *list = head, *prev = nullptr;
    while (list) {
        prev = list;
        Node* temp = list->prev;
        list->prev = list->next;
        list->next = temp;

        list = list->prev;
    }
    return prev;
}
