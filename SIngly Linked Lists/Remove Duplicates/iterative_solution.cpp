Node* remove_duplicates(Node* list) {
    if (!list) return list;

    Node *temp, *head = list;
    while (list->link) {
        if (list->data == list->link->data) {
            temp = list->link;
            list->link = temp->link;
            delete temp;
        } else {
            list = list->link;
        }
    }

    return head;
}
