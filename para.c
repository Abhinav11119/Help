#include <stdio.h>

struct Stack {   
    char StackArr[100];
    int top;
};

void innit(struct Stack *s1){
    s1->top = -1;
}


char value(struct Stack *s1){
    if (s1->top==-1)
    {
        return '0';
    }
    return s1->StackArr[s1->top];
}

void push(struct Stack *s1, char c){
    s1->top++;
    s1->StackArr[s1->top] = c;
    printf("%c",s1->top);
}

char pop(struct Stack *s1){
    if (s1->top==-1)
    {
        return '0';
    }
    char temp = value(s1);
    s1->top--;
    printf("%c\n",temp);
    return temp; 
}

int main(){
    struct Stack s1;
    innit(&s1);
    char input[100];
    scanf("%[^#]s",input);
    int i =0, balance = 1;
    while(input[i]!='\0'){
        switch(input[i]){
            case '(':
            case '{':
            case '[':
                push(&s1,input[i]);
                break;
            case ')':
                if(value(&s1)=='('){
                    pop(&s1);
                }
                else{
                    printf("Break 1\n");
                    balance = 0;
                }
                break;
            case ']':
                if(value(&s1)=='['){
                    pop(&s1);
                }
                else{
                    balance = 0;
                    printf("Break 2\n");
                }
                break;
            case '}':
                if(value(&s1)=='{'){
                    pop(&s1);
                }
                else{
                    balance = 0;
                    printf("Break 3\n");
                }
                break;
            }
        i++;
    }
    if(s1.top!=-1){
        balance = 0;
    }
    if(balance==1){
        printf("Balnced Paranthesis");
    }
    else{
        printf("Not Balanced");
    }
}
