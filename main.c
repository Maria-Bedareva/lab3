#include "shop.h"
int main (int argc, char * argv[]) {
        if (argc < 2) {
                printf ("Нет аргумента\n");
		return 1;
	}
        FILE *f;
        if ((f = fopen(argv[1], "r")) == NULL) {
                printf("Такого файла не существует\n");
		return 1;
	}
    menu(argv[1]);
    return 0;
}
  
