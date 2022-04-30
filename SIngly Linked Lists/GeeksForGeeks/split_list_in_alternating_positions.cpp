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
