//artist sub-child LLL
//Miguel Salvador | Program #1 | October 8, 2025
//This will declare the Artist which represents a children of the vendor. It's data members are //duration, album, and popularity. It also declares the meet_greet, song_playing, request_song
// and dispay().

#pragma once  //sets guards so you don't duplicate definishions when include the same header file

#include "vendor.h"
#include <string>
using namespace std;


class Artist:public Vendor {

    public:
    Artist();//default constructor
    Artist(const char * a_title, const string & a_description, int a_price,
    int a_duration, const char * a_album,  int a_popularity);//argument constructor
    Artist(const Artist & a_artist);//copy constructor
    Artist& operator=(const Artist & a_artist); // assignment operator
    ~Artist();//destructor

    //This function will  request song name
    int request_song(const string & song, int payment);

    //This function will receive the payment from the user and then subract 
    //how much it is to meet the artist  minus payment and return total
    int meet_greet(int payment);
    //This function will give information about the album the artist is promoting
    bool album_announcement() const;
    //display all data members
    int display() const;
    float display_cost(bool flag) const;

    protected:
    
    private:
    int duration;//how long the concert will last
    char * album;//the album name the artist is promoting
    int popularity;//This is a mulitplier that will go up the more popular the artist is
};



