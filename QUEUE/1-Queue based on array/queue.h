#ifndef _DYNAMIC_QUEUE_H_
#define _DYNAMIC_QUEUE_H_
#include "types.h"
#include <stdlib.h>

typedef struct
{
    void **queue_arr;
    sint32 queuefront;
    sint32 queuerear;
    sint32 maxsize;
    uint32 Elementcounter;

}queue_t;

typedef enum
{
    Queue_NOK=0,
    Queue_OK,
    Queue_Full,
    Queue_Empty,
    Queue_Null_Pointer,
}status_t;

queue_t* Create_Queue(uint32 max_size ,status_t *status);
status_t Destroy_Queue(queue_t* my_queue);
status_t Enqueue_Element(queue_t* my_queue,void *element);
void *Dequeue_Element(queue_t* my_queue,status_t *status);//status_t Dequeue_Element(queue_t* my_queue,void *element);
status_t Get_Queue_Count(queue_t* my_queue,uint32 *QueueCount);
#endif // _DYNAMIC_QUEUE_H_
