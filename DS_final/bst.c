#include <stdio.h>
#include <stdlib.h>


struct node {
int info;
struct node *l;
struct node *r;
};


struct node *newNode(int data) {
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp->info = data;
temp->l = temp->r = NULL;
return temp;
}

void inorder(struct node* root) {
if (root == NULL) return;
inorder(root->l);
printf("%d ", root->info);
inorder(root->r);
}

void preorder(struct node* root) { 
if (root == NULL) return;
printf("%d ", root->info);
preorder(root->l);
preorder(root->r);
}

void postorder(struct node* root) {
if (root == NULL) return;
postorder(root->l);
postorder(root->r);
printf("%d ", root->info);
}

struct node *insert(struct node *node, int info) {
if (node == NULL) return newNode(info);
if (info < node->info)
node->l = insert(node->l, info);
else
node->r = insert(node->r, info);
return node;
}

struct node *minValueNode(struct node *node) {
struct node *cur = node;
while (cur && cur->l != NULL)
cur = cur->l;
return cur;
}

struct node *deleteNode(struct node *root, int info) {
if (root == NULL) return root;
	if (info < root->info)
	root->l = deleteNode(root->l, info);
	else if (info > root->info)
	root->r = deleteNode(root->r, info);

else {
	if (root->l == NULL) {
	struct node *temp = root->r;
	free(root);
	return temp;
	}
	else if (root->r == NULL) {
	struct node *temp = root->l;
	free(root);
	return temp;
}
    struct node *temp = minValueNode(root->r);
    root->info = temp->info;
    root->r = deleteNode(root->r, temp->info);
  }
return root;
}

int main() {
  struct node *root = NULL;
  root = insert(root, 10);
  root = insert(root, 15);
  root = insert(root, 20);
  root = insert(root, 25);
  root = insert(root, 30);
  root = insert(root, 35);
  root = insert(root, 40);
  root = insert(root, 45);

  printf("Inorder traversal of BST is : ");
  inorder(root);

  printf("\nAfter deleting 25\n");
  root = deleteNode(root, 25);
  printf("Inorder traversal of BST after deletion is:\n ");
  inorder(root);
printf("\n");
 printf("Preorder traversal of BST after deletion is:\n ");
  preorder(root);
printf("\n");
 printf("Postorder traversal of BST after deletion is:\n ");
postorder(root);
}
