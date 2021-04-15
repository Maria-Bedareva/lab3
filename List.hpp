#include "Book.hpp"

class List
{
public:
    	void add(Book *book);
    	void remove(Book *book);
    	Book *operator[](int i);
    	Book *searchByName(const std::string &name);
    	Book *searchByAuthor(const std::string &name);
    	Book *searchByPrice(const float price);
    	Book *searchByQuantity(const unsigned quantity);
    	unsigned int getSize() const;

    	~List();

    	struct Node
    	{
        	Book *book;
        	Node *next;
        	~Node();
    	};

private:
    	Node *head{nullptr};
    	unsigned int size{0};
};
