#ifndef QUEUE_BASED_ON_STACK_H
#define QUEUE_BASED_ON_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    Queue_OK,
    Queue_NOK,
    Queue_EMPTY,
	Queue_FULL,
	Queue_NULL
} status_t;

typedef struct {
    void **ptr;
    int top_index;
    int number_of_element;
    unsigned int max_size;
} stack_t;

typedef struct {
    stack_t *stack1;
    stack_t *stack2;
} queue_t;

stack_t* createstack(status_t *status, unsigned int max_size);
status_t push(stack_t *mystack, void *item);
void* pop(stack_t *mystack, status_t *status);

queue_t* Create_Queue(unsigned int max_size, status_t *status);
status_t Enqueue_Element(queue_t *queue, void *element);
void* Dequeue_Element(queue_t *queue, status_t *status);

status_t Get_Queue_Count(queue_t *queue, unsigned int *QueueCount);
status_t Destroy_Queue(queue_t *queue);

#endif
