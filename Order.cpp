#include "Order.h"



Order::Order() {
    numItems = 0;
}
Order::Order(string OrderString,  Menu* menup) {

	 
    MenuItem* item = (menup->getMenuItem(OrderString));
   
    

    

    items[numItems] = item;

    

	numItems++;

    /*//////////////////////////////////////////////////////test
    for (int i = 0; i < numItems; i++)
    {
        cout << items[i]->getCode() << " " << items[i]->getName() << " " << items[i]->getPrice() << endl;
    }
    

    ////////////////////////////////////////////////////////*/
}


	

/*void Order::addItems(string OrderString, Menu* menup) {

}*/
void Order::printReceipt(int addedItemCount,int ttableNum,int partySize) {
    /*
    
    double total = 0;
    cout << "Table " << ttableNum << " is closed. Here is the bill." << endl;

    cout << endl;
    cout << "Receipt Table# " << ttableNum << " Party " << partySize << endl;
    cout << setprecision(2);
    
    for (int i = 0; i < addedItemCount; i++)
    { 

        ////////////////////////////////////////////////////////////test
        cout << items[i]->getCode() << endl;
        /////////////////////////////////////////////////////////////

        MenuItem* item = items[i];

        ////////////////////////////////////////////////////////////test
        cout << item->getCode() << endl;
        /////////////////////////////////////////////////////////////
       // MenuItem* item = items[i];
        cout << left << item->getCode() << setw(19) << right << item->getName() << setw(7) << item->getPrice() << endl;
        total += item->getPrice();
    }

    cout << right << setw(21) << "Total" << right << setw(7) << total << endl;
    */
}
Order::~Order() {

}

string Order::getName() {
    MenuItem* item;

    item = items[0];

    return item->getName();
}
string Order::getCode() {
    MenuItem* item;

    item = items[0];

    return item->getCode();

}
double Order::getPrice() {
    MenuItem* item;

    item = items[0];

    return item->getPrice();

}