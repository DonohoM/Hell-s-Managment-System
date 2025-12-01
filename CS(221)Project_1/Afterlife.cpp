//
//  Afterlife.cpp
//  CS(221)Project_1
//
//  Created by Matthew Donoho on 2/26/24.
//

#include <_stdio.h>
#include <algorithm>
#include "Afterlife.h"
#include <iostream>

// Constructor / destructor
Afterlife::~Afterlife(){
    for(auto& soul: souls)
        delete soul;
}

void Afterlife::displayLocName()const{
    std::cout << name << std::endl;
}

// Adds new souls to the afterlife vector
void Afterlife::collectSoul(Soul* soul){
    souls.push_back(soul);
}

// Removes souls from the afterlife vector
void Afterlife::discardSoul(const std::string& soulID){
    auto it = find_if(souls.begin(), souls.end(), [&soulID](const Soul* soul){return soul->getSoulID()==soulID;});
    if(it != souls.end()){
        delete *it;
        souls.erase(it);
        std::cout << "--Soul: " << soulID << " returned to the land of the living.--" << std::endl << std::endl;
    }
}

// Prints out all souls in the afterlife vector
void Afterlife::displaySouls() const {
    std::cout << "Current Souls in Collection: " << std::endl;
    for(const auto& soul:souls){
        soul -> display();
    }
    std::cout << std::endl;
}

// Looks for specific soul using the inputed soulID
Soul* Afterlife::findSoul(const std::string& soulID) const{
    std::cout << "\nFinding Soul..." << std::endl;
    for(const auto& soul:souls){
        if(soul -> getSoulID() == soulID) {
            std::cout << "\nSoul Found: " << std::endl;
            soul -> display();
            std::cout << std::endl;
            return soul;
        }
    }
    return nullptr;
}

// Makes a soul avalible in the afterlife (through death)
void Afterlife::reapSoul(const std::string& soulID){
    Soul*soul = findSoul(soulID);
    std::cout << "Isolating Soul..." << std::endl;
    if(soul) soul -> death();
    else std::cout << "Soul not found." << std::endl;
}

// Makes a soul unavalible in the afterlife (through rebirth)
void Afterlife::reserectSoul(const std::string& soulID){
    Soul*soul = findSoul(soulID);
    std::cout << "Isolating Soul..." << std::endl;
    if(soul) soul -> rebirth();
    else std::cout << "Soul not found." << std::endl;
}

//------------------------AFTERLIFE LIST-------------------------

AfterlifeList::~AfterlifeList(){
    for(auto& list:afterlifes){
        delete list;
    };
};

void AfterlifeList::createNewAfterlife(Afterlife* afterlife){
    afterlifes.push_back(afterlife);
}

void AfterlifeList::displayLocations() const {
    std::cout << "Current Locations: " << std::endl;
    for(const auto& list:afterlifes){
        list -> displayLocName();
    }
    std::cout << std::endl;
}

Afterlife* AfterlifeList::findLocation(const std::string& location) const {
    for(const auto& loc:afterlifes){
        if(loc -> getAfterlifeName() == location){
            std::cout << "Location found..." << std::endl;
            return loc;
        }
    }
    return nullptr;
}

void AfterlifeList::displayLocationInventory() const {
    for(const auto& list:afterlifes){
        std::cout << "Location: " << std::endl;
        list -> displayLocName();
        std::cout << "\n";
        list -> displaySouls();
        std::cout << "\n";
    }
}

Afterlife* AfterlifeList::searchLocationForSoul(const std::string& soulID) const {
    for(const auto& loc:afterlifes){
        std::cout << "Searching ";
        loc -> displayLocName();
        if(loc -> findSoul(soulID) != nullptr){
            return loc;
        }
        std::cout << "\nSoul Not Found\n" << std::endl;
    }
    return nullptr;
}

void AfterlifeList::destroyAfterlifeLocation(const std::string& name){
    auto it = find_if(afterlifes.begin(), afterlifes.end(), [&name](const Afterlife* afterlife){return afterlife -> getAfterlifeName() == name;});
    if(it != afterlifes.end()){
        delete *it;
        afterlifes.erase(it);
        std::cout << "--Afterlife " << name << " has been destroyed--" << std::endl << std::endl;
    }else{
        std::cout << "Afterlife not found" << std::endl;
    }
}

void AfterlifeList::assignSoul(Afterlife* afterlife, Soul* soul){
    afterlife -> collectSoul(soul);
}
