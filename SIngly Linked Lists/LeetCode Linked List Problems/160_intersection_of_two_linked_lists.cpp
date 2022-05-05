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


// Cozum 2: Floyd's Cycle Detection algorithm used to find head node of the cycle, if any.

Node* cycleHeadNode(Node* head) {
    Node* slow = head, * fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            while (head != slow) {
                slow = slow->next;
                head = head->next;
            }
            return head;
        }
    }
    return nullptr;
}

Node* getIntersectionNodeFloyd(Node* headA, Node* headB) {
    Node* temp = headA;
    while (headA->next) {
        headA = headA->next;
    }
    headA->next = headB;
    Node* remember = headA;

    Node* intersectionNode = cycleHeadNode(temp);
    remember->next = nullptr;
    headA = temp;
    return intersectionNode;
}

// Cozum 3: Cozum 2'nin degistirilmis/farkli dusunulmus versiyonu

Node* cycleHeadNode(Node* head) {
    Node* slow = head, * fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            while (head != slow) {
                slow = slow->next;
                head = head->next;
            }
            return head;
        }
    }
    return nullptr;
}

Node* getIntersectionNodeFloydCircular(Node* headA, Node* headB) {
    Node* originalHeadA = headA;
    while (headA->next) {
        headA = headA->next;
    }
    headA->next = originalHeadA;

    Node* hasCycle = cycleHeadNode(headB);
    headA->next = nullptr;
    return hasCycle;
}
