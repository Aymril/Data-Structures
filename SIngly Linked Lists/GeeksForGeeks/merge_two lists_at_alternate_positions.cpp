Node* mergeList(Node* p, Node* q)
{
    Node* result = p, * temp;
    while (p && q) {
        if (!p->next) {
            p->next = q;
            break;
        }
            
        temp = q->next;
        q->next = p->next;
        p->next = q;
        q = temp;
        
        p = p->next->next;
    }
    return result;
}
