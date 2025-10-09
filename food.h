//Food sub-class Vector
//Miguel Salvador | Program #1 | October 8, 2025
//This declares the Food class which derives the parent Vendor, it's unique data members are
// dish_name, type_food, and calories. The methods will allow the user to order food,
//will recommend the customers a tip, and will calculate the total.
#pragma once

#include "vendor.h"
#include <string>

class Food:public Vendor {
    
    public:
    Food();//default constructor
    Food(const char* a_title, const string & a_description, int a_price,
    const string & a_dish_name, const string & a_type_food, int calories); //argument constructor
    //Food( const Food & a_food); //copy constructor// You don't need copy constructor since you don't have
                                                    //dynamic memory. The base class handles its own data members
    //Food& operator=(const Food & a_food);//assignment operator //You don't need assignment operated
                                                                 //since you don't have dynamic memory
    ~Food();

    //This will take in the # of orders of the food the specific vendor offers and 
    //calculate the total
    int order_food(int quantity);
    //This would calculate the recommended tip percentageto leave based on how many
    //orders were purchased
    int recommend_tip(int quantity);
    //This would take in the tip the customer chose and calculate the total tip based
    //on how much the food cost * the tip percentage.
    int leave_tip( int tip_percent, int sub_total);

    protected:

    private:
    string dish_name;
    string type_food;
    int calories;

};
