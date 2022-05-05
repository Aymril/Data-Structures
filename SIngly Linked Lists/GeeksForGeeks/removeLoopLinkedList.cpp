void removeLoop(Node* head) {
    Node** result = &head;
    Node* fast = *result;
    while (*result && fast && fast->next) {
        result = &(*result)->next;
        fast = fast->next->next;
        if (*result == fast) {
            while(head != *result) {
                head = head->next;
                result = &(*result)->next;
            }
            *result = nullptr;
            return;
        }
    }
}
