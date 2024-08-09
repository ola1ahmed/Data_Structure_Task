#include "queueLL.h"

queue_t* Create_Queue(status_t *status){
	*status=Queue_NOK;
	queue_t *my_queue=(queue_t *)malloc(sizeof(queue_t));
	if(my_queue!=NULL)
	{
		my_queue->front=NULL;
		my_queue->rear=NULL;
		my_queue->Elementcounter=0;
	}
	else
	{
		*status=Queue_NOK;
	}
	return my_queue;
}
status_t Destroy_Queue(queue_t* my_queue)
{
	status_t status =Queue_NOK;
	queueNode_t *tempPtr =NULL;
	if(my_queue!=NULL)
	{
		while((my_queue->Elementcounter)!=0)
		{
			
			tempPtr = my_queue->front;
            my_queue->front = my_queue->front->next;
			free(tempPtr);
			my_queue->Elementcounter--;
		}
		status =Queue_OK;
	}
	else
	{
		status =Queue_NOK;
	}
	
	return status;
}
status_t Enqueue_Element(queue_t* my_queue,void *element)
{
	status_t status =Queue_NOK;
	if(my_queue!=NULL)
	{
		
		queueNode_t *queueNode=(queueNode_t *)malloc(sizeof(queueNode_t));
		queueNode->next=NULL;
		queueNode->entry=element;
		if((my_queue->Elementcounter)!=0)
		{
			my_queue->rear->next=queueNode;
				my_queue->rear=queueNode;
		}
		else
		{
			my_queue->rear=queueNode;
			my_queue->front=queueNode;
		}
		my_queue->Elementcounter++;	
		status =Queue_OK;	
		
	}
	else
	{
		status =Queue_NOK;
	}
	return status;
}
void *Dequeue_Element(queue_t* my_queue,status_t *status){
	void *element=NULL;
	*status =Queue_NOK;
	if(my_queue!=NULL)
	{
		if((my_queue->Elementcounter)==0)
		{
			*status =Queue_Empty;
			element = NULL;

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
				my_queue->Elementcounter = 0;
            }
            
			
			*status=Queue_OK;
		}
	}
	else
	{
		*status =Queue_NOK;
	}
	return element;
}
void Traverse_Queue(queue_t* my_queue, void (*func)(void *)) 
{
    if (my_queue != NULL) 
	{
        queueNode_t *current = my_queue->front;
        while (current != NULL)
		{
            func(current->entry);  
            current = current->next;  
        }
    }
}


status_t Get_Queue_Count(queue_t* my_queue,uint32 *QueueCount){
	status_t status= Queue_NOK;
	if(my_queue!=NULL)
	{
		*QueueCount=my_queue->Elementcounter;
		status= Queue_OK;
	}	
	 return status;
}