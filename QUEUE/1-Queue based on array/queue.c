#include "queue.h"

queue_t* Create_Queue(uint32 max_size ,status_t *status){
	*status=Queue_NOK;
	queue_t *my_queue=(queue_t *)malloc(sizeof(queue_t));
	if(my_queue!=NULL)
	{
		my_queue->queue_arr=(void**)calloc(max_size,sizeof(void *));
		if((my_queue->queue_arr)!=NULL)
		{
			my_queue->maxsize=max_size;
			my_queue->queuefront=-1;
			my_queue->queuerear=-1;
			my_queue->Elementcounter=0;
			*status=Queue_OK;
		}
		else
		{
			*status=Queue_Null_Pointer;
		}
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
	if(my_queue!=NULL)
	{
		free(my_queue->queue_arr);
		free(my_queue);
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
		if((my_queue->Elementcounter)==(my_queue->maxsize))
		{
			status =Queue_Full;
		}
		else
		{
			(my_queue->queuerear)++;
			if( (my_queue->queuerear)==(my_queue->maxsize) )
			{
				my_queue->queuerear=0;
			}
			my_queue->queue_arr[my_queue->queuerear] = element;
           
            if((my_queue->Elementcounter)==0)
            {
                my_queue->queuefront=0;
                my_queue->Elementcounter=1;
            }
            else
            {
                (my_queue->Elementcounter)++;
            }
			status =Queue_OK;
		}
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
			
			element=my_queue->queue_arr[my_queue->queuefront];
			(my_queue->queuefront)++;
			(my_queue->Elementcounter)--;
		
			if((my_queue->queuefront)==(my_queue->maxsize))
            {
                (my_queue->queuefront)=0;
				
            }
            if((my_queue->Elementcounter)==0)
            {
                my_queue->queuefront=-1;
                my_queue->queuerear=-1;
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
status_t Get_Queue_Count(queue_t* my_queue,uint32 *QueueCount){
	status_t status= Queue_NOK;
	if(my_queue!=NULL)
	{
		*QueueCount=my_queue->Elementcounter;
		status= Queue_OK;
	}	
	 return status;
}