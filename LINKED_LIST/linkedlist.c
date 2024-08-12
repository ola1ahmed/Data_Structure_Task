#include "linkedlist.h"


linkedlist_t *createlist(stutes_t *stutes){
	*stutes=LL_NOK;
	linkedlist_t *mylist=(linkedlist_t*)malloc(sizeof(linkedlist_t));
	if(mylist!=NULL){
		mylist->Head=NULL;
		mylist->size=0;
		*stutes=LL_OK;
	}
	return mylist;
}
stutes_t destroylist(linkedlist_t *mylist){
	stutes_t stutes=LL_NOK;
	listnode_t *temp=NULL;
	if(mylist!=NULL){
		while((mylist->Head)!=NULL)
		{
			temp=mylist->Head;
			mylist->Head=mylist->Head->next;
			free(temp);
		}
		free(mylist);
		stutes=LL_OK;
	}
	return stutes;
}
stutes_t insertnode(linkedlist_t *mylist,EntryType itemptr,uint32 pos){
	stutes_t stutes=LL_NOK;
	listnode_t *temp=NULL;
	if(mylist!=NULL && pos <= mylist->size)
	{
		listnode_t *node=(listnode_t*)malloc(sizeof(listnode_t));
		if(node!=NULL){
			node->input=itemptr;
			node->next=NULL;
			if(pos==0)
			{
				node->next=mylist->Head;
				mylist->Head=node;
			}
			else
			{
				temp=mylist->Head;
				for(uint32 i=0;i<pos-1;i++)
				{
					temp=temp->next;
				}
				node->next=temp->next;
				temp->next=node;
			}
			stutes=LL_OK;
			mylist->size++;
			
		}
	}
	return stutes;
}
stutes_t deletenode(linkedlist_t *mylist,uint32 pos){
	stutes_t stutes=LL_NOK;
	listnode_t *temp=NULL;
	listnode_t *current=NULL;
	if(mylist!=NULL && pos < mylist->size)
	{
		temp=mylist->Head;
		if(pos==0)
		{
			free(temp);
			mylist->Head=NULL;		
		}
		else
		{
			for(uint32 i=0;i<pos-1;i++)
			{
				 temp = temp->next;
            }
            current = temp->next;
            temp->next = current->next;
            free(current);
			}
		stutes=LL_OK;
		mylist->size--;	
				
	}
	return stutes;
}
stutes_t traverse(linkedlist_t *mylist,void  (*func)(EntryType*)){
	stutes_t stutes=LL_NOK;
	listnode_t *temp=NULL;
	if(mylist!=NULL )
	{
		temp=mylist->Head;
		while(temp!=NULL)
		{
			func(temp->input);
			temp=temp->next;
		}
		stutes=LL_OK;
	}
	
	return stutes;
}
stutes_t reverse(linkedlist_t *mylist){
	stutes_t stutes=LL_NOK;
	listnode_t *prev=NULL;
	listnode_t *current=NULL;
	
	if(mylist!=NULL){
		while (mylist->Head != NULL)
		{
			current=mylist->Head->next;
			mylist->Head->next=prev;
			prev=mylist->Head;
			mylist->Head=current;
		}
		mylist->Head=prev;
		stutes=LL_OK;
	}
	return stutes;
}
int middel(linkedlist_t *mylist){
	if (mylist == NULL || mylist->Head == NULL) 
	{
        return -1;  
    }
    listnode_t *temp = mylist->Head; 
	int pos;
	if(mylist->size==1)
	{
		return mylist->Head->input;
	}
	else
	{
		if(mylist->size %2==0)
		{
			pos=(mylist->size )/2 ;
		}
		else
		{
			pos=(mylist->size )/2 +1 ;
		}
		
		for(uint32 i=0;i<pos-1;i++)
		{
			 temp = temp->next;
		}
		return temp->input;
	}
}
int findsum(linkedlist_t *mylist){
	if (mylist == NULL || mylist->Head == NULL) 
	{
        return -1;  
    }
	int sum = mylist->Head->input;
    listnode_t *temp = mylist->Head->next; 

    while (temp != NULL)
	{
        sum+=temp->input;
        temp = temp->next;
    }

    return sum;
}

int findmax(linkedlist_t *mylist){
	if (mylist == NULL || mylist->Head == NULL) 
	{
        return -1;  
    }
	int max = mylist->Head->input;
    listnode_t *temp = mylist->Head->next; 

    while (temp != NULL)
	{
        if (temp->input > max) 
		{
            max = temp->input;
        }
        temp = temp->next;
    }
    return max;
}


stutes_t deletenode2(linkedlist_t *mylist, int (*func)(listnode_t *)) {
    if (mylist == NULL || mylist->Head == NULL) 
	{
        return LL_NOK; 
    }

    listnode_t *temp = mylist->Head;
    listnode_t *prev = NULL;
    stutes_t stutes = NODE_NOTFOUND;

    while (temp != NULL) 
	{
        if (func(temp) != -1) 
		{
            if (prev==NULL) 
			{
   			   mylist->Head = temp->next;
            }			
			else 
			{
                prev->next = temp->next;
            }
            free(temp);
            mylist->size--;
            stutes = LL_OK;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return stutes;
}