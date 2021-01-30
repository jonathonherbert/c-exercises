#include <stdio.h>
#include <assert.h>

struct dll_node {
  struct dll_node* prev;
  struct dll_node* next;
  int val;
};

struct dll_node create(int val) {
  struct dll_node* arr = malloc(sizeof(struct dll_node));;
  arr->next = NULL;
  arr->prev = NULL;
  arr->val = 1;
  return *arr;
}

void push(struct dll_node** head_ref, int data) {
  struct dll_node* newNode = malloc(sizeof(struct dll_node));
  newNode->next = (*head_ref);
  newNode->prev = NULL;
  newNode->val = data;

  if ((*head_ref) != NULL) (*head_ref)->prev = newNode;
  (*head_ref) = newNode;
}

struct dll_node pop(struct dll_node** head_ref) {
  struct dll_node* node_ref = *head_ref;
  while (node_ref->next != NULL) {
    node_ref = node_ref->next;
  }
  if ((node_ref->prev) != NULL) (*(node_ref->prev)).next = NULL;
  return *node_ref;
}

int get_index(struct dll_node** arr, int val) {
  struct dll_node *curr;
  int index = 0;
  curr = *arr;
  while (curr->val != val) {
    if (curr->next == NULL) return -1;
    curr = curr->next;
    index++;
  };
  return index;
}

int main()
{
  struct dll_node* arr = NULL;

  push(&arr, 1);
  push(&arr, 2);
  push(&arr, 3);

  assert(get_index(&arr, 3) == 0);
  assert(get_index(&arr, 2) == 1);
  assert(get_index(&arr, 1) == 2);
  assert(pop(&arr).val == 1);
  assert(pop(&arr).val == 2);
  assert(pop(&arr).val == 3);

  return 0;
}
