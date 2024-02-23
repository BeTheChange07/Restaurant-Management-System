
#include "MenuItem.h"

class Menu
{
public:
    Menu(ifstream& finput);
    virtual ~Menu();

    MenuItem* getMenuItem(string menuItem = "");

    bool findMenuItem(string iitem);

protected:

private:
    static const int MAX_ITEMS_ON_MENU = 10000;
    int numItems;
    MenuItem** items = new MenuItem* [MAX_ITEMS_ON_MENU];
};

