#include "Shop.hpp"
#include <fstream>
#include <sstream>

bool Shop::loadFromFile(const std::string &filename)
{
    	std::ifstream file(filename);
    	if (false == file.is_open())
    	{
        	std::cout << "Файл на чтение не существует или не был открыт успешно!\n";
        	return false;
    	}
    	Book temp;
    	while (file >> temp)
    	{
        	books.add(new Book(temp));
    	}
    	file.close();
    	return true;
}
void Shop::menu()
{
    	char key;
    	std::string trash;
    	do
    	{
        	std::cout << "------------------------------------\n";
        	std::cout << "Выберите действие:\n"
                	<< "1 - Добавить книгу\n"
                  	<< "2 - Удалить книгу\n"
                  	<< "3 - Найти книгу по Имени\n"
                  	<< "4 - Найти книгу по Автору\n"
                  	<< "5 - Редактировать название книги\n"
                  	<< "6 - Вывести все книги на экран\n"
                  	<< "7 - Выход\n";
        	std::cin >> key;
        	std::getline(std::cin, trash);
        	switch (key)
        	{
        	case '1':
        	{
            		Book *newBook = new Book;
            		std::cout << "Введите ифонмацию о книге в формате:\n"
                      		<< "<название>\n"
                      		<< "<автор>\n"
                      		<< "<цена и количество через пробел>\n Вводите:\n";
            		std::cin >> *newBook;
           		books.add(newBook);
        	}
        	break;
        	case '2':
        	{
            		std::string name;
            		std::cout << "Введите название книги для удаления:\n";
            		std::getline(std::cin, name);
            		Book *book = books.searchByName(name);
            		if (book == nullptr)
            		{
                		std::cout << "Такой книги нет!\n";
            		}
            		else
            		{
                		books.remove(book);
                		std::cout << "Книга удалена!\n";
            		}
        	}
        	break;
        	case '3':
        	{
            		std::string name;
            		std::cout << "Введите название книги для поиска:\n";
            		std::getline(std::cin, name);
            		Book *book = books.searchByName(name);
            		if (book == nullptr)
            		{
                		std::cout << "Такой книги нет!\n";
            		}
            		else
            		{
                	std::cout << "Книга найдена! Полная информация:\n"
                          	<< *book << std::endl;
            		}
        	}
        	break;
        	case '4':
        	{
            		std::string name;
            		std::cout << "Введите автора книги для поиска:\n";
            		std::getline(std::cin, name);
            		Book *book = books.searchByAuthor(name);
            		if (book == nullptr)
            		{
                		std::cout << "Такой книги нет!\n";
            		}
            		else
            		{
                		std::cout << "Книга найдена! Полная информация:\n"
                          		<< *book << std::endl;
            		}
        	}
        	break;
        	case '5':
        	{
            		std::string name;
            		std::cout << "Введите текущее имя книги:\n";
            		std::getline(std::cin, name);
            		Book *book = books.searchByName(name);
            		if (book == nullptr)
            		{
                		std::cout << "Такой книги нет!\n";
            		}
            		else
            		{
                		std::cout << "Введите Новое имя книги:\n";
                		std::getline(std::cin, name);
                		book->setName(name);
            		}
        	}
        	break;

        	case '6':
        	{
            		std::cout << "\nВсего книг: " << books.getSize() << ", список:\n";
            		for (unsigned int i = 0; i < books.getSize(); ++i)
            		{
                	std::cout << "------------------------------------\n";
                	std::cout << *books[i] << std::endl;
            		}
        	}
        	break;

		case '7':
		break;

        	default:
            		std::cout << "Выберите действие от 1 до 7!\n";
            		break;
        	}

    	} while (key != '7');
}
bool Shop::saveToFile(const std::string &filename)
{
    	std::ofstream file(filename);
    	if (false == file.is_open())
    	{
        	std::cout << "Файл на запись не существует или не был открыт успешно!\n";
        	return false;
    	}

    	for (int i = 0; i < books.getSize(); ++i)
    	{
        	file << *books[i] << std::endl;
    	}

    	file.close();
    	return true;
}
