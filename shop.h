#include <stdio.h>
typedef struct shop {
	char* name;
	char* author;
	float price;
	int quartity;
	struct shop* next;
} shop;
shop* deleted(shop *head);
shop *book(shop * head);
shop *search(char *str, shop *head);
shop* read();
char* read_b (FILE *f, char *a);
void edit(shop *head);
char* input();
void write (shop *head, char * filename);
void menu();
