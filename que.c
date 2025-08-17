#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Queue
{
    int rear,size,front,count,tcount;
    struct Customer *QueueArr;
};
struct Customer{
    char name[20];
    int id;
};
void init(struct Queue *q,int size){
    q->tcount=0;
    q->count = 0;
    q->front=0;
    q->size = size;
    q->rear=-1;
    q->QueueArr=(struct Customer*)malloc(size*sizeof(struct Customer));
}
void enque(struct Queue *q){
    char name[20];
    printf("Enter Customer name:");
    scanf("%s",name);
    if(q->tcount==q->size){
        printf("Overflow\n");
        return;
    }
    q->tcount++;
    q->rear=(q->rear+1)%(q->size);
    q->count++;
    q->QueueArr[q->rear].id =q->count;
    strcpy(q->QueueArr[q->rear].name,name);
}
struct Customer dequeue(struct Queue *q){
    struct Customer temp;
    if(q->tcount==0){
        //printf("Underflow\n");
        temp.name[0]='\0';
        temp.id=-1;
        return temp;
    }
    temp= q->QueueArr[q->front];
    q->front=(q->front+1)%(q->size);
    q->tcount--;
    return temp;
}
void display(struct Queue *q){
    for(int i=q->front;i!=q->rear;i=(i+1)%(q->size)){
        printf("Customer Name: %s Id: %d -> ",q->QueueArr[i].name,q->QueueArr[i].id);
    }
    printf("Customer Name: %s Id: %d -> ",q->QueueArr[q->rear].name,q->QueueArr[q->rear].id);
    printf("\n");
}
int main(){
    struct Queue q1;
    init(&q1,10);
    int input;
    while(1){
        printf("Enter 1 to Enqueue a customer 2 to display the Queue and 3 to Dequeue: ");
        scanf("%d",&input);
        switch(input){
            case 1:
                enque(&q1);
                break;
            case 2:
                display(&q1);
                break;
            case 3:
                struct Customer de = dequeue(&q1);
                if(de.name[0]=='\0'){
                    printf("Queue empty\n");
                }
                else{   
                     printf("%s Has finished their appointment\n",de.name);
                    }
                break;
    }}

}