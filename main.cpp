//YOU GOT THIS OK!!
//Miguel Salvador | Program #1 | October 8, 2025
//This is the main file where I will create the children

#include "MerchList.h"
using namespace std;

int main() {

    cout << " hello " << endl;

    //Vendor a_vendor("Miguel", "Academic Weapon", 10);//Argument constructor works 
    //bool first = a_vendor.compare_title("Miguel");
    
    Merch art1("Miguel", "restaurant", 10 , "Poster", .8, 5);
    Merch  art2("Chris", "taco truck", 20, "Shirt", .5 , 10);
    Merch  art3("Tammy", "sky truck", 30, "Pants", .7 , 15);
    Merch  art4("Guilly", "sky truck", 40, "Socks", .2, 15);
    C_list CLL;

    CLL.enqueue(art1);
    CLL.enqueue(art2);
    CLL.enqueue(art3);
    CLL.enqueue(art4);
    
    Merch art9;
    CLL.peek(art9);
    CLL.peek(art4);
    art9.display();
    art4.display();



//    CLL.display();


    return 0;
}


