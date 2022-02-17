#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->data = new_data;
new_node->next = (*head_ref);
(*head_ref) = new_node;
}
void insertAfter(struct Node* prev_node, int new_data) {
if (prev_node == NULL) {
printf("the given previous node cannot be NULL");
return;
}

struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->data = new_data;
new_node->next = prev_node->next;
prev_node->next = new_node;
}

void insertAtEnd(struct Node** head_ref, int new_data) {
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
struct Node* last = *head_ref; 
new_node->data = new_data;
new_node->next = NULL;

if (*head_ref == NULL) {
*head_ref = new_node;
return;
}

while (last->next != NULL) last = last->next;
last->next = new_node;
return;
}

void deleteNode(struct Node** head_ref, int key) {
struct Node *temp = *head_ref, *prev;

if (temp != NULL && temp->data == key) {
*head_ref = temp->next;
free(temp);
return;
}
while (temp != NULL && temp->data != key) {
prev = temp;
temp = temp->next;
}
if (temp == NULL) return;
prev->next = temp->next;

free(temp);
}


void printList(struct Node* node) {
while (node != NULL) {
printf(" %d ", node->data);
node = node->next;
}
}

int main() {
	  struct Node* head = NULL;

	  insertAtEnd(&head, 10);
	  insertAtBeginning(&head, 22);
	  insertAtBeginning(&head,45);
	  insertAtEnd(&head,64);
	  insertAfter(head->next, 19);

	  printf("Linked list is : ");
	  printList(head);

	  printf("\nAfter deleting an element: ");
	  deleteNode(&head, 3);
	  printList(head);
}
