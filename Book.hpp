#include <string>
#include <iostream>

class Book
{
public:
   	friend std::ostream &operator<<(std::ostream &out, const Book &book);
   	friend std::istream &operator>>(std::istream &in, Book &book);

    	std::string getName() const;
    	std::string getAuthor() const;
    	float getPrice() const;
    	unsigned int getQuantity() const;

    	void setName(std::string newName);
    	void setAuthor(std::string newAuthor);
    	void setPrice(float newPrice);
    	void setQuantity(unsigned int newQuantity);

private:
    	std::string name;
    	std::string author;
    	float price;
    	unsigned int quantity;
};
