#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX],front,rear;

void push(int x){
	if(rear==MAX-1){
		printf("Queue is full");
	}
	else{
		front=0;
		queue[++rear]=x;
	}
}

int pop(){
	if(rear==-1&&front==-1){
		printf("Queue is empty");
		return 0;
	}
	else{
		int x=queue[front];
		++front;
		return x;
	}
}

void display(){
	if(rear==-1&&front==-1){
		printf("Nothing to display Queue is empty");
	}
	else{
		for(int i=front;i<=rear;i++){
			printf("%d\n",queue[i]);
		}
	}
}

int main(){
	int ch,item;
	front=-1;rear=-1;
	while(1){
		printf("\n 1.push\n 2.pop\n 3.display\n 4.exit\n Enter your choice :");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				printf("Enter item to be pushed: ");
				scanf("%d",&item);
				push(item);
				printf("\n");
				break;
			case 2:
				item=pop();
				printf("you popped %d\n",item);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			
		}
		
	}
}
