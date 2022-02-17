#include <stdio.h>
#include <stdlib.h>


//Circular linkedlist operations.
struct Node {
int info;
struct Node* link;
};

int info,item,key;
struct Node* insert(struct Node* last, int info) {
if (last != NULL) return last;
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
printf("Enter node value\n");
scanf("%d ",&info);
newNode->info = info;
last = newNode;
last->link = last;

return last;
}
struct Node* insertFront(struct Node* last, int info) {
if (last == NULL) return insert(last, info);
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->info = info;
newNode->link = last->link;
last->link = newNode;

return last;
}

struct Node* insertEnd(struct Node* last, int info) {
if (last == NULL) return insert(last, info);
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
printf("Enter node value at end\n");
scanf("%d ",&info);
newNode->info = info;
newNode->link = last->link;
last->link = newNode;
last = newNode;

return last;
}


struct Node* insertAfter(struct Node* last, int info, int item) {
if (last == NULL) return NULL;

struct Node *newNode, *p;

p = last->link;
do {
	if (p->info == item) {
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->info = info;
	newNode->link = p->link;
	p->link = newNode;
	if (p == last) last = newNode;
	return last;
	}

p = p->link;
} while (p != last->link);

printf("\nThe given node is not present in the list");
return last;
}


void deleteNode(struct Node** last, int key) {
if (*last == NULL) return;
if ((*last)->info == key && (*last)->link == *last) {
free(*last);
*last = NULL;
return;
}
struct Node *temp = *last, *d;
if ((*last)->info == key) {
while (temp->link != *last) temp = temp->link;
temp->link = (*last)->link;
free(*last);
*last = temp->link;
}
while (temp->link != *last && temp->link->info != key) {
temp = temp->link;
}
if (temp->link->info == key) {
d = temp->link;
temp->link = d->link;
free(d);
}
}

void traverse(struct Node* last) {
struct Node* p;

if (last == NULL) {
printf("The list is empty");
return;
}

p = last->link;

do {
printf("%d ", p->info);
p = p->link;
} while (p != last->link);
}

int main() {
struct Node* node = NULL;
	int dlt,front,after,i;
	node = insert(node, info);
	node = insertEnd(node, info);
	printf("Enter node value at front\n");
	scanf("%d ",&front);
	node = insertFront(node, front);
	printf("Enter node value after which you want to add\n");
	scanf("%d ",&after);
	printf("Enter value you want to add\n");
	scanf("%d ",&i);
	node = insertAfter(node,after,i);
	printf("Output after inserting in the beginning,at end,infront ,and after \n");
	traverse(node);
	printf("\n");
	deleteNode(&node,i);
	printf("Output after deleting node %d \n",i);
	traverse(node);
	printf("\n");

return 0;
}
