#include <iostream>
using namespace std;

class Stack{
    public:
        int Size;
        char* StackArr;
        Stack(int size){
            Size = size;
            StackArr = new char[Size];
        }
        int Top=-1;
        void push(char input){
            if(Top==Size-1){
                cout<<"Stack Overflow";
                return;
            }
            Top++;
            StackArr[Top]=input;
        }
        char pop(){
            if(Top<0){
                cout<<"Stack Undeflow";
                return '~';
            }
            char c = StackArr[Top];
            StackArr[Top]='0';
            Top--;
            return c;
        }
        void display(){
            if(Top<0){
                cout<<"Stack Undeflow";
                return;
            }
            for(int i = Top;i>=0;i--){
                cout<<StackArr[i];
            }
        }
        char Value(){
            return StackArr[Top];
        }
        
    private:

};

int main(){
    int x;
    char input[20];
    char postfix[20];
    int pl=0;
    char check;
    cout<<"Enter Input: ";
    cin>>input;
    Stack s1(20);
    s1.push('#');
    for(int i =0;input[i]!='\0';i++){
        if(isalnum(input[i])){
            postfix[pl]=input[i];
            pl++;
        }
        else if(input[i]=='('){
            s1.push(input[i]);
        }
        else if(input[i]==')'){
            check = s1.pop();
            while(check!='('){
                postfix[pl]=check;
                pl++;
                check = s1.pop();
            }
        
        }
        else if(input[i]=='-' or input[i]=='+'){
            if(s1.Value()=='+' or s1.Value()=='-' or s1.Value()=='*' or s1.Value()=='/' or s1.Value()=='^'){
                postfix[pl]=s1.pop();
                pl++;
            }
            s1.push(input[i]);
        }
        else if(input[i]=='*' or input[i]=='/'){
            if(s1.Value()=='*' or s1.Value()=='/' or s1.Value()=='^'){
                postfix[pl]=s1.pop();
                pl++;
            }
            s1.push(input[i]);
        }
        else if(input[i]=='^'){
            if(s1.Value()=='^'){
                postfix[pl]=s1.pop();
                pl++;
            }
            s1.push(input[i]);
        }
    }
    while(s1.Value()!='#'){
        postfix[pl]=s1.pop();
        pl++;
    }
    postfix[pl]='\0';
    cout<<postfix;
    cin>>x;
    return 0;
}