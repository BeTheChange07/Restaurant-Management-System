#include "Order.h"

//TABLE status: IDLE --> SEATED --> ORDERED --> SERVED

enum TableStatus { IDLE, SEATED, ORDERED, SERVED };
//                   0     1       2         3

class Table
{
public:
    Table(int ttableId = 0, int ccapacity = 0);
    
    bool seatParty(int numGuests);

    // IDLE / ORDERED / SERVED --> ORDEDED
    void placeOrder(string str, Menu* menup, int ttableNum);
    bool serve(); // ORDERED --> SERVED
    bool cleanup(int ttableNum); // SERVED --> IDLE
    virtual ~Table();

    int getCapacity();
    

protected:

private:
    bool orderedFlag = false;
    int addedItemCount = 0;
    int tableId = 0, capacity = 0;
    int partySize = 0;
    TableStatus status = IDLE; //status = IDLE;
    Order* orderp = new Order [1000];
};

