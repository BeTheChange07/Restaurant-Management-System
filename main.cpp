#include "Table.h"

int main()
{

    // read the minu items
    ifstream inFile("config.txt");


    Menu menu(inFile);

    /*//////////////////////////////////////////////////test
    string testTemp;
    while (inFile >> testTemp)
    {
        cout << testTemp;
    }
    // //////////////////////////////////////////////////*/

    // read the tables and the capacity 
    Table** tables;
    int numTables;
    string temp;
    inFile >> numTables;
    getline(inFile, temp);
    tables = new Table * [numTables];


    for (int i = 0; i < numTables; i++)
    {
        int tableId = 0,
            capacity = 0;
        inFile >> tableId >> capacity;
        
        tables[i] = new Table(tableId, capacity);
    }
        
   

    //read the commands and process them!

   // bool seatedFlag = false;
    int tableNum = 0;
    char actionChoice = ' ';

    while (true)
    {
        if (!(cin >> tableNum))
        {
            return 0;
        }

        cin >> actionChoice;

        if (actionChoice == 'P')
        {
            int  guestNum = 0;
            cin >> guestNum;

            int tableMax = tables[tableNum -1]->getCapacity();
            if (guestNum > tableMax)
            {
                cout << "Sorry, max " << tableMax << " seats in Table " << tableNum << "!" << endl;
                continue;
            }

            if (!tables[tableNum -1]->seatParty(guestNum)) {
                cout << "Table " << tableNum << " already occupied!" << endl;
                continue;
            }
            else
            {
                cout << "Party of " << guestNum << " assigned to Table " << tableNum << endl;
                continue;
            }
                

            
            

        }

        if (actionChoice == 'O')
        {
            string order;
            getline(cin, order);

            tables[tableNum -1]->placeOrder(order, &menu, tableNum);

            continue;
        }

        if (actionChoice == 'C')
        {

            if (!(tables[tableNum -1]->cleanup(tableNum)))
            {
                cout << "Food not served for Table " << tableNum << " yet!" << endl;
            }
            
            continue;
                
        }

        if (actionChoice == 'S')
        {
            if (tables[tableNum -1]->serve())
            {
                cout << "Food served in table " << tableNum << endl;
            }
            else
                cout << "Order not placed at Table " << tableNum << " yet!" << endl;

            continue;
        }

    }
  
   





    return 0;
}