#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


queue_t* Create_Queue(status_t *status) 
{
    *status = Stack_NOK;
    queue_t *my_queue = (queue_t *)malloc(sizeof(queue_t));
    if (my_queue != NULL) 
	{
        my_queue->front = NULL;
        my_queue->rear = NULL;
        my_queue->Elementcounter = 0;
        *status = Stack_OK;
    }
    return my_queue;
}

status_t Destroy_Queue(queue_t* my_queue) 
{
    status_t status = Stack_NOK;
    queueNode_t *tempPtr = NULL;
    if (my_queue != NULL) 
	{
        while (my_queue->Elementcounter != 0) 
		{
            tempPtr = my_queue->front;
            my_queue->front = my_queue->front->next;
            free(tempPtr);
            my_queue->Elementcounter--;
        }
        free(my_queue);
        status = Stack_OK;
    }
    return status;
}

status_t Enqueue_Element(queue_t* my_queue, void *element) 
{
    status_t status = Stack_NOK;
    if (my_queue != NULL) 
	{
        queueNode_t *queueNode = (queueNode_t *)malloc(sizeof(queueNode_t));
        if (queueNode != NULL) 
		{
            queueNode->entry = element;
            queueNode->next = NULL;
            if (my_queue->Elementcounter == 0) 
			{
                my_queue->front = queueNode;
                my_queue->rear = queueNode;
            } 
			else 
			{
                my_queue->rear->next = queueNode;
                my_queue->rear = queueNode;
            }
            my_queue->Elementcounter++;
            status = Stack_OK;
        }
    }
    return status;
}

void* Dequeue_Element(queue_t* my_queue, status_t *status) 
{
    void *element = NULL;
    *status = Stack_NOK;
    if (my_queue != NULL) {
        if (my_queue->Elementcounter == 0) 
		{
            *status = Stack_Empty;
        } 
		else 
		{
            queueNode_t *tempPtr = my_queue->front;
            element = my_queue->front->entry;
            my_queue->front = my_queue->front->next;
            free(tempPtr);
            my_queue->Elementcounter--;
            if (my_queue->Elementcounter == 0) 
			{
                my_queue->front = NULL;
                my_queue->rear = NULL;
            }
            *status = Stack_OK;
        }
    }
    return element;
}

status_t Get_Queue_Count(queue_t* my_queue, uint32 *QueueCount) 
{
    status_t status = Stack_NOK;
    if (my_queue != NULL)
		{
        *QueueCount = my_queue->Elementcounter;
        status = Stack_OK;
    }
    return status;
}

stack_t* Create_Stack(status_t *status) 
{
    *status = Stack_NOK;
    stack_t *my_stack = (stack_t *)malloc(sizeof(stack_t));
    if (my_stack != NULL) 
	{
        my_stack->primaryQueue = Create_Queue(status);
        if (*status == Stack_OK) 
		{
            my_stack->tempQueue = Create_Queue(status);
            if (*status == Stack_OK) 
			{
                *status = Stack_OK;
            }
			else 
			{
                Destroy_Queue(my_stack->primaryQueue);
                free(my_stack);
                my_stack = NULL;
            }
        }
		else 
		{
            free(my_stack);
            my_stack = NULL;
        }
    }
    return my_stack;
}

status_t Destroy_Stack(stack_t* my_stack) 
{
    status_t status = Stack_NOK;
    if (my_stack != NULL) 
	{
        Destroy_Queue(my_stack->primaryQueue);
        Destroy_Queue(my_stack->tempQueue);
        free(my_stack);
        status = Stack_OK;
    }
    return status;
}

status_t Push_Element(stack_t* my_stack, void *element) 
{
    status_t status = Stack_NOK;
    if (my_stack != NULL) 
	{
        
        Enqueue_Element(my_stack->primaryQueue, element);
     
        while (Get_Queue_Count(my_stack->primaryQueue, NULL) > 0) 
		{
            void *elem = Dequeue_Element(my_stack->primaryQueue, &status);
            Enqueue_Element(my_stack->tempQueue, elem);
        }
        
       
        queue_t *temp = my_stack->primaryQueue;
        my_stack->primaryQueue = my_stack->tempQueue;
        my_stack->tempQueue = temp;

        status = Stack_OK;
    }
    return status;
}

void* Pop_Element(stack_t* my_stack, status_t *status) 
{
    void *element = NULL;
    *status = Stack_NOK;
    if (my_stack != NULL) 
	{
        element = Dequeue_Element(my_stack->primaryQueue, status);
    }
    return element;
}

status_t Get_Stack_Count(stack_t* my_stack, uint32 *StackCount) 
{
    return Get_Queue_Count(my_stack->primaryQueue, StackCount);
}
