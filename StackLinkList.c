#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node* push(struct node*, int);
struct node* pop(struct node*);
void display(struct node*);

void main(){
	int ch, item;
	struct node *tos=NULL;
	while(1){
		printf("\n1.push\n2.pop\n3.Display\n4.exit\n\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
		case 1:printf("\nEnter element: ");
			scanf("%d",&item);
			tos=push(tos,item);
			break;
		case 2: tos=pop(tos);
			break;
		case 3: display(tos);
			break;
		case 4:exit(1);
		default: printf("\nWrong choice");
		}
	}
}

struct node* push(struct node*s, int x){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=s;
	s=temp;
	return s;
}

struct node* pop(struct node *s){
	struct node *temp;
	if(s==NULL){
		printf("\nStack overflow");
		return s;

	}
	temp=s;
	s=s->next;
	printf("\nPopped element is %d ",temp->data);
	free(temp);
	return s;
}

void display(struct node *s){
	struct node *temp;
	temp=s;
	if(temp==NULL){
		printf("\nStack is empty");
		return ;
	}
	printf("\nElements in stack are:");
	while(temp!=NULL){
		printf("\n%d",temp->data);
		temp=temp->next;
	}
}