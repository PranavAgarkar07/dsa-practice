#include <stdio.h>
#include <stdlib.h>

struct node
{
	int d;
	struct node *next;
};

struct node* enq(struct node*,int);
struct node* deq(struct node*);
void display(struct node *);

void main(){
	int ch, item;
	struct node *f,*r;
	f=r=NULL;
	while(1){
		printf("\n1.Enq\n2.Deq\n3.Display\n4.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
		case 1:printf("\nEnter element:");
			scanf("%d",&item);
			r=enq(r,item);
			if(f==NULL) f=r;
			break;
		case 2:f=deq(f);
			if(f==NULL)r=NULL;
			break;
		case 3:display(f);
			break;
		case 4:exit(1);
		default:printf("\nWrong choice");
		}
	}
}

struct node* enq(struct node* r,int x){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->d=x;
	temp->next=NULL;
	if(r!=NULL)r->next=temp;
	r=temp;
	return r;
}

struct node* deq(struct node *f){
	struct node *temp;
	if(f==NULL){
		printf("\nQueue underflow");
		return f;
	}
	temp=f;
	f=f->next;
	printf("\nDeleted element is %d ",temp->d);
	free(temp);
	return f;
}

void display(struct node *f){
	struct node *p;
	if(f==NULL){
		printf("\nQueue is Empty");
		return;
	}
	printf("\nElements in queue are: ");
	p=f;

	while(p!=NULL){
		printf("\n%d",p->d);
		p=p->next;
	}
}