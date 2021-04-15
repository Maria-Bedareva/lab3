#include "List.hpp"

void List::add(Book *book)
{
    	if (head == nullptr)
    	{
        	head = new Node{book, nullptr};
    	}
    	else
    	{
        	Node *temp = head;
        	while (nullptr != temp->next)
        	{
            		temp = temp->next;
        	}
        	temp->next = new Node{book, nullptr};
    	}
    	++size;
}
void List::remove(Book *book)
{
    	if (size == 0)
    	{
        	// удалять нечего
    	}
    	else if (head->book == book)
    	{
        	Node *temp = head;
        	head = temp->next;
        	delete temp;
        	--size;
    	}
    	else
    	{
        	Node *temp = head;
        	while (temp->next != nullptr && temp->next->book != book)
        	{
            		temp = temp->next;
        	}
        	if (temp == nullptr)
        	{
            		// не нашлось такого
			return;
        	}
        	Node *toRemove = temp->next;
        	temp->next = toRemove->next;
        	delete toRemove;
        	--size;
    	}
}
Book *List::operator[](int i)
{
    	if (i >= 0 && i < size)
    	{
        	Node *temp = head;
        	while (temp != nullptr && i != 0)
        	{
            		--i;
            		temp = temp->next;
        	}
        	return temp->book;
    	}
    	return nullptr;
}
Book *List::searchByName(const std::string &name)
{
    	Node *temp = head;
    	while (temp != nullptr && temp->book->getName() != name)
    	{
        	temp = temp->next;
    	}
    	if (temp != nullptr)
    	{
        	return temp->book;
    	}
    	return nullptr;
}
Book *List::searchByAuthor(const std::string &author)
{
    	Node *temp = head;
    	while (temp != nullptr && temp->book->getAuthor() != author)
    	{
        	temp = temp->next;
    	}
    	if (temp != nullptr)
    	{
        	return temp->book;
    	}
    	return nullptr;
}
Book *List::searchByPrice(const float price)
{
    	Node *temp = head;
    	while (temp != nullptr && temp->book->getPrice() != price)
    	{
        	temp = temp->next;
    	}
    	if (temp != nullptr)
    	{
        	return temp->book;
    	}
    	return nullptr;
}
Book *List::searchByQuantity(const unsigned quantity)
{
    	Node *temp = head;
    	while (temp != nullptr && temp->book->getQuantity() != quantity)
    	{
        	temp = temp->next;
    	}
    	if (temp != nullptr)
    	{
        	return temp->book;
    	}
    	return nullptr;
}

List::~List()
{
    	Node *temp = head;
    	Node *prev;
    	while (temp != nullptr)
    	{
        	prev = temp;
        	temp = temp->next;
        	delete prev;
    	}
}

List::Node::~Node()
{
    	delete book;
    	book = nullptr;
    	next = nullptr;
}
unsigned int List::getSize() const
{
    	return size;
}
