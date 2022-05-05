Okuyucunun dikkatine. C programlama dilinin yaraticilarin Ken Thompson; "When in doubt, use brute force" demistir. 
o yuzden, ilk olarak problemi cozmeye bakin. daha sonra optimize etmeye calisirsaniz daha verimli ve kolay olur sizin icin. 
ilk olarak elinizde bir sonuc olsun, olsun ki size bir fikir versin problem ve cozumu hakkinda.

Bu problemi ilk olarak, tabii ki aklima gelen ilk yoldu, brute force kullanarak cozdum. sonra baska cozumlere baktim ve kendi yazdigim kodla karsilastirdim, boyle 
boyle yaparak kodu iyilestirdim. ve ayni zamanda en guzel cozumu benimsemeye ve icsellestirmeye basladim. bu surec icinde bazi teknikler de ogrendim.



// Cozum 1
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* result = l1, * l1_prev;
    int carry = 0, placeholder;
    while (l1 && l2) {
        l1_prev = l1;
        placeholder = l1->data + l2->data;
        l1->data = (placeholder + carry) % 10;
        carry = (placeholder + carry) / 10;
        l1 = l1->next;
        l2 = l2->next;
    }


    if (l1 == nullptr && l2 == nullptr) {
        if (carry) {
            l1_prev->next = create_node(carry);
        }
    }

    else if (!l1) {
        Node* temp = l2, * l2_prev = nullptr;
        while (l2) {
            l2_prev = l2;
            placeholder = l2->data;
            l2->data = (placeholder + carry) % 10;
            carry = (placeholder + carry) / 10;
            l2 = l2->next;
        }

        if (carry) {
            l2_prev->next = create_node(carry);
        }
        l1_prev->next = temp;
    }

    else {
        l1_prev = nullptr;
        while (l1) {
            l1_prev = l1;
            placeholder = l1->data;
            l1->data = (placeholder + carry) % 10;
            carry = (placeholder + carry) / 10;
            l1 = l1->next;
        }

        if (carry) {
            l1_prev->next = create_node(carry);
        }
    }
    return result;
}


// Cozum 2:
Node* addTwoNumbersConcise(Node* l1, Node* l2) {
    Node* result = create_node(-1);
    Node* head = result;
    int carry = 0, first, second, sum;
    while (l1 or l2 or carry) {
        first = second = 0;
        if (l1) {
            first = l1->data;
            l1 = l1->next;
        }
        if (l2) {
            second = l2->data;
            l2 = l2->next;
        }

        sum = first + second + carry;

        result->next = create_node(sum % 10);
        carry = sum / 10;
        result = result->next;
    }
    return head->next;
}

// Cozum 2, Iyilestirme 1:
Node* addTwoNumbersConcise2(Node* l1, Node* l2) {
    Node* result = create_node(-1);
    Node* head = result;
    int sum = 0;
    while (l1 or l2 or sum > 0) {
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }
        
        result->next = create_node(sum % 10);
        
        sum = (sum > 9) ? 1 : 0;

        result = result->next;
    }
    return head->next;
}
