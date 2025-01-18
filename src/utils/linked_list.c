#include "../../include/utils/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// Create a new node
Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (!new_node) {
    perror("Memory allocation error");
    return NULL;
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Append a node to the end of the list
void append_node(Node **head, int data) {
  Node *new_node = create_node(data);
  if (!new_node)
    return;

  if (*head == NULL) {
    *head = new_node;
  } else {
    Node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

// Print the linked list
void print_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

// Free the linked list
void free_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    free(temp);
  }
}
