#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int precedence(char c)
{
    if(c == '^')
        return 3;
    if(c == '*' || c == '/')
        return 2;
    if(c == '+' || c == '-')
        return 1;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;
    char c;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(i = 0; i < strlen(infix); i++)
    {
        c = infix[i];

        if(isalnum(c))
        {
            postfix[j++] = c;
        }
        else if(c == '(')
        {
            push(c);
        }
        else if(c == ')')
        {
            while(top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            pop();
        }
        else
        {
            while(top != -1 && stack[top] != '(' &&
                  precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = pop();
            }

            push(c);
        }
    }

    while(top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}