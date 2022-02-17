#include <stdio.h>
#include <stdlib.h>

struct Node {
int info;
struct Node* r;
struct Node* l;
};

void insertFront(struct Node** head, int info) {
	  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	  newNode->info = info;
	  newNode->r = (*head);
	  newNode->l = NULL;

	  if ((*head) != NULL)
	    (*head)->l = newNode;

	  (*head) = newNode;
}

void insertAfter(struct Node* lptr, int info) {
	  if (lptr == NULL) {
	    printf("previous node cannot be null");
	    return;
	  }

	  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	  newNode->info = info;
	  newNode->r = lptr->r;
	  lptr->r = newNode;
	  newNode->l = lptr;

	  if (newNode->r != NULL)
	    newNode->r->l = newNode;
}

void insertEnd(struct Node** head, int info) {
	  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	  newNode->info = info;
	  newNode->r = NULL;

	  struct Node* temp = *head;
	  if (*head == NULL) {
	    newNode->l = NULL;
	    *head = newNode;
	    return;
	  }

	  while (temp->r != NULL)
	    temp = temp->r;
	  temp->r = newNode;
	  newNode->l = temp;
}

void deleteNode(struct Node** head, struct Node* dlt) {
	  if (*head == NULL || dlt == NULL)
	    return;
	  if (*head == dlt)
	    *head = dlt->r;
	  if (dlt->r != NULL)
	    dlt->r->l = dlt->l;
	  if (dlt->l != NULL)
	    dlt->l->r = dlt->r;
	  free(dlt);
}

void display(struct Node* node) {
	  struct Node* last;

	  while (node != NULL) {
	    printf("%d ", node->info);
	    last = node;
	    node = node->r;
	  }
	  if (node == NULL)
	    printf("NULL\n");
}

int main() {
struct Node* head = NULL;
int end,front,after,after_value;
printf("enter value to be added at the end\n");
scanf("%d ",&end);
insertEnd(&head, end);
printf("enter value to be added at the front\n");
scanf("%d ",&front);
insertFront(&head, front);
printf("enter value to be added at the front\n");
scanf("%d ",&front);
insertFront(&head, front);
printf("enter value to be added at the end\n");
scanf("%d ",&end);
insertEnd(&head, end);
printf("enter value to be added after previous\n");
scanf("%d ",&after);
insertAfter(head,after);
printf("enter value to be added after second node\n");
scanf("%d ",&after_value);
insertAfter(head->r, after_value);
display(head);
deleteNode(&head, head->r->r->r->r->r);

display(head);
}
