Node* middleNode(Node* head) {
    Node* slow = head, * fast = head;

    while (fast && fast->link) {
        slow = slow->link;
        fast = fast->link->link;
    }

    return slow;
}
