#ifndef _STACK_H_
#define _STACK_H_

typedef struct stack {
    signed int top_index;
    unsigned int stack_size;
    unsigned int number_of_element;
    char *ptr;  
} stack_t;

typedef enum {
    S_NOK=0,
    S_OK,
    S_EMPTY,
    S_FULL,
    S_NULL,
} stutes_t;

stack_t* createstack(stutes_t *stutes, int size);
stutes_t push(stack_t *mystack, char item);
char pop(stack_t *mystack, stutes_t *stutes);
char stacktop(stack_t *mystack, stutes_t *stutes);
int IsEmpty(stack_t *mystack);
stutes_t destroystack(stack_t *mystack);

#endif
