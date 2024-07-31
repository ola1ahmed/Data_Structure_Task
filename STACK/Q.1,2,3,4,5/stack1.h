#ifndef _STACK_H_
#define _STACK_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
	signed int top_index;
	unsigned int stack_size;
	unsigned int number_of_element;
	void **ptr; //pointer to array of pointer 
}stack_t;
typedef enum
{
	S_NOK=0,
	S_OK,
	S_EMPTY,
	S_FULL,
	S_NULL,
}stutes_t;

stack_t* createstack(stutes_t *stutes,int size);
stutes_t push(stack_t *mystack,void *item);
void* pop(stack_t *mystack,stutes_t *stutes);
void* stacktop(stack_t *mystack,stutes_t *stutes);
void*FindMin(stack_t *mystack,stutes_t *stutes);
int StackCount (stack_t* mystack, stutes_t *stutes);
stack_t* copy(stack_t *mystack,stutes_t *stutes,stutes_t *newstutes);
stutes_t copy2(stack_t *mystack,stack_t *copiedstack,stutes_t *stutes);
void displayStackElement(stack_t *mystack,stutes_t *stutes);
stutes_t destroystack(stack_t *mystack);

#endif

