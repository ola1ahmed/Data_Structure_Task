#include "queue_basedonstack.h"

int main() {
    status_t status;
	int size;
	printf("enter size of queue:");
	scanf("%d",&size);
    queue_t *myQueue = Create_Queue(size, &status);

    if (status == Queue_OK) 
	{
        int Number1 = 0x11, Number2 = 0x22, Number3 = 0x33, Number4 = 0x44, Number5 = 0x55;

        status=Enqueue_Element(myQueue, &Number1);
		printf("=> %i \n", status);
        status=Enqueue_Element(myQueue, &Number2);
		printf("=> %i \n", status);
        status=Enqueue_Element(myQueue, &Number3);
		printf("=> %i \n", status);
		status=Enqueue_Element(myQueue, &Number4);
		printf("=> %i \n", status);
		status=Enqueue_Element(myQueue, &Number5);
		printf("=> %i \n", status);
        int *result;

        result = (int *)Dequeue_Element(myQueue, &status);
        printf("Dequeued: %d\n", *result);  

        result = (int *)Dequeue_Element(myQueue, &status);
        printf("Dequeued: %d\n", *result);  

        result = (int *)Dequeue_Element(myQueue, &status);
        printf("Dequeued: %d\n", *result);

		result = (int *)Dequeue_Element(myQueue, &status);
        printf("Dequeued: %d\n", *result);  		
		
		result = (int *)Dequeue_Element(myQueue, &status);
        if(result!=NULL)printf("Dequeued: %d\n", *result);  

        Destroy_Queue(myQueue);
    } 
	else
	{
        printf("Failed to create queue.\n");
    }

    return 0;
}
