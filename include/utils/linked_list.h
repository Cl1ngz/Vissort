#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data);
void append_node(Node** head, int data);
void print_list(Node* head);
void free_list(Node* head);

#endif // LINKED_LIST_H
