#include "Menu.h"

Menu::Menu(ifstream& inFile)
{
	string codeOfItem = "", nameOfItem = "";
	double priceOfItem = 0;
    string temp;
    inFile >> numItems;
    getline(inFile, temp);


	
	for (int i = 0; i < numItems; i++)
	{
		inFile >> codeOfItem >> nameOfItem >> priceOfItem;

		items[i] = new MenuItem(codeOfItem, nameOfItem, priceOfItem);
	}

	

}

Menu::~Menu()
{
    //dtor
}

MenuItem* Menu::getMenuItem(string menuItem) {

	for (int i = 0; i < numItems; i++)
	{
		string temp = "";
		temp = items[i]->getCode();
		if (menuItem == temp)
		{
			/*///////////////////////////////////////////////////////////test

		cout << items[i]->getCode() << " " << items[i]->getName() << " " << items[i]->getPrice() << endl;
	

	////////////////////////////////////////////////////////////*///
		MenuItem* item = items[i];
		return item;
		}
			
	}

	
	
}


bool Menu::findMenuItem(string iitem) {
	bool menuItemFound = false;

	for (int i = 0; i < numItems; i++){
	
		string temp = "";
		temp = items[i]->getCode();

		if (temp == iitem)
			return true;
	}

	return false;
	


}