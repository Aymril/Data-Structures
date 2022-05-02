// double pointer used. address of the head of the list passed as arguments to the function.

void reverseRecursive(Node** head) {
    if (!*head) return;

    Node* temp = (*head)->next;
    (*head)->next = (*head)->prev;
    (*head)->prev = temp;

    if (temp) {
        *head = (*head)->prev;
        reverseRecursive(head);
    }
}

// head of the list is passed. that's why we need to return new head.
Node* reverseRecursive2(Node* head) {
    if (!head) return head;

    Node* temp = head->next;
    head->next = head->prev;
    head->prev = temp;

    if (head->prev) {
        return reverseRecursive2(head->prev);
    }
    return head;
}
