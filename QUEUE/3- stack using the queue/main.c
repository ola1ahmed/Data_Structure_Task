#include <stdio.h>
#include "queue.h"
int main()
{
	
	queue_t *Queue=NULL;
	status_t status;
	uint32 Number1 = 0x11, Number2 = 0x22, Number3 = 0x33, Number4 = 0x44, Number5 = 0x55;
	void *dequeue_number=NULL;
	uint32 count;
	uint32 size;

	Queue=Create_Queue(&status);
	if(status==1) printf("done\n");
	printf("0x%X \n", Queue);
	
	status=Enqueue_Element(Queue,&Number1);
	printf("=> %i \n", status);
	status=Enqueue_Element(Queue,&Number2);
	printf("=> %i \n", status);
	status=Get_Queue_Count(Queue,&count);
	printf("count:%d",count);
	printf("=> %i \n", status);
	status=Enqueue_Element(Queue,&Number3);
	printf("=> %i \n", status);
	status=Enqueue_Element(Queue,&Number4);
	printf("=> %i \n", status);
	status=Enqueue_Element(Queue,&Number5);
	printf("=> %i \n", status);
	
	status=Get_Queue_Count(Queue,&count);
	printf("count:%d \n",count);
	
	dequeue_number=Dequeue_Element(Queue,&status);
	printf("dequeue element: 0x%x\n",*(uint32*)dequeue_number);
	printf("=> %i \n", status);
	dequeue_number=Dequeue_Element(Queue,&status);
	printf("dequeue element: 0x%x\n",*(uint32*)dequeue_number);
	printf("=> %i \n", status);
	dequeue_number=Dequeue_Element(Queue,&status);
	printf("dequeue element: 0x%x\n",*(uint32*)dequeue_number);
	printf("=> %i \n", status);
	dequeue_number=Dequeue_Element(Queue,&status);
	printf("dequeue element: 0x%x\n",*(uint32*)dequeue_number);
	printf("=> %i \n", status);
	dequeue_number=Dequeue_Element(Queue,&status);
	printf("dequeue element: 0x%x\n",*(uint32*)dequeue_number);
	printf("=> %i \n", status);
	
	status=Destroy_Queue(Queue);
	if(status==1) printf("done\n");
	

	
	return 0;
	 
}
//gcc main.c queue.c -o q3.exe