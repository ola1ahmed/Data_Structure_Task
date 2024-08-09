#include "queue_basedonstack.h"

stack_t* createstack(status_t *status, unsigned int max_size) {
    *status=Queue_NOK;
	stack_t *mystack;
	if(mystack ==NULL)
	{
		*status=Queue_NULL;
	}
	else
	{
		mystack=(stack_t*)malloc(sizeof(stack_t));
		if(mystack ==NULL)
		{
			*status=Queue_OK;
		}
		else
		{
			mystack->ptr=(void**)calloc(max_size,sizeof(void*));
			if(mystack->ptr ==NULL)
			{
				*status=Queue_NULL;
			}
			else
			{
				mystack->top_index=-1;
				mystack->max_size=max_size; 
				mystack->number_of_element=0;
				*status=Queue_OK;
			}
		}
	}
	
	return mystack;
}
status_t push(stack_t *mystack, void *item) {
    if (mystack == NULL || item == NULL) {
        return Queue_NOK;
    }
    if (mystack->number_of_element >= mystack->max_size) {
        return Queue_NOK; // Stack is full
    }
    mystack->ptr[++(mystack->top_index)] = item;
    mystack->number_of_element++;
    return Queue_OK;
}

void* pop(stack_t *mystack, status_t *status) {
    if (mystack == NULL || status == NULL) {
        *status = Queue_NOK;
        return NULL;
    }
    if (mystack->number_of_element == 0) {
        *status = Queue_NOK; // Stack is empty
        return NULL;
    }
    *status = Queue_OK;
    void *item = mystack->ptr[(mystack->top_index)--];
    mystack->number_of_element--;
    return item;
}


queue_t* Create_Queue(unsigned int max_size, status_t *status) {
    queue_t *myqueue = (queue_t *)malloc(sizeof(queue_t));
    if (myqueue == NULL)
	{
        *status = Queue_NOK;
        return NULL;
    }
    myqueue->stack1 = createstack(status, max_size);
    if (*status != Queue_OK) 
	{
        free(myqueue);
        return NULL;
    }

    myqueue->stack2 = createstack(status, max_size);
    if (*status != Queue_OK) 
	{
        free(myqueue->stack1);
        free(myqueue);
        return NULL;
    }

    *status = Queue_OK;
    return myqueue;
}

status_t Enqueue_Element(queue_t *queue, void *element) {
	status_t status=Queue_NOK;
    if (queue == NULL || element == NULL) {
        status=Queue_NOK;
    }
	else
	{
		if((queue->stack1->number_of_element)==(queue->stack1->max_size))
		{
			status=Queue_FULL;
		}
		else
		{
		push(queue->stack1, element);
		}
	}
    
    return status;
}

void* Dequeue_Element(queue_t *queue, status_t *status) 
{
    void *number = NULL;
    status_t local_status = Queue_NOK;
    int num_elements1 = queue->stack1->number_of_element;
    int num_elements2 = queue->stack2->number_of_element;

    if (queue == NULL || status == NULL) {
        *status = Queue_NOK;
        number=NULL;
    }

    if (num_elements2 == 0) {
        while (num_elements1 > 0) 
		{
            number = pop(queue->stack1, &local_status);
            if (local_status == Queue_OK) 
			{
                push(queue->stack2, number);
            }
            num_elements1--;
        }
    }

    number = pop(queue->stack2, &local_status);
    if (local_status == Queue_OK)
	{
        *status = Queue_OK;
    } else {
        *status = Queue_EMPTY;
    }

    return number;
}

status_t Get_Queue_Count(queue_t *queue, unsigned int *QueueCount) 
{
	status_t status = Queue_NOK;
    if (queue == NULL || QueueCount == NULL) 
	{
        status=Queue_NOK;
    }
	else
	{
		*QueueCount = queue->stack1->number_of_element + queue->stack2->number_of_element;
		status=Queue_NOK;	
	}
    return status;
}

status_t Destroy_Queue(queue_t *queue) 
{
	status_t status = Queue_NOK;
    if (queue == NULL) 
	{
        status=Queue_NOK;
    }
	else
	{
		
		free(queue->stack1->ptr);
		free(queue->stack1);
		free(queue->stack2->ptr);
		free(queue->stack2);
		free(queue);
	}
    
    
    return status;
}
