#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack1.h"

int precedence(char oprand) 
{
    switch (oprand) {
        case '^': return 4;
        case '*': case '/': return 3;
        case '+': case '-': return 2;
        case '(': return 1;
        default: return 0;
    }
}

int main() 
{
    int size;
    stack_t *stack1 = NULL;
    stutes_t stutes = S_NOK;
    int index = 0;
    
    char infix[100];
    char postfix[100];
    
    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';  
    size = strlen(infix);
    printf("Infix Expression: %s\n", infix);  

    stack1 = createstack(&stutes, size);
    if (stack1 == NULL) 
	{
        printf("Error: Failed to create stack\n");
        return 1;
    }

    for (int i = 0; i < size; i++) 
	{
        if (isalpha(infix[i])) 
		{
            postfix[index++] = infix[i];
        } else if (infix[i] == '(') {
            if (push(stack1, infix[i]) != S_OK) 
			{
                printf("Error: Failed to push '(' onto stack\n");
                return 1;
            }
        } 
		else if (infix[i] == ')') 
		{
            while (!IsEmpty(stack1) && stacktop(stack1, &stutes) != '(') 
			{
                postfix[index++] = pop(stack1, &stutes);
            }
            if (stutes != S_OK) 
			{
                printf("Error: Failed to pop from stack\n");
                return 1;
            }
            pop(stack1, &stutes);  
            if (stutes != S_OK) 
			{
                printf("Error: Failed to pop '(' from stack\n");
                return 1;
            }
        } 
		
		else 
		{
            while (!IsEmpty(stack1) && precedence(infix[i]) <= precedence(stacktop(stack1, &stutes)))
			{
                postfix[index++] = pop(stack1, &stutes);
            }
            if (stutes != S_OK) 
			{
                printf("Error: Failed to pop from stack\n");
                return 1;
            }
            if (push(stack1, infix[i]) != S_OK)
				{
                printf("Error: Failed to push operator onto stack\n");
                return 1;
            }
        }
    }

    while (!IsEmpty(stack1))
		{
        postfix[index++] = pop(stack1, &stutes);
        if (stutes != S_OK) {
            printf("Error: Failed to pop from stack\n");
            return 1;
        }
    }

    postfix[index] = '\0';
    printf("Postfix Expression: %s\n", postfix);




    if (destroystack(stack1) == S_OK) {
        printf("Stack destroyed successfully\n");
    } else {
        printf("Error: Failed to destroy the stack\n");
        return 1;
    }
    
    return 0;
}
// A+B*(C-D)/M ------>ABCD-*M/+
