#include "List.hpp"

class Shop
{
public:
    	bool loadFromFile(const std::string &filename);
    	void menu();
    	bool saveToFile(const std::string &filename);

private:
    	List books;
};
