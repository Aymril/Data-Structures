void deleteNode(Node** head, Node* node) {
    if (!*head || !node) return;

    if (*head == node) {
        *head = node->next;
    }
    if (node->prev) {
        node->prev->next = node->next;
    }

    if (node->next) {
        node->next->prev = node->prev;
    }

    delete node;
}

void deleteNthNode(Node** head, int position) {
    if (!*head || position < 1) return;

    Node* current = *head;
    for (int i = 1; current && i <= position - 1; ++i) {
        current = current->next;
    }

    // n greater than length of list.
    if (!current) return;

    deleteNode(head, current);
}
