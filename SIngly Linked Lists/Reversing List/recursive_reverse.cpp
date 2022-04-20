void RecursiveReverse(Node** list) {
    if (!*list) return;
    Node* first = *list;
    Node* rest = first->link;

    if (!rest) {
        return;
    }

    RecursiveReverse(&rest);
    first->link->link = first;
    first->link = nullptr;
    *list = rest;
}
