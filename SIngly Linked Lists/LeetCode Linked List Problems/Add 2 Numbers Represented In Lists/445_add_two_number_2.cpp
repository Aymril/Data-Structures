// Cozum 1: lists are reversed, then addition done. Better way may be to add numbers without reversing lists. It'll be in the Cozum 2 part.

void reverseList(Node** list) {
    if (!list) return;

    Node* first = *list;
    Node* rest = first->next;

    if (!rest) return;

    reverseList(&rest);

    first->next->next = first;
    first->next = nullptr;

    *list = rest;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    reverseList(&l1);
    reverseList(&l2);

    Node* head = nullptr;
    Node** result = &head;
    int sum = 0;
    while (l1 or l2 or sum) {
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }

        *result = create_node(sum % 10);
        sum = sum > 9 ? 1 : 0;

        result = &(*result)->next;
    }
    reverseList(&head);
    return head;
}


// Cozum 2: 
int listSize(Node* head) {
    int count = 0;
    while (head) {
        ++count;
        head = head->next;
    }
    return count;
}

Node* additionAlgorithm(Node* l1, Node* l2, int* carry) {
    Node* head = create_node(-1);

    if (l1->next && l2->next) {
        head->next = additionAlgorithm(l1->next, l2->next, carry);
    }

    int sum = l1->data + l2->data + *carry;
    head->data = sum % 10;
    *carry = sum > 9 ? 1 : 0;
    return head;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    int l1_length = listSize(l1);
    int l2_length = listSize(l2);

    if (l1_length > l2_length) {
        for (int i = 1; i <= l1_length - l2_length; ++i) {
            Node* node = create_node(0);
            node->next = l2;
            l2 = node;
        }
    }
    else if (l1_length < l2_length) {
        for (int i = 1; i <= l2_length - l1_length; ++i) {
            Node* node = create_node(0);
            node->next = l1;
            l1 = node;
        }
    }

    int carry = 0;
    Node* dummy = create_node(-1);
    dummy->next = additionAlgorithm(l1, l2, &carry);
    
    if (carry) {
        Node* node = create_node(carry);
        node->next = dummy->next;
        dummy->next = node;
    }
    return dummy->next;
}


// Cozum 2, Iyilestirme 1: adding zeros to top (padding) can be done without using lengths' of the lists. this way, code will be much shorter.
Node* additionAlgorithm(Node* l1, Node* l2, int* carry) {
    Node* head = create_node(-1);

    if (l1->next && l2->next) {
        head->next = additionAlgorithm(l1->next, l2->next, carry);
    }

    int sum = l1->data + l2->data + *carry;
    head->data = sum % 10;
    *carry = sum > 9 ? 1 : 0;
    return head;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* ptr1 = l1, * ptr2 = l2;
    while (ptr1 or ptr2) {
        if (!ptr1) {
            Node* node = create_node(0);
            node->next = l1;
            l1 = node;

            ptr2 = ptr2->next;
        }
        else if (!ptr2) {
            Node* node = create_node(0);
            node->next = l2;
            l2 = node;

            ptr1 = ptr1->next;
        }
        else {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    int carry = 0;
    Node* dummy = create_node(-1);
    dummy->next = additionAlgorithm(l1, l2, &carry);

    if (carry) {
        Node* node = create_node(carry);
        node->next = dummy->next;
        dummy->next = node;
    }

    return dummy->next;
}

// leetcode'da gordum bu cozumu, inanilmaz hosuma gitti. Probleme cok baska bir yonden bakilmis.
// No recursion/stack/reversing.

int length_list(Node* head) {
    int count = 0;
    for (; head; head = head->next, ++count);
    return count;
}

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

Node* addTwoNumbersNoRecursionStackReverse(Node* l1, Node* l2) {
    int l1_length = length_list(l1);
    int l2_length = length_list(l2);

    if (l1_length < l2_length) {
        swap(l1_length, l2_length);
        swap(l1, l2);
    }

    Node* head = create_node(0);
    Node** result = &head, * frontier = head;

    for (int i = l1_length - l2_length; i > 0; --i, l1 = l1->next) {
        (*result)->next = create_node(l1->data);
        result = &(*result)->next;

        if ((*result)->data < 9)
            frontier = *result;
    }

    for (; l1; l1 = l1->next, l2 = l2->next) {
        (*result)->next = create_node(l1->data + l2->data);
        result = &(*result)->next;
        if((*result)->data < 9) {
            frontier = *result;
        }
        else if ((*result)->data > 9) {
            while (frontier != *result) {
                frontier->data += 1;
                if (frontier->data == 10)
                    frontier->data = 0;
                frontier = frontier->next;
            }
            frontier->data -= 10;
        }
    }

    return (head->data == 0) ? head->next : head;
}
