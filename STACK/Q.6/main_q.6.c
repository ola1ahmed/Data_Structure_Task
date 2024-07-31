#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack1.h"
int main()
{
	int size;
    stack_t *Stack1 = NULL;
    stutes_t stutes = S_NOK;
	
	char str[30];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 
    size = strlen(str);
    printf("String: %s\n", str);  

    // Create stack
    Stack1 = createstack(&stutes, size);
    if (Stack1 != NULL) 
	{
        printf("Address of Stack1 starts from: %p\n", (void *)Stack1);
    }
	else
	{
        printf("Error: Stack creation failed.\n");
        return -1;
    }
	
	int ret=validation(str,size,Stack1);
	
	if(ret==1) 
	{
		printf("valid\n");
	}
	else
	{
		
		printf("not valid\n");
	}
	/*destroy stack*/
	stutes=destroystack(Stack1);
	if(stutes==1) 
	{
		printf("desroied seccfelly\n");
	}
	
	return 0;
}	


//[ola{ahmed}]

//gcc main_q.6.c stack1.c -o task1.exe