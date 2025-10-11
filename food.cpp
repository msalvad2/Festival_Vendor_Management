//
//Miguel Salvador | Program #1 | October 8, 2025
//Thsi is the implementation of the Food class,
//Currently it only has the the constructors and destructor
#include "food.h"

Food::Food() : Vendor(), waiter_name(""), type_food(""), calories(0)
{}

Food::Food(const char * a_title, const string & a_description, int a_price,
const string & a_waiter_name, const string & a_type_food, int a_calories) 
: Vendor(a_title, a_description, a_price),
waiter_name(a_waiter_name), type_food(a_type_food), calories(a_calories) 
{}

Food::~Food() {
    waiter_name = "";
    type_food = "";
    calories = 0;

}   
int Food::display() const {
    Vendor::display();
    cout << "Waiter name: " << waiter_name << endl;
    cout << "Type of food: " << type_food << endl;
    cout << "Calories: " << calories << endl;

    return 1;
}
int Food::order_food(int quantity) {
    cout << " My name is " << waiter_name << " I'll be taking your orders today" << endl;
    float amount = Vendor::charge(10000, quantity);
    int total = 10000 - amount;
    
    cout << "The total for the food is: " << total << endl;

    return total;
}
float Food::recommend_tip(int quantity) {

    if(quantity < 3)
        cout << "Recommended tip: 12 %" << endl;
    else if(quantity > 9)
        cout << "Recommended tip: 24 %" << endl;
    else
        cout << "Recommended tip: 16 %" << endl;
    
    float tip;
    cout << "Tip %";
    cin >> tip;
    cin.ignore(100, '\n');

    return tip/100;
}
float Food::total( float tip_percent, int sub_total) {
    float tip = tip_percent * sub_total;
    float sum = tip + sub_total;
    int payment{0};

    cout << "The total for today will be: " << sum << " dollars" << endl;
    cout << "Payment: ";
    cin >> payment;
    cin.ignore(100, '\n');

    float change = payment - sum;

    cout << "Your total is: " << change << endl;

    return 1;
    




}
