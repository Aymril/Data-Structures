// guzel dusunulmus bir cozum. begendim.

Node* getIntersectionNode(Node* headA, Node* headB) {
    if (headA && headB == nullptr)
        return nullptr;

    Node* a_ptr = headA;
    Node* b_ptr = headB;

    while (a_ptr != b_ptr) {
        if (!a_ptr)
            a_ptr = headB;
        else
            a_ptr = a_ptr->next;

        if (!b_ptr)
            b_ptr = headA;
        else
            b_ptr = b_ptr->next;
    }
    return a_ptr;
}
