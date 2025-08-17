#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int *StackArr;
    int top;
    int max;
    char id;
};
void innit(struct Stack *S,int size,char id){
    S->max= size;
    S->StackArr= (int*)malloc(size*sizeof(int));
    S->top = -1;
    S->id = id;
}
void push(struct Stack *S, int value){
    if(S->top==(S->max)-1){
        printf("Overflow\n");
        return;
    }
    S->top++;
    S->StackArr[S->top]=value;
}
int pop(struct Stack *S){
    if(S->top==-1){
        printf("Underflow\n");
        return -1;
    }
    int temp = S->StackArr[S->top];
    S->top--;
    return temp;
}
int value(struct Stack *S){
    if(S->top==-1){
        return -1;
    }
    return S->StackArr[S->top];
}
void destroy(struct Stack *S){
    free(S->StackArr);
}
void moveDisk(struct Stack *from, struct Stack *to,int *count){
    int disk = pop(from);
    push(to,disk);
    (*count)++;
    printf("Moved disk %d from Rod %c to Rod %c\n",disk,from->id,to->id);
}
void hanoi(int size,struct Stack *from, struct Stack *to,struct Stack *mid,int *count){
    if(size<0){
        printf("Error");
        return;
    }
    if(size==1){
        moveDisk(from,to,count);
        return;
        
    }
    hanoi(size-1,from,mid,to,count);
    moveDisk(from,to,count);
    hanoi(size-1,mid,to,from,count);
}
int main(){
    int count = 0;
    struct Stack A;
    struct Stack B;
    struct Stack C;
    int size;
    printf("Enter the size of rod you want to simulate\n");
    scanf("%d",&size);
    innit(&A,size,'A');
    innit(&B,size,'B');
    innit(&C,size,'C');
    for(int i=size;i>0;i--){
        push(&A,i);
    }
    hanoi(size,&A,&C,&B,&count);
    printf("%d",count);
    return 0;
    destroy(&A);
    destroy(&B);
    destroy(&C);
}