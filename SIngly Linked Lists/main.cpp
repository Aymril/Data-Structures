#include <iostream>

struct Node {
    int data;
    Node* link;
};

void print_list(const Node* list)
// const pointers are extremely important. first time I used them.
// so beautiful.
{
    if (!list) return;

    while (list) {
        std::cout << list->data << ' ';
        list = list->link;
    }
    std::cout << std::endl;
}

Node* create_node(int number) {
    Node* temp = new Node();
    if (!temp) {
        return nullptr;
    }
    temp->data = number;
    temp->link = nullptr;
    return temp;
}

Node* insert_top(Node* list, int number) {
    Node* temp = create_node(number);
    // some checking.
    temp->link = list;
    return temp;
}

Node* insert_end(Node* list, int number) {
    Node* temp = create_node(number);
    Node* head = list;
    // some checking.
    if (!list) {
        return (list = temp);
    }

    while (list->link) list = list->link;
    list->link = temp;
    return head;
}

Node* insert_at_n(Node* list, int number, int position) {
    // position begins from 1.
    Node* temp = create_node(number);
    if (position == 1) {
        temp->link = list;
        return list = temp;
    }

    Node* prev = list;
    for (int i = 1; i < position - 1; ++i) {
        prev = prev->link;
    }

    temp->link = prev->link;
    prev->link = temp;
    return list;
}

Node* delete_at_n(Node* list, int position) {
    // assume valid position.
    if (!list) return nullptr;

    Node* prev = list;
    if (position == 1) {
        list = list->link;
        delete prev;
        return list;
    }

    for (int i = 1; i < position - 1; ++i) prev = prev->link;
    Node* temp = prev->link;
    prev->link = temp->link;
    delete temp;
    return list;
}

Node* delete_key(Node* list, int key) {
    // this function deletes the first node with data value equals key
    // (if such node exists).

    if (!list) return nullptr;

    Node *temp = list, *prev = nullptr;
    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->link;
    }

    if (temp) {
        if (!prev)
            list = list->link;
        else
            prev->link = temp->link;
        delete temp;
    }
    return list;
}

void printListForwardRecursion(Node* list) {
    if (!list) return;

    std::cout << list->data << ' ';
    printListForwardRecursion(list->link);
}

void printListBackwardRecursion(Node* list) {
    if (!list) return;

    printListBackwardRecursion(list->link);
    std::cout << list->data << ' ';
}

int main(void) {
    Node* N = nullptr;
    N = insert_at_n(N, 8, 1);
    N = insert_at_n(N, 5, 1);
    N = insert_at_n(N, 3, 1);
    N = insert_at_n(N, 2, 1);
    N = insert_at_n(N, 1, 1);
    N = insert_at_n(N, 1, 1);
    N = insert_at_n(N, 0, 1);
    print_list(N);

}
