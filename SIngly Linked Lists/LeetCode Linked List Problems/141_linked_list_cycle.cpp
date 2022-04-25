// Iterative solution.

bool hasCycle(Node* list) {
    Node* slow = list, * fast = list;
    
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}


// Recursive solution.

bool cycleTestRecursive(Node* ptr1, Node* ptr2) {
    if (!ptr1 || !ptr2 || !ptr2->next)
        return false;

    if (ptr1 == ptr2)
        return true;
    return cycleTestRecursive(ptr1->next, ptr2->next->next);
}

bool hasCycleRecursive(Node* list) {
    if (!list)
        return false;
    return cycleTestRecursive(list, list->next);
}
