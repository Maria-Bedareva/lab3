#include <stdio.h>
#include "shop.h"
#include <string.h>
#include <stdlib.h>
char* read_b (FILE *f,char *a) {
	char *b;
	b=(char*)malloc(sizeof(char)*strlen(a)+1);
	strcpy(b,a);
	return b;
}
shop* read (char * filename) {
        FILE *f;
	f=fopen(filename, "r");
	char *k;
	char a[50];
	shop *head=NULL;
	if (f==NULL) return head;
	while (1) {
		shop *tmp;
		k=fgets(a,50,f);
		if(k==0) break;
		tmp=(shop*)malloc(sizeof(shop));
		tmp->name=read_b(f,a);
		fgets(a,50,f);
		tmp->author=read_b(f,a);
		fgets(a,50,f);
		fscanf(f,"%f",&tmp->price);
		fscanf(f,"%d",&tmp->quartity);
		tmp->next=head;
		head=tmp;
	}
	fclose(f);
	return head;
}

