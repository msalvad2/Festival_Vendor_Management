//
//Miguel Salvador | Program #1 | October 8, 2025
//Thsi is the implementation of the Food class,
//Currently it only has the the constructors and destructor
#include "food.h"

Food::Food() : Vendor(), dish_name(""), type_food(""), calories(0)
{}

Food::Food(const char * a_title, const string & a_description, int a_price,
const string & a_dish_name, const string & a_type_food, int a_calories) 
: Vendor(a_title, a_description, a_price),
dish_name(a_dish_name), type_food(a_type_food), calories(a_calories) 
{}

Food::~Food() {
    dish_name = "";
    type_food = "";
    calories = 0;

}   
