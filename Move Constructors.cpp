// Move Constructors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
class Item {
public:
    std::string sItemName;
    int* iItemPrice;
   
    Item(std::string sInit, int iInit)
        :sItemName(sInit)
    {
        iItemPrice = new int;
        *iItemPrice = iInit;
        std::cout << "Regular constructor called to create " << sItemName << "\n";
    }

    Item(const Item& objItem)
        :Item(objItem.sItemName, *objItem.iItemPrice)
    {
        std::cout << "Copy Constructor called\n";
    }

    Item(Item&& data) noexcept
        :iItemPrice(data.iItemPrice)
    {
        data.iItemPrice = nullptr;
        std::cout << "Move constructor being called\n";
    }

    ~Item() 
    {
        std::cout << "Destructor called for " << sItemName << "\n";
        delete iItemPrice;
    }
};
int main()
{
    std::vector<Item>vecItems;
    Item Mic("Mic", 100);
    Item* Test = new Item("Test", 3);

    vecItems.push_back(Mic);
   vecItems.push_back(*Test);
    delete Test;
   
}