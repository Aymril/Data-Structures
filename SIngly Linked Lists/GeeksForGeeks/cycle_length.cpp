int cycleLength(Node* node) {
    int length = 1;
    for(Node* temp = node; temp->next != node; ++length, temp = temp->next);
    return length;
}

int countNodesinLoop(struct Node *head)
{
    Node* walker, *runner;
    walker = runner = head;
    while(runner and runner->next) {
        walker = walker->next;
        runner = runner->next->next;
        if(runner == walker) {
            return cycleLength(runner);
        }
    }
    return 0;
}
