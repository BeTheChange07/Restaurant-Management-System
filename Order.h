

#include "Menu.h"

// const int MAX_ITEMS_IN_ORDER = 100;

class Order
{
public:
    Order();
    // "A1 A2 B1"
    Order(string OrderString, Menu* menup);
   // void addItems(string OrderString, Menu* menup);
    void printReceipt(int addedItemCount, int ttableNum,int partySize);
    virtual ~Order();

    string getName();
    string getCode();
    double getPrice();

protected:

private:
    static const int MAX_ITEMS_IN_ORDER = 100;
    int numItems = 0;
    MenuItem* items[MAX_ITEMS_IN_ORDER];
};

