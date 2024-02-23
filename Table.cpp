#include "Table.h"

Table::Table(int ttableId, int ccapacity)
{

    tableId = ttableId;
    capacity = ccapacity;
    partySize = 0;
    status = IDLE;
}



bool Table::seatParty(int numGuests) {

    if (status != IDLE)
    {
        return false;
    }

    status = SEATED;

    partySize = numGuests;


    return true;


}

// IDLE / ORDERED / SERVED --> ORDEDED
void Table::placeOrder(string sstr, Menu* mmenup, int ttableNum)
{

    istringstream istr(sstr);

    string menuItemChoice = "";

    int  nowItemsNum = 0;


    while (true) {

        if (!(istr >> menuItemChoice))
            break;

        if (mmenup->findMenuItem(menuItemChoice))
        {

            orderp[addedItemCount] = Order(menuItemChoice, mmenup);
            nowItemsNum++;
            addedItemCount++;
        }
        else
        {
            cout << "No item with code " << menuItemChoice << endl;
            continue;
        }


    }



    if (!orderedFlag)
    {
        cout << nowItemsNum << " items ordered for Table " << ttableNum << endl;
        status = ORDERED;
        orderedFlag = true;


    }

    else if (orderedFlag)

    {
        cout << nowItemsNum << " additional items ordered for Table " << ttableNum << endl;
        status = ORDERED;
        orderedFlag = true;
    }


}




bool Table::serve() {
    if (status == ORDERED)
    {
        status = SERVED;
        return true;
    }
    else
        return false;


}// ORDERED --> SERVED


bool Table::cleanup(int ttableNum) {
    if (status == SERVED)
    {

        double total = 0;
        cout << "Table " << ttableNum << " is closed. Here is the bill." << endl;

        cout << endl;
        cout << "Receipt Table# " << ttableNum << " Party " << partySize << endl;


        for (int i = 0; i < addedItemCount; i++)
        {

            /*///////////////////////////////////////////////////////////test
            cout << items[i]->getCode() << endl;
            ////////////////////////////////////////////////////////////*/

            Order order = orderp[i];

            string code = order.getCode();
            string name = order.getName();
            double price = order.getPrice();

            /*///////////////////////////////////////////////////////////test
            cout << item->getCode() << endl;
            ////////////////////////////////////////////////////////////*/
            // MenuItem* item = items[i];
            cout << left << code << setw(19) << right << name << setw(7) << fixed << setprecision(2) << price << endl;
            total += price;
        }

        cout << right << setw(21) << "Total" << right << setw(7) << total << endl;



        //orderp->printReceipt(addedItemCount, ttableNum, partySize);
        status = IDLE;
        int partySize = 0;



        orderp = NULL;

        int addedItemCount = 0;

        orderedFlag = false;


        return true;
    }
    else
        return false;
}// SERVED --> IDLE


Table::~Table() {

}

int Table::getCapacity() {
    return capacity;
}