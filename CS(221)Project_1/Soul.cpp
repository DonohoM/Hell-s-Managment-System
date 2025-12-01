//
//  Soul.cpp
//  CS(221)Project_1
//
//  Created by Matthew Donoho on 2/26/24.
//

#include <_stdio.h>
#include "Soul.h"
#include <iostream>

// Displays all of the information for a soul
void Soul::display() const{
    std::cout << "Name: " << name << ", Death Date: " << deathDate << ", Age: " << age << ", Location: " << location << ", Soul ID: " << soulID << ", Available: " << (availability? "Yes" : "No") << std::endl;
}

// Sends a soul back to the afterlife, making them avalible again
void Soul::death(){
    availability = true;
    std::cout << name << "'s soul has returned to the After Life." << std::endl << std::endl;
}

// Sends a soul to the land of the living, making them unavalible
void Soul::rebirth(){
    if(availability){
        availability = false;
        std::cout << name << "'s soul has been reborn and is no longer available ( for now ;) ) ." << std::endl << std::endl;
    }else{
        std::cout << name << "'s soul is currently in the world of the living." << std::endl << std::endl;
    }
}

