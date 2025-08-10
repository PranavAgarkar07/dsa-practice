#include <stdio.h>
#include <stdlib.h>
#define MAX 5


struct Queue{
	int queue[MAX],front,rear;
};

int isFull(struct Queue *s){
	if(s->front==((s->rear)+1)%MAX){
		return 1;
	}
	else{
		return 0;
	}
}

int isEmpty(struct Queue *s){
	if(s->front==-1){
		return 1;
	}
	else{
		return 0;
	}
}

void enq(struct Queue *s,int x){
	if(isFull(s)){
		printf("Queue is full");
	}
	else{
		s->front=0;
		s->queue[++s->rear]=x;
	}
}

int deq(struct Queue *s){
	if(isEmpty(s)){
		printf("Queue is empty");
		return 0;
	}
	else{
		int x=s->queue[s->front];
		++s->front;
		return x;
	}
}



void display(struct Queue *s){
	if(isEmpty(s)){
		printf("Nothing to display Queue is empty");
	}
	else{
		for(int i=s->front;i<=s->rear;i++){
			printf("%d\n",s->queue[i]);
		}
	}
}

int main(){
	int ch,item;
	struct Queue s;
	s.front=-1;s.rear=-1;
	while(1){
		printf("\n 1.push\n 2.pop\n 3.display\n 4.exit\n Enter your choice :");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				printf("Enter item to be pushed: ");
				scanf("%d",&item);
				enq(&s,item);
				printf("\n");
				break;
			case 2:
				item=deq(&s);
				printf("you popped %d\n",item);
				break;
			case 3:
				display(&s);
				break;
			case 4:
				exit(1);
			
		}
		
	}
}
