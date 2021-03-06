#ifndef LIST_HPP
#define LIST_HPP
#include "Item.hpp"

#define DEFAULT 2

class Item;

class List
{
    private:
        Item **pItem;
        Item **pTemp;
        int capacity;       //index to be used to count the capacity of an array.
        int emptyPos;  //index to be used to know position to be stored in the array.  

    public:
        List();  // creating a list which can hold 4 items. (initial)
       ~List();
       void UserInput(int n);
       void ShowMenu();         
       void AddToList();
       void RemoveFromList();
       void DisplayList();
     
       //friend bool operator==(const Item&, const Item&);
};

#endif
