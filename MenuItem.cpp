#include "MenuItem.h"

MenuItem::MenuItem()
{
    code = "";
    name = "";
    price = 0;
}

MenuItem::MenuItem(string codeOfItem, string nameOfItem, double priceOfItem)
{
    code = codeOfItem;
    name = nameOfItem;
    price = priceOfItem;
}


string MenuItem::getCode() {
    return code;
}
string MenuItem::getName() {
    return name;
}
double MenuItem::getPrice() {
    return price;
}

MenuItem::~MenuItem()
{
    //dtor
}