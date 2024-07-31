#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack1.h"
int main()
{
	int size;
    stack_t *Stack1 = NULL;
    stutes_t stutes = S_NOK;
	void *poped_item;
	
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

	for (int i = 0; i < size; i++) 
	{
		if( (str[i]=='[' )||(str[i]=='{' )||(str[i]=='(' ) )
		{
			stutes=push(Stack1,&str[i]);
			if(stutes==1)printf("%c pushed seccfelly\n",str[i]);						
		}
		else if((str[i]==']' )||(str[i]=='}' )||(str[i]==')' ))
		{
			poped_item=pop(Stack1, &stutes);	
			if(stutes==1) printf("%c poped seccfelly\n",*(char*)poped_item);
		}
		else
		{
			continue;
		}

	}
	
	int counter=StackCount(Stack1,&stutes);
	if(counter==0) 
	{
		printf("valid\n");
	}
	else 
	{
		printf("not valid \n");
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