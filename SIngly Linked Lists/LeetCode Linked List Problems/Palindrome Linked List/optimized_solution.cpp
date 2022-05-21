// this version doesn't restore the original list, not restoring reverse operation.
bool isPalindrome() {
        ListNode* prev = nullptr;
        ListNode *slow = head, *fast = head;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            head->next = prev;
            prev = head;
            head = slow;
        }

        if (fast) slow = slow->next;

        while (prev and prev->val == slow->val) {
            prev = prev->next;
            slow = slow->next;
        }
        return prev == nullptr;
}

//if you want original list unchanged, this is for you
bool isPalindrome(void) {
        ListNode* prev = nullptr;
        ListNode *slow = head, *fast = head;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            head->next = prev;
            prev = head;
            head = slow;
        }

        if (fast) slow = slow->next;

        bool isPal = true;

        while (prev) {
            if (prev->val != slow->val) isPal = false;
            slow = slow->next;
            ListNode* temp = prev->next;
            prev->next = head;
            head = prev;
            prev = temp;
        }
        return isPal;
    }
