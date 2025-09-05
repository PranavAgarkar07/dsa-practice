#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* head;

struct node* ins_beg(struct node*,int);
void display(struct node*);

void main(){
	int ch,item;
	struct node *head=NULL;

	while(1){
		printf("\n1.Insert Item at the begining:\n2.Display Items\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
		case 1:
			printf("Enter item: ");
			scanf("%d",&item);
			head=ins_beg(head,item);
			break;
		case 2:
			display(head);
			break;
		}
	}
}

void display(struct node* head){
	if(head==NULL){
		printf("The list is empty");
	}
	struct node* s;
	s=head;
	while(s!=NULL){
		printf("|%d|=>",s->data);
		s=s->next;
	}
}

struct node* ins_beg(struct node* head,int item){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	if(head==NULL){
		temp->next=NULL;
		return temp;
	}else{
		temp->next=head;
		return temp;
	}
}
