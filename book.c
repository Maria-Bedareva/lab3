#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shop.h"
shop *book(shop *head) {
	shop *books=(shop*)malloc(sizeof(shop));
	printf("Введите название книги:\n");
	books->name=input();
	printf("Введите имя автора:\n");
	books->author=input();
	printf("Введите цену:\n");
	scanf("%f",&books->price);
        getchar();
	printf("Введите количество книг в наличии:\n");
	scanf("%d",&books->quartity);
	books->next=head;
	return books;
}
