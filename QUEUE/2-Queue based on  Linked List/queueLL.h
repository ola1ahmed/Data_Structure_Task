#ifndef _QUEUELL_H_
#define _QUEUELL_H_

#include "types.h"
#include <stdlib.h>

typedef struct queueNode {
    void *entry;            
    struct queueNode *next; 
} queueNode_t;

typedef struct queue {
    queueNode_t *front;      
    queueNode_t *rear;       
    uint32 Elementcounter; 
} queue_t;

typedef enum
{
    Queue_NOK=0,
    Queue_OK,
    Queue_Full,
    Queue_Empty,
    Queue_Null_Pointer,
}status_t;

queue_t* Create_Queue(status_t *status);
status_t Destroy_Queue(queue_t* my_queue);
status_t Enqueue_Element(queue_t* my_queue,void *element);
void *Dequeue_Element(queue_t* my_queue,status_t *status);
void Traverse_Queue(queue_t* my_queue, void (*func)(void *)); 
status_t Get_Queue_Count(queue_t* my_queue,uint32 *QueueCount);
#endif // _QUEUELL_H_
