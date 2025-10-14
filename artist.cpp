//Hello This is the artist.cpp
//Miguel Salvador | Program #1 | October 8, 2025
//This is the implementation of the Artist, it has the the constructors, destructor and methosds
//It will handle memory management for the dynamic data member and will call the base classes 
//function as well

#include "artist.h"
#include <string>
#include <cstring>
using namespace std;

Artist::Artist():Vendor(), duration(0), album(nullptr), popularity(0) 
{}
Artist::Artist(const char* a_title, const string & a_description, int a_price,  int a_duration, const char* a_album, int a_popularity)
    : Vendor(a_title, a_description, a_price), duration(0), album(nullptr), popularity(0) {

    if(a_album) {
        album = new char[strlen(a_album) + 1];
        strcpy(album,a_album);
    }
    duration = a_duration;
    popularity = a_popularity;

}
//I am passing in a object a_artist, then I am initializing the local variables to their zero equivalence
Artist::Artist(const Artist & a_artist) : Vendor(a_artist), duration(0), album(nullptr), popularity(0) {
   
   //This will perform a deep copy if a_artist.album is not nullptr
    if(a_artist.album) {
        album = new char[strlen(a_artist.album) + 1];
        strcpy(album, a_artist.album);
    }
    duration = a_artist.duration;
    popularity = a_artist.popularity;//This->seat = a_artist.seat; this is always being used when 
                        //just using the local variable in the background hidden

}
Artist& Artist::operator=(const Artist & a_artist) {
    if(this == &a_artist)//This compares the memory of the current node to the memory of the 
                         //node you passed in
        return *this;//If they are the exact same memory you return, because you are self assigning

    //if(*this == a_artist) //This doesn't work because you are not comparing whether they are
    //the same memory/node you are only comparing if the data is the same
    //you have have two nodes with same data but they live in different memory
    if(album)
        delete [] album;
    album = nullptr;//Don't forget to set it to nullptr since you don't want to acess
                    //deleted memory

    Vendor::operator=(a_artist);//This will kickstart the parents assignment operator

    if(a_artist.album) {
        album = new char[strlen(a_artist.album) + 1];
        strcpy(album, a_artist.album);
    }
    duration = a_artist.duration;
    popularity = a_artist.popularity;

    return *this;

}
Artist::~Artist(){
    if(album)
        delete [] album;
    album = nullptr;
    duration = 0;
    popularity = 0;
}

int Artist::display() const {

    Vendor::display();
    cout << "Duration: " << duration << endl;
    cout << "Album: " << album << endl;
    cout << "Popularity Multiplier: " << popularity << endl;

    return 1;

}
int Artist::request_song(const string & song, int  payment) {

    int amount = Vendor::charge(payment, 0.5*popularity); //songs always cost 1/10 the base 
    if( amount == -1) {
        cout << "Not enought money! " << endl;
        return 0;
    }
    else
        cout << "Your total change: " << amount << " Enjoy the song: " << song << endl;

    return 1;
}
int Artist::meet_greet(int payment) {
    
    int amount = Vendor::charge(payment, popularity);
    if(amount == -1) {
        cout << "Not enough money for Meet and greet " << endl;
        return 0;
    }
    else{
        cout << "Your total change: " << amount << endl;
        cout << "Enjoy the MEET and GREET " << endl;
    }

    return 1;
}
bool Artist::album_announcement() const {
    cout << "On STAGE: " ;
    Vendor::display_title();
    cout <<"Welcome everyone the new album: " << album << " is about to play " <<endl; 
    cout << "Duration of Album: " << duration << endl;
    return true;
}
//
float Artist::display_cost( bool flag) const {
    //pass in true if wanting to use song_req
    if(flag)
        return  Vendor::display_cost(popularity*.5);
        //else false will use the meet_greet
    else
        return Vendor::display_cost(popularity);
    
}
