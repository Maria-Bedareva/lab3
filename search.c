#include <stdio.h>
#include <string.h>
#include "shop.h"
shop *search(char *str,shop *head) {
    while(head !=NULL) {
        if(!strcmp(head->name,str))
        	break;
        else head=head->next;
    }
    return head;
}
