
   
Node* middleNode(Node* head) {
    Node* slow = head, * fast = head;

    while (fast && fast->link) {
        slow = slow->link;
        fast = fast->link->link;
    }

    return slow;
}

void isPalindromeTest(Node** head, Node* middle, bool* isTrue) {
    

    if (middle->link)
        isPalindromeTest(head, middle->link, isTrue);

    if (*isTrue == false)
        return;

    if ((*head)->data != middle->data)
        *isTrue = false;     
    else {
        (*head) = (*head)->link;
        *isTrue = true;
    }
}

bool isPalindrome(Node* head) {
    bool result = true;
    isPalindromeTest(&head, middleNode(head), &result);
    return result;
}
