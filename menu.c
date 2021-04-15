#include <stdio.h>
#include "shop.h"

void menu(char * filename) {
	shop *head=NULL;
	shop *help;
	shop *help1;
	int c;
	head=read(filename);
	do {
		printf("\nКнижный магазин 'Читайна'\nВыбирете действие:\n1. Найти и вывести информацию о книге\n2. Добавить книгу\n3. Удалить книгу\n4. Редактировать название книги\n5. Выход\n\n");
		scanf("%d", &c);
		getchar();
		switch(c) {
			case 1:
				help=head;
				if(help==NULL){
					printf("Книг ещё нет\n");
					break;
				}
				printf("Введите название книги: ");
				help=search(input(),help);
				if(help==NULL){
					printf("Такой книги нет\n");
					break;
				}
				printf("Название: %s\n\nАвтор: %s\n\nЦена: %f\n\nКоличество на складе: %d\n\n",help->name,help->author,help->price,help->quartity);
                                        help=help->next;

			break;
			case 2:
				head=book(head);
			break;
			case 3:
				help=head;
				help1=head;
				if(help==NULL){
					printf("Книг ещё нет\n");
					break;
				}
				printf("Введите название книги: ");
				help=search(input(),help);
				if(help==NULL){
					printf("Такой книги нет\n");
					break;
				}
				if(help==head)
					head=deleted(help);
				else{
					while(1){
						if(help1->next==help)
							break;
						else help1=help1->next;
					}
					help1->next=deleted(help);
				}
			break;
			case 4:
				help=head;
				if(help==NULL){
					printf("Книг ещё нет\n");
					break;
				}
				printf("Введите название книги: ");
				help=search(input(),help);
				if(help==NULL){
					printf("Такой книги нет\n");
					break;
				}
				edit(help);
			break;
			case 5:
				write(head, filename);
				printf("\nДо новых встреч!\n");
			break;
			default:
				printf("Данной команды не существует\n");
			break;
		}
	}
	while(c!=5);
}

