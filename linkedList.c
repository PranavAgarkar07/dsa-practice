#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};

void main()
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->data=1;
	n->next=NULL;
	printf("%d\n", n->data);
}