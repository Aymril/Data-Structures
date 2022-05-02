// print forward

void print_list_forward(Node* head) {
    while (head) {
        std::cout << head->data << ' ';
        head = head->next;
    }
    std::cout << std::endl;
}

// print backward

void print_list_backward(Node* head) {
    if (!head) return;

    while (head->next) head = head->next;

    while (head) {
        std::cout << head->data << ' ';
        head = head->prev;
    }
    std::cout << std::endl;
}
