#include "stack1.h"
/*                 local function                          	 */
static int IsEmpty(stack_t *mystack)
{
	if(mystack->number_of_element == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
static int IsFull(stack_t *mystack)
{
	
	if(mystack->number_of_element==mystack->stack_size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*****************************************************************/
stack_t* createstack(stutes_t *stutes,int size){
	*stutes=S_NOK;
	stack_t *mystack;
	if(mystack ==NULL)
	{
		*stutes=S_NULL;
	}
	else
	{
		mystack=(stack_t*)malloc(sizeof(stack_t));
		if(mystack ==NULL)
		{
			*stutes=S_NULL;
		}
		else
		{
			mystack->ptr=(void**)calloc(size,sizeof(void*));
			if(mystack->ptr ==NULL)
			{
				*stutes=S_NULL;
			}
			else
			{
				mystack->top_index=-1;
				mystack->stack_size=size; 
				mystack->number_of_element=0;
				*stutes=S_OK;
			}
		}
	}
	
	return mystack;
}

stutes_t push(stack_t *mystack,void *item){
	stutes_t stutes=S_NOK;
	if(mystack ==NULL || item ==NULL)
	{
		stutes=S_NOK;
	}
	else
	{
		if(IsFull(mystack))
		{
			stutes=S_FULL;
		}
		else
		{
			(mystack->top_index)++;
			mystack->ptr[mystack->top_index]=item;
			(mystack->number_of_element)++;
			stutes=S_OK;
		}
	}
	return stutes;
}
void* pop(stack_t *mystack,stutes_t *stutes)
{
	*stutes=S_NOK;
	void *item = NULL;
	if(mystack ==NULL)
	{
		*stutes=S_NOK;
	}
	else
	{
		if(IsEmpty(mystack))
		{
			*stutes=S_EMPTY;
		}
		else
		{
			item = mystack->ptr[mystack->top_index];
			(mystack->top_index)--; 
			(mystack->number_of_element)--;
			*stutes=S_OK;
		}
	}
	return item;
}

void* stacktop(stack_t *mystack,stutes_t *stutes)
{
	*stutes=S_NOK;
	void *item = NULL;
	if(mystack ==NULL)
	{
		*stutes=S_NOK;
	}
	else
	{
		if(IsEmpty(mystack))
		{
			*stutes=S_EMPTY;
		}
		else
		{
			item = mystack->ptr[mystack->top_index];
			*stutes=S_OK;
		}
	}
	return item;
	
}


void*FindMin(stack_t *mystack,stutes_t *stutes)
{
	*stutes=S_NOK;
	
	void *min_item = mystack->ptr[0];
	int min_value = *(int *)min_item;
	int current_value;
	signed int i;
	if(mystack ==NULL)
	{
		*stutes=S_NOK;
	}
	else
	{
		if(IsEmpty(mystack))
		{
			*stutes=S_EMPTY;
		}
		else
		{
			for (i = mystack->top_index; i >= 0; i--) 
			{
				current_value = *(int *)(mystack->ptr[i]);
				if (current_value < min_value) 
				{
					min_value = current_value;
					min_item = mystack->ptr[i];
				}
				*stutes=S_OK;
			}
		}
	}
	return min_item;
}


int StackCount (stack_t* mystack, stutes_t *stutes)
{
	int stack_count;
	*stutes=S_NOK;
	if(mystack ==NULL)
	{
		*stutes=S_NOK;
	}
	else
	{
		stack_count=mystack->number_of_element;
		*stutes=S_OK;
	}
	return stack_count;
}
stack_t* copy(stack_t *mystack,stutes_t *stutes,stutes_t *newstutes)
{
	*newstutes=S_NOK;
	stack_t *newStack=NULL;
	if(mystack ==NULL)
	{
		*newstutes=S_NOK;
	}
	else
	{
		newStack=createstack(stutes,mystack->stack_size);
		if(stutes ==S_NOK)
		{
			*newstutes=S_NULL;
		}
		else
		{
			for ( int i = mystack->top_index; i >= 0; i--) 
			{
				newStack->ptr[i] = (mystack->ptr[i]);
			}
			newStack->stack_size=mystack->stack_size;
			newStack->top_index=mystack->top_index;
			newStack->number_of_element=mystack->number_of_element;
			if(IsEmpty(newStack))
			{
				*newstutes=S_EMPTY;
			}
			else if(IsFull(newStack))
			{
				*newstutes=S_FULL;
			}
			else
			{
				*newstutes=S_OK;
			}
		}
	}
	return newStack;
}
stutes_t copy2(stack_t *mystack,stack_t *copiedstack,stutes_t *stutes)
{
	stutes_t newstutes=S_NOK;
	if(mystack ==NULL)
	{
		newstutes=S_NOK;
	}
	else
	{
		for ( int i = mystack->top_index; i >= 0; i--) 
		{
			copiedstack->ptr[i] = (mystack->ptr[i]);
		}
		copiedstack->stack_size=mystack->stack_size;
		copiedstack->top_index=mystack->top_index;
		copiedstack->number_of_element=mystack->number_of_element;
		if(IsEmpty(copiedstack))
		{
			newstutes=S_EMPTY;
		}
		else if(IsFull(copiedstack))
		{
			newstutes=S_FULL;
		}
		else
		{
			newstutes=S_OK;
		}
	}
	return newstutes;
}

void displayStackElement(stack_t *mystack,stutes_t *stutes)
{
	
	if(mystack ==NULL)
	{
		*stutes=S_NOK;
	}
	else
	{
		printf("stack display: \n");
		for ( int i = mystack->top_index; i >= 0; i--) 
		{
			printf("%d \t",*(int*)(mystack->ptr[i]));
		}
		printf("\n");
		
	}
	
}
stutes_t destroystack(stack_t *mystack)
{
	stutes_t stutes=S_NOK;
	if(mystack ==NULL)
	{
		stutes=S_NOK;
	}
	else
	{
		free(mystack->ptr);
		free(mystack);
		stutes=S_OK;
	}
	return stutes;
}