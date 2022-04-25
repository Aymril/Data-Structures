Node* mergeSorted2List(Node* list1, Node* list2) {
    Node* result = list1, * temp, * prev = nullptr;

    while (list2) {
        temp = list2;
        list2 = list2->link;

        while (list1 && list1->data <= temp->data) {
            prev = list1;
            list1 = list1->link;
        }

        temp->link = list1;
        if (!prev)
            result = temp;
        else
            prev->link = temp;
        list1 = temp;
    }
    return result;
}
