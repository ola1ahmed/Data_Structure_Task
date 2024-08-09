#include "stack1.h"
#include <stdlib.h>

int IsEmpty(stack_t *mystack) {
    return mystack->number_of_element == 0;
}

int IsFull(stack_t *mystack) {
    return mystack->number_of_element == mystack->stack_size;
}

stack_t* createstack(stutes_t *stutes, int size) {
    *stutes = S_NOK;
    stack_t *mystack = (stack_t*)malloc(sizeof(stack_t));
    if (mystack == NULL) {
        *stutes = S_NULL;
    } else {
        mystack->ptr = (char*)calloc(size, sizeof(char)); 
        if (mystack->ptr == NULL) {
            *stutes = S_NULL;
        } else {
            mystack->top_index = -1;
            mystack->stack_size = size;
            mystack->number_of_element = 0;
            *stutes = S_OK;
        }
    }
    return mystack;
}

stutes_t push(stack_t *mystack, char item) {
    stutes_t stutes = S_NOK;
    if (mystack == NULL) {
        stutes = S_NOK;
    } else {
        if (IsFull(mystack)) {
            stutes = S_FULL;
        } else {
            mystack->ptr[++(mystack->top_index)] = item;
            (mystack->number_of_element)++;
            stutes = S_OK;
        }
    }
    return stutes;
}

char pop(stack_t *mystack, stutes_t *stutes) {
    *stutes = S_NOK;
    char item = '\0';
    if (mystack == NULL) {
        *stutes = S_NOK;
    } else {
        if (IsEmpty(mystack)) {
            *stutes = S_EMPTY;
        } else {
            item = mystack->ptr[(mystack->top_index)--];
            (mystack->number_of_element)--;
            *stutes = S_OK;
        }
    }
    return item;
}

char stacktop(stack_t *mystack, stutes_t *stutes) {
    *stutes = S_NOK;
    char item = '\0';
    if (mystack == NULL) {
        *stutes = S_NOK;
    } else {
        if (IsEmpty(mystack)) {
            *stutes = S_EMPTY;
        } else {
            item = mystack->ptr[mystack->top_index];
            *stutes = S_OK;
        }
    }
    return item;
}

stutes_t destroystack(stack_t *mystack) {
    stutes_t stutes = S_NOK;
    if (mystack == NULL) {
        stutes = S_NOK;
    } else {
        free(mystack->ptr);
        free(mystack);
        stutes = S_OK;
    }
    return stutes;
}
