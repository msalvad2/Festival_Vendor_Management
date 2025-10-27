//YOU GOT THIS OK!!
//Miguel Salvador | Program #1 | October 8, 2025
//This is the main file where I will create the children

#include "MerchList.h"
#include "ArtistList.h"
#include "food.h"
#include <algorithm>
#include <vector> //STL library will give me access to the vectors

using namespace std;
//This function will check if the number the user provided is valid
int num_check(int low, int high, int & num) {
    while(num > high || num < low) {
        cout <<"Please choose a number between " << low << " - " << high << endl;
        cout << "Choice: ";
        cin >> num;
        cin.ignore(100, '\n');
    }
    return num;
}
//This will ask the user if they want to work with the list or the data members of the class (e.g Artist)
int list_or_node(int & num, string & name) {
    cout <<"Do you want to work with: " << endl;
    cout << " 1. " << name << "List functions" << endl <<
        " 2. " << name << "Node functions " << endl;
    cout << "Choice: ";
    cin >> num;
    num_check(1, 2, num);

    return num;
}

int main() {
    
    //Predefined class data types user will work with
    Artist artist("Bad Bunny", "Cool guy", 10, 2, "Un Verano Sin Ti", 5);
    Merch merch("Shirts", "Comfy and Flexible", 10,"Clothing",  .8, 60);
    Food food("Salvo's Restaurant", "Tasty & Friendly" , 2, "Bob", "Tacos", 100);
    //Created empty list the user can add and remove from
    List ArtistList;
    C_list MerchList;
    vector <Food> FoodList;

    int choice{0};

    cout <<"What would you like to work with: " << endl;
    cout <<"1). Artist (LLL)| 2. Merch (CLL)| 3. Food (Vector)" << endl;
    cout << "Choice: ";
    cin >> choice;
    cin.ignore(100, '\n');
    num_check(1, 3, choice);

    //Work with the artist
    if(choice == 1) {
        string name = "Artist's ";
        int num{0};
        list_or_node(num, name);
        //This will work with the Artist's List functions;

        if(num == 1) {

            char option;

            do{ cout <<"a). Insert Artist b). Remove Artist c). Find Artist " <<
                "d).Display all artists e). Remove all arists q).Quit" << endl;
                cin>> option;
                cin.ignore(100, '\n');

                switch(option) 
                {
                    //Adds artist to the beginning of the list
                    case 'a': {
                                  char name[100];
                                  string description;
                                  int price{0};
                                  int duration{0};
                                  char album[100];
                                  int popularity{0};

                                  cout <<"Title: ";
                                  cin.get(name, 100, '\n');
                                  cin.ignore(100, '\n');

                                  cout << "Description: ";
                                  getline(cin, description);

                                  cout << "Price(10-30): ";
                                  cin >> price;
                                  cin.ignore(100, '\n');

                                  cout << "Duration (1-4) : ";
                                  cin>> duration;
                                  cin.ignore(100, '\n');

                                  cout << "Album: ";
                                  cin.get(album, 100, '\n');
                                  cin.ignore(100, '\n');

                                  cout << "Popularity (1-10)";
                                  cin  >>popularity;
                                  cin.ignore(100, '\n');

                                  Artist a_artist(name, description, price, duration, album, popularity);
                                  ArtistList.insert(a_artist);


                              }
                              break;
                              //Removes an artist using the title
                    case 'b': {
                                  char name[100];
                                  cout << "The Artist Name: ";
                                  cin.get(name, 100, '\n');
                                  cin.ignore(100, '\n');

                                  ArtistList.remove_title(name);

                              }
                              break;
                              //finda an artist then displays information if found was succesful
                    case 'c': {
                        
                                  char name[100];
                                  cout << "The Artist Name: ";
                                  cin.get(name, 100, '\n');
                                  cin.ignore(100, '\n');

                                  Artist found_artist;

                                  ArtistList.find(name, found_artist);

                                  cout << "The artist found: " << endl;
                                  found_artist.display();

                              }
                              break;
                            //Displays all artist in the list
                    case 'd': {
                                  ArtistList.display();

                              }
                              break;
                    case 'e': {
                        int num = ArtistList.remove_all();
                        if(num == 1)
                            cout << "Successfully remove all Artists! " << endl;
                    }

                }

            }while(option != 'q');

            //This will work with the Artist Nodes functions

        }
        else {

            char option;
            do{ cout << "a). Request song b). Meet and Greet Artist c.) Album Announcement d.) Display Artist Info q).Quit" << endl << "Choice: ";
                cin >>option;
                cin.ignore(100, '\n');
                switch(option) {
                    // This will let the user request then calculate how much it is
                    case 'a': {
                                  string song;
                                  int money;
                                  cout << "Song request: "; 
                                  getline(cin, song);

                                  float cost = artist.Artist::display_cost(true);
                                  cout << "The price is: " << cost << " dollars " << endl;

                                  cout << "How much are you paying with: ";
                                  cin >> money;
                                  cin.ignore(100, '\n');

                                  artist.request_song(song, money);

                              }
                              break;
                    //This will allow the user to meet and greet the artist it will calculate costs
                    case 'b': {
                                  float price{0};
                                  int money{0};

                                  price = artist.Artist::display_cost(false);

                                  cout << "The meet and greet is: " << price << endl;
                                  cout << "How much are you paying with: ";
                                  cin >> money;
                                  cin.ignore(100, '\n');

                                  artist.meet_greet(money);
                              }
                              break;
                            //T 
                    case 'c': {
                                  artist.album_announcement();
                              }
                              break;

                    case 'd': {
                                  artist.display();

                              }
                              break;

                }//switch



            }while(option != 'q');



        }
    }

    /////////////////////////////////////////////////////////////////////////////////
    //Work with Merch
    else if(choice == 2) {
        string name = "Merch's ";
        char option;
        int num{0};

        list_or_node(num, name);

        if(num == 1) {
            do{ cout <<"a). Insert Merch  (Enqueue) b). Remove Merch (Dequeue) c). Find Merch " <<
                "d).Display all Merch  e). Peek f). Remove all Merch g). Remove by title q).Quit" << endl;
                cin>> option;
                cin.ignore(100, '\n');

                switch(option) {
                    case 'a': {
                                  char name[100];
                                  string description;
                                  int price{0};
                                  string merch_type;
                                  int discount{0};
                                  float a_discount{0.0};
                                  int stock{0};

                                  cout <<"Title: ";
                                  cin.get(name, 100, '\n');
                                  cin.ignore(100, '\n');

                                  cout << "Description: ";
                                  getline(cin, description);

                                  cout << "Price(10-30): ";
                                  cin >> price;
                                  cin.ignore(100, '\n');

                                  cout << "Merch_type(e.g. Clothing, posters etc.)  : ";
                                  getline(cin, merch_type);

                                  cout << "Discount (1-100) : ";
                                  cin >> discount;
                                  cin.ignore(100, '\n');
                                  a_discount = 1 - ( discount/100);

                                  cout << "Stock (num): ";
                                  cin  >> stock;
                                  cin.ignore(100, '\n');

                                  Merch a_merch(name, description, price, merch_type, a_discount, stock);
                                  MerchList.enqueue(a_merch);
                              }
                              break;
                    case 'b': {

                                  Merch deleted_merch;
                                  int num = MerchList.dequeue(deleted_merch);
                                  if(num != -1)
                                      cout << "The merch  you deleted: " << endl;

                                  deleted_merch.display();
                              }
                              break;

                    case 'c': {

                                  char name[100]; 
                                  cout << "Merch Name: ";
                                  cin.get(name, 100, '\n');
                                  cin.ignore(100, '\n');

                                  Merch found_merch;

                                  bool flag = MerchList.find_match(name, found_merch);
                                  if(flag)  {
                                      cout << "The Merch founds is: " << endl;

                                  }
                                  found_merch.display();


                              }
                              break;
                    case 'd': {
                                  MerchList.display();

                              }
                              break;
                    case 'e': {
                                  Merch peeked_merch;
                                  int num = MerchList.peek(peeked_merch);
                                  if(num != -1)
                                      cout << "The merch peeked: " << endl;

                                  peeked_merch.display();
                    }
                    case 'f': {
                                int num = MerchList.remove_all();
                                if(num == 1) 
                                    cout <<"Successfully removed all merch" << endl;

                              }
                    break;

                    case 'g': {

                            char name[100];

                            cout << "Name of merch: ";
                            cin.get(name, 100, '\n');

                            MerchList.remove_by_title(name);
                    }
                    break;


                }//switch
            }while(option != 'q');

        }
        else{
            char option;
            do{ cout << "a). Buy merch  b). Check Availability c.) Sell to booth  d.) Display Merch Info q).Quit" << endl << "Choice: ";
                cin >>option;
                cin.ignore(100, '\n');
                switch(option) {

                    case 'a': {
                                  int num{0};
                                  float cost{0};
                                  int money{0};

                                  cout << "How many " << merch.Vendor::display_title() << " would you like to purchase " << endl;
                                  cout << "Quantity: ";
                                  cin >> num;
                                  cin.ignore(100, '\n');

                                  cost = merch.Vendor::display_cost(num);

                                  cout <<"The cost for the " << merch.display_title() << " is : " << cost << endl;
                                  cout << "How much are you paying with: ";

                                  cin >> money;
                                  cin.ignore(100, '\n');

                                  merch.buy_merch( num, money);


                              }
                              break;
                    case 'b': {
                                  merch.check_availability();
                              }
                              break;

                    case 'c': {
                                  int quantity{0};

                                  cout << "How many " << merch.display_title() << " would you like to sell: ";
                                  cin >> quantity;
                                  cin.ignore(100, '\n');

                                  merch.sell_to_booth(quantity);

                              }
                              break;

                    case 'd': {
                                  merch.display();

                              }
                              break;
                }

            }while(option != 'q');

        }//else
    }//elseif main
     /////////////////////////////////////////////////////////////////////////////////////
     //Work with the Food
    else {
        string name = " Food's ";
        char option;
        int num{0};

        list_or_node(num, name);
        if(num == 1) {

            do{ cout <<"a). Insert Food  b). Remove Last Food  c). Remove all Foods " <<
                "d).Display all Foods  q).Quit" << endl;
                cin>> option;
                cin.ignore(100, '\n');

                switch(option) {
                    case 'a': {
                                  char name[100];
                                  string description;
                                  int price{0};
                                  string waiter_name;
                                  string type_food;
                                  int calories{0};

                                  cout <<"Title: ";
                                  cin.get(name, 100, '\n');
                                  cin.ignore(100, '\n');

                                  cout << "Description: ";
                                  getline(cin, description);

                                  cout << "Price(10-30): ";
                                  cin >> price;
                                  cin.ignore(100, '\n');

                                  cout << "Waiter Name  : ";
                                  getline(cin, waiter_name);

                                  cout << "Type of Food : ";
                                  getline(cin, type_food);

                                  cout << "Calories (num): ";
                                  cin  >> calories;
                                  cin.ignore(100, '\n');

                                  Food a_food(name, description, price, waiter_name, type_food, calories);
                                  FoodList.push_back(a_food);//This will add at end of list
                                  //Efficiency is O(1) on average
                              }
                    break;
                    case 'b': {
                                FoodList.pop_back();

                    }
                    case 'c': {
                        FoodList.clear();
                        }
                    break;
                    
                    case 'd': {
                        
                        int length = FoodList.size();

                        for(int i = 0; i < length; ++i) {
                            
                            FoodList[i].display();

                        }

                    }
                    break;

}
            }while(option != 'q');


        }//ifchoice
        else {
            char option;
            do{ cout << "a). Order Food -> Recommend Tip -> Calculate Total b.) Display Merch Food q).Quit" << endl << "Choice: ";
                cin >>option;
                cin.ignore(100, '\n');
                switch(option) {

                    case 'a': {
                                  int num{0};
                                  float cost{0};
                                  float actual_tip{0};

                                  cout << "How many Tacos would you like to order " << endl;
                                  cout << "Quantity: ";
                                  cin >> num;
                                  cin.ignore(100, '\n');

                                  cost = food.Vendor::display_cost(num);

                                  cout <<"The cost for the Tacos is : " << cost << endl;
                                  
                                  actual_tip = food.recommend_tip(num);


                                  food.total(actual_tip, cost);


                                  


                              }
                              break;
                    case 'b': {

                               food.display(); 

                              } 
                              break;
                }
            }while(option != 'q');

        }//lil else
    }//main else


    return 0;
}


