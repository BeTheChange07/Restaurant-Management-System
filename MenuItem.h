#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>


using namespace std;

class MenuItem
{
public:
    MenuItem();
    MenuItem(string codeOfItem, string nameOfItem, double priceOfItem);

    string getCode();
    string getName();
    double getPrice();

    virtual ~MenuItem();

protected:

private:
    string code = "", name = "";
    double price = 0;
};

