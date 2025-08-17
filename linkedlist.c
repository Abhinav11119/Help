#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
    char value;
    struct node *next;
};
struct Stack{
    struct node *top;
};
void initstack(struct Stack *s){
    s->top= NULL;
}
void push(struct Stack *s,char value){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->value=value;
    temp->next=s->top;
    s->top = temp;
}
char pop(struct Stack *s){
    if(s->top==NULL){
        printf("Underflow\n");
        return 0;
    }
    struct node *temp = s->top;
    s->top = s->top->next;
    char value = temp->value;
    free(temp);
    return value;
}
char value(struct Stack *s){
    if(s->top==NULL){
        printf("Underflow\n");
        return 0;
    }
    return s->top->value;
}
void display(struct Stack *s){
    struct node *temp = s->top;
    if(temp==NULL){
        printf("Stack Empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%c ",temp->value);
        temp=temp->next;
    }
    printf("\n");
}
/*struct Queue{
    struct node *front;
    struct node *rear;
};
void initQueue(struct Queue *q){
    q->front = NULL;
    q->rear = NULL;
}
void enqueue(struct Queue *q,int value){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->value = value;
    if(q->front==NULL){
        q->front = temp;
        q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    
}
int dequeue(struct Queue *q){
    if(q->front == NULL){
        printf("Underflow\n");
        return 0;
    }
    struct node *temp = q->front;
    q->front=q->front->next;
    if(q->front==NULL){
        q->rear = NULL;
    }
    int value = temp->value;
    free(temp);
    return(value);
}
void displayQueue(struct Queue *q){
    struct node *temp = q->front;
    if(temp==NULL){
        printf("Queue Empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d -> ",temp->value);
        temp = temp->next;
    }
    printf("\n");
}*/
int precedence(char operato){
    int value = (operato=='-'||operato=='+')?1:(operato=='*'||operato=='/')?2:(operato=='*')?:0;
    return value;
}
int main(){
    struct Stack s1;
    initstack(&s1);
    char infix[20];
    char postfix[20];
    scanf("%s",infix);
    int i =0;
    int pl =0;
    push(&s1,'#');
    for(i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i])){
            postfix[pl]=infix[i];
            pl++;
        }
        else if(infix[i]=='('){
            push(&s1,infix[i]);
        }
        else if(precedence(infix[i])!=0){
            while(precedence(infix[i])<precedence(value(&s1))){
                postfix[pl]=pop(&s1);
                pl++;
            }
            push(&s1,infix[i]);
        }
        else if(infix[i]==')'){
            while(value(&s1)!='('){
                postfix[pl]=pop(&s1);
                pl++;
            }
            pop(&s1);
        }    
    }
    while(value(&s1)!='#'){
        postfix[pl]=pop(&s1);
        pl++;       
    }
    postfix[pl]='\0';
    printf("%s",postfix);
    return 0;
}