# Structure of node of a linked list

Linked list consists of nodes, each having 2 parts:

1. Item/Data part. Data is stored here.
2. A pointer to Node, storing the address of the next node (if any); otherwise, `nullptr`.

Linked list node, in my case, is defined to be:

```
struct Node {
  int data;
  Node* link;
}  
```
