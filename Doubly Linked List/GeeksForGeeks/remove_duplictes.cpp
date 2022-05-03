void removeDuplicates(Node** head) {
    Node* list = *head;
    while (list && list->next) {
        if (list->data == list->next->data) {
            while (list && list->next && list->data == list->next->data) {
                Node* temp = list->next;
                list->next = list->next->next;
                if (list->next) {
                    list->next->prev = list;
                }
                delete temp;
            }
        }
        list = list->next;
    }
}

// recursive solution
void removeDuplicatesRecursive(Node** head) {
    if (!*head || !(*head)->next) return;

    if ((*head)->data == (*head)->next->data) {
        Node* temp = (*head)->next;
        (*head)->next = (*head)->next->next;
        if ((*head)->next) {
            (*head)->next->prev = *head;
        }
        delete temp;
        removeDuplicatesRecursive(head);
    } else {
        removeDuplicatesRecursive(&(*head)->next);
    }
}
