#include "Shop.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Нет аргумента!\n";
        	return 0;
    	}
    	Shop shop;
    	if (false == shop.loadFromFile(argv[1]))
    	{
        	std::cout << "Файл не был успешно открыт\n";
        	return 0;
    	}
    	shop.menu();
    	if (false == shop.saveToFile(argv[1]))
    	{
        	std::cout << "Файл не был успешно сохранен\n";
    	}
    	return 0;
}
