#include "Book.hpp"
#include <sstream>

std::ostream &operator<<(std::ostream &out, const Book &book)
{
    	out << book.name << std::endl
        	<< book.author << std::endl
        	<< book.price << " " << book.quantity;
    	return out;
}
std::istream &operator>>(std::istream &in, Book &book)
{
    	std::string temp;
    	std::getline(in, temp);
    	book.setName(temp);
    	std::getline(in, temp);
    	book.setAuthor(temp);
    	std::getline(in, temp);
    	std::stringstream priceAndQuantity(temp);

    	float price;
    	unsigned int quantity;
    	priceAndQuantity >> price >> quantity;
    	book.setPrice(price);
    	book.setQuantity(quantity);

    	return in;
}


std::string Book::getName() const
{
    	return name;
}
std::string Book::getAuthor() const
{
    	return author;
}
float Book::getPrice() const
{
    	return price;
}
unsigned int Book::getQuantity() const
{
    	return quantity;
}

void Book::setName(std::string newName)
{
    	name = newName;
}
void Book::setAuthor(std::string newAuthor)
{
    	author = newAuthor;
}
void Book::setPrice(float newPrice)
{
    	price = newPrice;
}
void Book::setQuantity(unsigned int newQuantity)
{
    	quantity = newQuantity;
}
