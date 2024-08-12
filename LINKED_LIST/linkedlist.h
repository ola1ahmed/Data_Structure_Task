#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <stdlib.h>
#include "types.h"


#define EntryType uint32
typedef struct listnode{
	EntryType input;
	struct listnode *next;
}listnode_t;
typedef struct linkedlist{
	listnode_t *Head;
	uint32 size;
}linkedlist_t;
typedef enum{
	LL_NOK,
	LL_OK,
	LL_EMPTY,
	LL_NULL,
	NODE_NOTFOUND
}stutes_t;

linkedlist_t *createlist(stutes_t *stutes);
stutes_t destroylist(linkedlist_t *mylist);
stutes_t insertnode(linkedlist_t *mylist,EntryType itemptr,uint32 pos);
stutes_t deletenode(linkedlist_t *mylist,uint32 pos);
stutes_t traverse(linkedlist_t *mylist,void  (*func)(EntryType*));


stutes_t deletenode2(linkedlist_t *mylist, int (*func)(listnode_t *)) ;
stutes_t reverse(linkedlist_t *mylist);
int middel(linkedlist_t *mylist);
int findsum(linkedlist_t *mylist);
int findmax(linkedlist_t *mylist);

#endif