#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* head=NULL;

void insertAtEND(int item){

	struct node* newNode=(struct node*)malloc(sizeof(struct node));

	if(newNode==NULL){
		printf("insertion of node failed dueto Memory constrainsts");
		return ;
	}

	newNode->data=item;
	newNode->next=NULL;

	if(head==NULL){
		head=newNode;
	}else{
		struct node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}

	printf("Inserted %d ",item);

}

void insertAfter(struct node* loc,int item){
	struct node* newNode=(struct node*)malloc(sizeof(struct node));

	if(newNode==NULL){
		printf("insertion of node failed dueto Memory constrainsts");
		return ;
	}

	newNode->data=item;
	newNode->next=loc->next;

	loc->link=newNode

}

void display(){
	struct node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void main()
{
	int ch,item;
	while(1){
		printf("\n1.Insert at end\n4.Insert After a given node\n3.Display\n4.exit\nEnter your choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				printf("\nEnter item to be inserted into the list: ");
				scanf("%d",&item);
				insertAtEND(item);
				break;
			case 2:
				printf("\nEnter item to be inserted into the list: ");
				scanf("%d",&item);
				insertAtEND(item);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("enter a valid option");
		}
	}
}
