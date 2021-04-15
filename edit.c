#include <stdio.h>
#include <stdlib.h>
#include "shop.h"
void edit(shop *head) {
	int ch;
    	do {
	        printf("Выберете ,что нужно отредактировать:\n1. Редатировать название книги\n2. Редактировать имя автора\n3. Редактировать цену\n4. Редактировать количество товара в наличии\n5. Выход из режима редактирования\n");
        	scanf("%d",&ch);
	        getchar();
        	switch(ch){
			case 1:
				free(head->name);
				printf("Введите новый название книги: ");
				head->name=input();
			break;
			case 2:
				free(head->author);
				printf("Введите новое имя автора: ");
				head->author=input();
			break;
			case 3:
				printf("Введите новую цену: ");
				scanf("%f",&head->price);
			break;
			case 4:
				printf("Введите новое количество товаров в наличии: ");
				scanf("%d",&head->quartity);
			break;
			case 5:
			break;
			default:
				printf("Данной команды не существуют\n");
			break;
	        }
    	}
	while(ch !=5);
}
