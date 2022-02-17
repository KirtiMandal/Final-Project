#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node{
struct node* lptr;
char info;
struct node* rptr;
}node;

struct node *tree(int);
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);

void main(){
node *a ,*b ,*c ,*d ,*e ,*f ,*g ,*t;
a=(struct node*)malloc(sizeof(struct node));
b=(struct node*)malloc(sizeof(struct node));
c=(struct node*)malloc(sizeof(struct node));
d=(struct node*)malloc(sizeof(struct node));
e=(struct node*)malloc(sizeof(struct node));
f=(struct node*)malloc(sizeof(struct node));
g=(node*)malloc(sizeof(struct node));
t=a;
a->info='A';
a->lptr=b;
a->rptr=d;

b->info='B';
b->lptr=c;
b->rptr=NULL;

c->info='C';
c->lptr=NULL;
c->rptr=NULL;

d->info='D';
d->lptr=e;
d->rptr=f;

e->info='E';
e->lptr=NULL;
e->rptr=NULL;

f->info='F';
f->lptr=NULL;
f->rptr=NULL;

g->info='G';
g->lptr=NULL;
g->rptr=NULL;

printf("preorder is \n");
preorder(t);
printf("\ninorder is \n");
inorder(t);
printf("\npostorder is \n");
postorder(t);
}

void preorder(node*t){
	if (t==NULL)
		printf("Empty");
	else{
		printf("%c ",t->info);
		if(t->lptr!=NULL){
		preorder(t->lptr);
		}
		if (t->rptr!=NULL){
		preorder(t->rptr);
		}
	}
}

void inorder(node*t){
	if (t==NULL)
		printf("Empty");
	else{
		if(t->lptr!=NULL){
		inorder(t->lptr);
		}
		printf("%c ",t->info);
		if (t->rptr!=NULL){
		inorder(t->rptr);
		}
	}
}

void postorder(node*t){
	if (t==NULL)
		printf("Empty");
	else{
		if(t->lptr!=NULL){
		postorder(t->lptr);
		}
		if (t->rptr!=NULL){
		postorder(t->rptr);
		}
	}
	printf("%c ",t->info);
}


