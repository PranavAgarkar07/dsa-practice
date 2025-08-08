#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};

void insert(int item){

	struct node *i=(struct node*)malloc(sizeof(struct node));
	i->data=item;
	i->next=i+1;
	(i+1)->next=NULL;
	i++;

}

void display(struct node *p){
	while(p->next!=NULL){
		printf("%d",p->data);
	}
}

void main()
{
	// struct node *n1=(struct node*)malloc(sizeof(struct node));
	// struct node *n2=(struct node*)malloc(sizeof(struct node));
	// n1->data=1;
	// n1->next=n2;
	// n2->data=2;
	// n2->next=NULL;
	// printf("%d\n", n1->data);

	int ch,item,i;
	struct node j;
	while(1){
		printf("\nEnter your choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				printf("\nEnter item to be inserted into the list: ");
				scanf("%d",&item);

				insert(item);
				break;
			case 2:
				display(j);
				break;
		}
	}
}