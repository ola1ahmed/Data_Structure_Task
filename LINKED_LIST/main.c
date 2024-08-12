#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
void printEntry(EntryType *entry) {
    if (entry != NULL) 
	{
        printf("Data: 0x%x\n", entry);
    }
}

int findnum(listnode_t *temp){
	if(temp->input==0x33)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}



int main(){
	int mid;
	int max_ele;
	int sum;
	EntryType num1=0x11,num2=0x22,num3=0x33,num4=0x44,num5=0x55,num6=0x66;
	stutes_t stutes=LL_NOK;
	linkedlist_t* mylist=createlist(&stutes);
	if(stutes==1) printf("created succssfully\n");
	stutes=insertnode(mylist,num1,0);
	stutes=insertnode(mylist,num2,1);
	stutes=insertnode(mylist,num3,2);
	stutes=insertnode(mylist,num4,3);
	stutes=insertnode(mylist,num5,4);
	stutes=insertnode(mylist,num6,4);
	stutes=insertnode(mylist,num6,3);
	stutes=traverse(mylist, printEntry);
	printf("------------------------\n");
	stutes=reverse(mylist);
	stutes=traverse(mylist, printEntry);
	printf("------------------------\n");
	stutes=deletenode2(mylist,findnum);
	printf("stutes->%d\n",stutes);
	printf("------------------------\n");
	stutes=traverse(mylist, printEntry);
	printf("------------------------\n");
	mid=middel(mylist);
	printf("mid: 0x%x\n", mid);
	
	stutes=deletenode(mylist,1);
	stutes=traverse(mylist, printEntry);
	printf("------------------------\n");
	mid=middel(mylist);
	printf("mid: 0x%x\n", mid);
	
	sum=findsum(mylist);
	printf("sum: 0x%x\n", sum);
	
	max_ele=findmax(mylist);
	printf("max_ele: 0x%x\n", max_ele);
	
	stutes=deletenode(mylist,1);
	
	
	stutes=destroylist(mylist);
	if(stutes==1) printf("destroied succssfully\n");
	return 0;
}