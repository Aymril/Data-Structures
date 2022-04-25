/*
bu cozumu daha cok begendim. recursion kullanimi sevdim bu cozumde.
*/

Node* mergeSorted2ListRecursive(Node* l1, Node* l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->data < l2->data) {
        l1->link = mergeSorted2ListRecursive(l1->link, l2);
        return l1;
    }
        
    else {
        l2->link = mergeSorted2ListRecursive(l1, l2->link);
        return l2;
    }
}



// 2. way to write recursively. simple modification done.

Node* mergeSorted2ListRecursive(Node* l1, Node* l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    Node* result = nullptr;
    if (l1->data < l2->data) {
        result = l1;
        l1->link = mergeSorted2ListRecursive(l1->link, l2);
    }
        
    else {
        result = l2;
        l2->link = mergeSorted2ListRecursive(l1, l2->link);
    }
  return result;
}
