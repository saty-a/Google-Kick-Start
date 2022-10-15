#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
struct stack 
{
    int size;
    int top;
    char *arr;
};
int isFull(struct stack *sp) //check wether stack is full or not
{
    if(sp->top==MAX)
    {
        return 1;
    }
    else return 0;
}
int isEmpty(struct stack *sp) //check wether stack is empty or not
{
    if(sp->top==-1)
    {
        return 1;
    }
    else return 0;
}
int push(struct stack *sp,int val) //to add operator in stack
{
    if(isFull(sp))
    {
        printf("Stack overflow\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top]=val;
    }
}
int pop(struct stack *sp)  //to remove operator from stack
{
    if(isEmpty(sp))
    {
        printf("Stack underflow\n");
    }
    else
    {
        int val;
        val=sp->arr[sp->top];
        sp->top=sp->top-1;
        return val;
    }
}
int isOperator(char c) // check that character is operator or not
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
    {
        return 1;
    }
    else return 0;
}
int precedence(char c) //check the precedence of operator
{
    if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else return 0;
}
char stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}
char *infixTopostfix(char *infix)
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack)); //stack to store operator
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));
    char *pos=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0,j=0;
    while(infix[i]!='\0') //to track infix form
    {
        if(!isOperator(infix[i])) //check for operator 
        {
            pos[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(sp))) //check for precedence
            {
                push(sp,infix[i]);
                i++;
            }
            else{
                pos[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)) //to empty the stack and fill remaining element to postfix
    {
        pos[j]=pop(sp);
        j++;
    }
    pos[j]='\0';  //null element at last of string
    return pos;  //return postfix
}
int main()   //driver code
{
    char *infix;
    infix="A*B+C-D";
    printf("Infix form is:%s\n",infix); //to print infix form
    char *postfix=infixTopostfix(infix);
    printf("Postfix for is:%s\n",postfix);  //to print postfix form
}