#include<stdio.h>


struct stack
{
    int top;
    unsigned capacity;
    int *array;
};

typedef struct stack STACK;


STACK* createStack(unsigned capacity)
{
    STACK *stack =(STACK*) malloc(sizeof(STACK));

    if(!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->aray = (int*)malloc(stack->capacity * sizeof(int));

    if(!stack->array)
        return NULL

    return stack;

}

int isEmpty(stack)
{
    return stack->top == -1;
}

char peek(stack)
{
    return stack->array[stack->top];
}

char pop(stack)
{
    if(!isEmpty(stack))
        return stack->array[stack->top--];

    return '$';
}

void push(stack, char op)
{
    stack->array[++stack->top] = op;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}


int Precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}


int infixToPostfix(char* exp)
{
    int i, k;


    //create a stack of capacity equal to expression size
    STACK stack = createStack(strlen(exp));


}
void main()
{

}
