#include<stdio.h>
#include<stdlib.h>
#include"shop.h"
shop* deleted(shop *head)
{
    	shop *dop;
    	dop=head->next;
    	free(head->name);
    	free(head->author);
    	free(head);
	return dop;
}
