#ifndef STACK_BASED_ON_QUEUEK_H
#define STACK_BASED_ON_QUEUEK_H
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

typedef enum {
	Stack_NOK,
	Stack_OK,
	Stack_Empty 
} status_t;

typedef struct queueNode {
    void *entry;
    struct queueNode *next;
} queueNode_t;

typedef struct {
    queueNode_t *front;
    queueNode_t *rear;
    uint32 Elementcounter;
} queue_t;

queue_t* Create_Queue(status_t *status);
status_t Destroy_Queue(queue_t* my_queue);
status_t Enqueue_Element(queue_t* my_queue, void *element);
void* Dequeue_Element(queue_t* my_queue, status_t *status);
status_t Get_Queue_Count(queue_t* my_queue, uint32 *QueueCount);


typedef struct {
    queue_t *primaryQueue;
    queue_t *tempQueue;
} stack_t;

stack_t* Create_Stack(status_t *status);
status_t Destroy_Stack(stack_t* my_stack);
status_t Push_Element(stack_t* my_stack, void *element);
void* Pop_Element(stack_t* my_stack, status_t *status);
status_t Get_Stack_Count(queue_t* my_queue, uint32 *Stack_Count)
#endif