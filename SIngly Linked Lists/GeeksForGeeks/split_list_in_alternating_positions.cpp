/// iterative solution

void alternatingSplitList(ListNode* head, ListNode** a1, ListNode** b1) 
{
    while(head) {
        *a1 = head;
        a1 = &(*a1)->next;
        head = head->next;
        if(head){
            *b1 = head;
            b1 = &(*b1)->next;
            head = head->next;
        }
    }
    *a1 = *b1 = nullptr;
}


// weird but nontheless, recursive solution.
void alternatingSplitListRecursive(ListNode* head, ListNode** a1,
                                   ListNode** b1) {
    if (!head) {
        *a1 = nullptr;
        *b1 = nullptr;
        return;
    }

    *a1 = head;

    if (head->next) {
        *b1 = head->next;
        return alternatingSplitListRecursive(head->next->next, &(*a1)->next,
                                             &(*b1)->next);
    }
    alternatingSplitListRecursive(head->next, &(*a1)->next, b1);
}
