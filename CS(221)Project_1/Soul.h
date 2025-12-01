//
//  Soul.h
//  CS(221)Project_1
//
//  Created by Matthew Donoho on 2/22/24.
//
// Need: name, price, quantity, stockLocations (a dynamic array using vector<int> to represent stock across various locations).
// Also: Constructor, Destructor, updatePrice, updateQuantity, addStockLocation, displayProductInfo.

#ifndef Soul_h
#define Soul_h

#include <string>

// Defineing all of the aspects of a soul
class Soul{
    std::string name;
    std::string deathDate;
    std::string soulID;
    std::string location;
    int age;
    //double karma;
    bool availability;
    
    // Initialization list for Soul
public:
    Soul(std::string n, std::string d, std::string s, int a, std::string l) : name(n), deathDate(d), soulID(s), age(a), location(l), availability(true) {}
    void display() const; // displays a soul
    void death(); // makes a soul avalible
    void rebirth(); // makes a soul unavalible
    void displayKarma() const; // displays a soul's karma
    
    std::string getSoulID() const {return soulID;} // returns a soul's id
    std::string getSoulLocation() const {return location;} // returns the soul's location
    
};

#endif /* Soul_h */
