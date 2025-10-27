//
//Miguel Salvador | Program #1 | October 8, 2025
//This will implement the fucntions. It currentluy only has the constructors and destructors
//implemented
#include "merch.h"

//the default constructor
Merch::Merch() : Vendor(), merch_type(""), discount(0), stock(0) {

}
//this is the argument constructor
Merch::Merch( const char * a_title, const string & a_description, int a_price,
const string & a_merch_type, float a_discount, int a_stock) 
    : Vendor(a_title, a_description, a_price), //Call Vendor's argument constructor
    merch_type(a_merch_type), discount(a_discount), stock(a_stock) 
    {}// I don't need to put anything for the body since there is no dynamic memory

//destructor
Merch::~Merch() {
    merch_type = "";
    discount = 0.0;
    stock = 0;

}
//This is the functin that calculates based on quantity and payment
int Merch::buy_merch(int quantity, int payment) {
    if(stock < quantity) {
        cout << "Sorry we only have " << stock << " ";
        Vendor::display_title();
        cout << "Left" << endl;
        return 0;
    }
    int amount = 0;
    if(stock < 50)
        amount = Vendor::charge(payment, quantity * discount);
    else {
        amount =Vendor::charge(payment, quantity);
    }
    if(amount == -1) {
        cout << "Sorry not enough money to make purchase! " << endl;
        return -1;
    }
    stock -= quantity;
    cout << "Thank you for shopping! Your total is: " << amount << endl;

    return amount;
    
}
//This is gonna display all the items
int Merch::display() {
    int num =Vendor::display();
    if(num == -1)
        return -1;

    cout << "Color: " << merch_type << endl;
    cout << "Discount when stock  is 50 or less: " << discount << endl;
    cout << "Current stock : " << stock << endl;
    return 1;

}
//This will show how much items are available and if there is currently a discount
int Merch::check_availability() const {
    if(stock < 50) {
    float num = 100 - (discount * 100);
    cout << "DISCOUNT IS NOW " << num << "%" << endl;
    }
    cout << "We have: " << stock << " ";
    Vendor::display_title();
    return 1;
}
//This will allow the customer to sell to the booth.
float Merch::sell_to_booth(int quantity) {
 
   stock +=quantity;
   float amount = Vendor::charge(10000, quantity * discount);
   float change = 10000 - amount;

   cout << "Thank you your total is: " << change << endl;
    
    return 1;
}
