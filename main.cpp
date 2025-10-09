//YOU GOT THIS OK!!
//Miguel Salvador | Program #1 | October 8, 2025
//This is the main file where I will create the children

#include "artist.h"
using namespace std;

int main() {

    cout << " hello " << endl;

    //Vendor a_vendor("Miguel", "Academic Weapon", 10);//Argument constructor works 
    //bool first = a_vendor.compare_title("Miguel");

    Artist a_artist("Jamal", "Studying", 10, 2, "Si veo a tu mama", 5);
    Artist artist2("Miguel", "Studying", 10, 2, "Si veo a tu mama", 5);
    
    artist2.display();
    artist2.meet_greet(1);


    return 0;
}


