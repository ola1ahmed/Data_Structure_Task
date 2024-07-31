#include <stdio.h>
#include "stack1.h"
int menu(stack_t *Stack1 ,stutes_t stutes);

int main()
{
	int size;
	stack_t *Stack1 = NULL;
	stutes_t stutes=S_NOK;
	
	stack_t *Stack2 = NULL;
	stutes_t newstutes=S_NOK;
	
	void *number=NULL;
	int *min_number=NULL;
	int num1=55,num2=22,num3=33,num4=44,num5=100;
	
	printf("enter size of stack you want:");
	scanf("%d",&size);
	/*create stack*/
	Stack1=createstack(&stutes,size);
	printf("address of stack1 start from:0x%X \n",Stack1);
	Stack2=createstack(&newstutes,size);
	printf("address of stack2 start from:0x%X \n",Stack2);
	/////////////////////////////////////////////////////menu(Stack1 ,stutes); 
	
	/*push data*/
	stutes=push(Stack1,&num1);
	if(stutes==1)printf("%d pushed seccfelly\n",num1);
	stutes=push(Stack1,&num2);
	if(stutes==1)printf("%d pushed seccfelly\n",num2);
	stutes=push(Stack1,&num3);
	if(stutes==1)printf("%d pushed seccfelly\n",num3);
	stutes=push(Stack1,&num4);
	if(stutes==1)printf("%d pushed seccfelly\n",num4);
	
	/*copy and display*/
	displayStackElement(Stack1,&stutes);
	Stack2=copy(Stack1,&stutes,&newstutes);
	displayStackElement(Stack2,&newstutes);
	
	/*push data*/
	stutes=push(Stack1,&num5);
	if(stutes==1)printf("%d pushed seccfelly\n",num5);
	
	/*copy and display*/
	displayStackElement(Stack1,&stutes);
	newstutes=copy2(Stack1,Stack2,&stutes);
	displayStackElement(Stack2,&newstutes);
	
	/*StackCount*/
    int counter=StackCount(Stack1,&stutes);
	if(stutes==1) printf("StackCount : %d\n",counter);
	
	/*FindMin*/
	min_number=FindMin(Stack1,&stutes);
	if(stutes==1) printf("min_number:%d\n",*min_number);
	
	/*pop*/
	number=pop(Stack1,&stutes);
	if(stutes==1) printf("%d poped seccfelly\n",*(int*)number);
	number=pop(Stack1,&stutes);
	if(stutes==1)printf("%d poped seccfelly\n",*(int*)number);
	
	/*show what in stacktop*/
	number=stacktop(Stack1,&stutes);
	if(stutes==1) printf("%d stacktop\n",*(int*)number);
	
	/*pop*/
	number=pop(Stack1,&stutes);
	if(stutes==1)printf("%d poped seccfelly\n",*(int*)number);
	number=pop(Stack1,&stutes);
	if(stutes==1)printf("%d poped seccfelly\n",*(int*)number);
	
	/*destroy stack*/
	stutes=destroystack(Stack1);
	if(stutes==1) printf("desroied seccfelly\n");
	
	return 0;
}




int menu(stack_t *Stack1 ,stutes_t stutes)
{
	int choise;
	void *number=NULL;
	int *min_number=NULL;
	stutes=S_NOK;
	int num1;
	
	printf("for pushing enter   1: \n");
	printf("for poping enter    2: \n");
	printf("for stacktop enter  3: \n");
	printf("for find min enter  4: \n");
	printf("for back enter      5: \n");
	printf("for exit enter      6: \n");
	scanf("%d",&choise);
	switch(choise)
	{
		
		case 1:
				printf("enter num to push:");
				scanf("%d",&num1);
				stutes=push(Stack1,&num1);
				if(stutes==1)printf("%d pushed seccfelly\n",num1);
				if(stutes==3)
				{
					printf("stack full !!!!!!!!!!!\n");
					
				}
				break;
		case 2:
				number=pop(Stack1,&stutes);
				if(stutes==1) printf("%d poped seccfelly\n",*(int*)number);
				if(stutes==2)
				{
					printf("stack empty !!!!!!!!!!!\n");
					
				}
				break;
		case 3:
				number=stacktop(Stack1,&stutes);
				if(stutes==1) printf("%d stacktop\n",*(int*)number);
				if(stutes==2)
				{
					printf("stack empty !!!!!!!!!!!\n");
					
				}
				break;
		case 4:
				min_number=FindMin(Stack1,&stutes);
				printf("Stack1_Status = %i \n",stutes);
				if(stutes==1) printf("min_number:%d\n",*min_number);
				if(stutes==2)
				{
					printf("stack empty !!!!!!!!!!!\n");
					
				}
				break;
		case 5:
				break;
		default:
				return 0;
		
	}
	printf("for menu again enter 1: \n");
	scanf("%d",&choise);
	if(choise==0)
		menu(Stack1 ,stutes); 
}

//gcc main.c stack1.c -o task1.exe