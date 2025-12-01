//
//  Afterlife.h
//  CS(221)Project_1
//
//  Created by Matthew Donoho on 2/26/24.
//
// Need: products (a dynamic array using vector<Product*> to hold multiple products).

#ifndef Afterlife_h
#define Afterlife_h

#include "Soul.h"
#include <vector>
#include <string>

// The main afterlife class
class Afterlife{
    // The vector that holds all of the souls for a Afterlife class
    std::vector<Soul*> souls;
    std::string name;

public:
    // Class deconstructor
    ~Afterlife();
    Afterlife(std::string n) : name(n){}
    
    void displayLocName() const;
    
    // adds a soul to a Afterlife class
    void collectSoul(Soul* soul);
    
    // erases a soul from a Afterlife class
    void discardSoul(const std::string& soulID);
    
    // displays all of the souls in a Afterlife class
    void displaySouls() const;
    
    // searches for a soul in a Afterlife class
    Soul* findSoul(const std::string& soulID) const;
    
    // Makes a soul avalible
    void reapSoul(const std::string& soulID);
    
    // Makes a soul unavalible
    void reserectSoul(const std::string& soulID);
    
    
    //void checkKarma(const std::string& soulID);
    
    std::string getAfterlifeName() const {return name;}
};

class AfterlifeList{
    std::vector<Afterlife*> afterlifes;
    
public:
    ~AfterlifeList();
    
    void createNewAfterlife(Afterlife* afterlife);
    void displayLocations() const;
    Afterlife* findLocation(const std::string& location) const;
    void displayLocationInventory() const;
    Afterlife* searchLocationForSoul(const std::string& soulID) const;
    void destroyAfterlifeLocation(const std::string& name);
    void assignSoul(Afterlife* afterlife, Soul* soul);
};

#endif /* Afterlife_h */
