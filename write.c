#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shop.h"
void write (shop *head, char * filename) {
    	FILE *f;
    	f=fopen(filename,"w");
	while(head !=NULL) {
        	fprintf(f,"%s %s %f %d ",head->name,head->author,head->price,head->quartity);
	        head=deleted(head);
    	}
    	fclose(f);
}
