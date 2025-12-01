//
//  main.cpp
//  CS(221)Project_1
//
//  Created by Matthew Donoho on 2/22/24.
//
// Create a managment program for the Grim Reaper
// It decuments souls and their information (name, date of death, age)

/* Goals
- 1. Have a way to collect the data of the soul
- 2. Have a way to orginize the sould dynamicaly
- 3. Have a way to access data from a sould
*/

// Soul ID is gender(1 = male, 0 = female)/alphanumeric number of the first letters of their first and last name/date of death

#include <iostream>
#include <vector>
#include "Afterlife.h"

// Initializes some locations in the after life, but you can add more


Afterlife* Tartarus = new Afterlife("Tartarus");
Afterlife* Asphodel = new Afterlife("Asphodel");
Afterlife* Elysium = new Afterlife("Elysium");

AfterlifeList all;

// Initializes the functions needed for the ui

void addNewSoul(); // Adds a new soul, placing it in a different location based off of the inputed karma
int findSoul(); // Searches for a soul in a specified location
void returnSoul(int request); // Returns a soul to the land of the living / or the land of the dead
void inventoryAtLocation(); // Lists the iventory at the inputted location

// Main function
int main(){
    
    // Initialized some souls to test different functionalities
    Tartarus -> collectSoul(new Soul("John Adams", "01/12/2023", "110012023", 45, "Tartarus"));
    Asphodel -> collectSoul(new Soul("Andrew Michel", "11/02/1943", "101131943", 50, "Asphodel"));
    Elysium -> collectSoul(new Soul("Trina Wazowski", "01/12/2000", "020212000", 25, "Elysium"));
    
    all.createNewAfterlife(Tartarus);
    all.createNewAfterlife(Asphodel);
    all.createNewAfterlife(Elysium);
    //all.displayLocations();
    
    //all.displayLocationInventory();
    
    // This is the main while loop that will run until the user inputs 'n' at the end to exit
    while(true){
        
        // Variable to keep track of what the user wants to do regarding the ui
        int request = 0;
        
        // Ask if the user wants to add a soul, return a soul to the living, discard a soul, or find a soul
        std::cout << "Would you like to:\n"
                  << "\t1. Add A New Soul\n"
                  << "\t2. Find A Soul\n"
                  << "\t3. Return A Soul To The Land Of The Living\n"
                  << "\t4. Inventory At Location\n"
                  << "\tResponse: ";
        std::cin >> request;
        
        switch (request) {
            case 1: // Adds a new soul by asking the user to input information about the soul
                addNewSoul();
                break;
            case 2: // Serches for a soul based on the location and soul ID
                findSoul();
                break;
            case 3: // Returns a soul to the land of the living or dead
                returnSoul(request);
                break;
            case 4:
                inventoryAtLocation();
                break;
            default: // They input something else
                std::cout << "Invalid input." << std::endl;
                break;
        }
        
        // Checks if they have any more requests for the managment system
        char repeat = ' ';
        std::cout << "Would you like to submit another request(y/n): ";
        std::cin >> repeat;
        if(std::tolower(repeat) == 'n')
            break;
        
    }
}

/**Adds a new soul**/
void addNewSoul(){
    // Different variables needed for getting a soul properly added to a afterlife
    std::string name;
    std::string name1;
    std::string name2;
    std::string date;
    std::string sId;
    int age;
    std::string location;
    
    // Line of questioning to collect data about the soul
    std::cout << "Enter Soul's name (First Last): " << std::endl;
    std::cin >> name1 >> name2;
    std::cout << "Enter Soul's Death Date (XX/XX/XXXX): ";
    std::cin >> date;
    std::cout << "Enter Soul's Soul ID: ";
    std::cin >> sId;
    std::cout << "Enter Soul's Age: ";
    std::cin >> age;
    std::cout << "Enter Soul's Location: ";
    std::cin >> location;
    
    // Getline was acting funky so i went old school and just manually added the names together
    name = name1+" "+name2;
    
    all.assignSoul(all.findLocation(location), new Soul(name, date, sId, age, location));
    all.displayLocationInventory();
}

/**Finds a requested soul**/

int findSoul(){
   
    // Asks for the soul ID of the requested soul
    std::string sId;
    std::cout << "Please enter the Soul ID of the soul you would like to find: ";
    std::cin >> sId;
    std::cout << std::endl;
    
    all.searchLocationForSoul(sId);
    
    return 0;
}

/**Reterns a soul to the living or back to the dead**/
void returnSoul(int request){
    
    // Asks if user is rebirthing a soul or reaping a soul
    request = 0;
    std::string soulResponse;
    std::cout << "\t1. Reserect Soul.\n\t2. Reap Soul." << std::endl;
    std::cout << "\tResponse: ";
    std::cin >> request;
    
    // 1 is for rebirth, 2 is for death
    switch(request){
        case 1:
            std::cout << "\nEnter Soul ID: " << std::endl;
            std::cin >> soulResponse;
            all.searchLocationForSoul(soulResponse) -> reserectSoul(soulResponse);
            break;
        case 2:
            std::cout << "\nEnter Soul ID: " << std::endl;
            std::cin >> soulResponse;
            all.searchLocationForSoul(soulResponse) -> reapSoul(soulResponse);
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
    }
}

void inventoryAtLocation(){
    
    int response = 0;
    std::string locationName = "";
    // Asks user for the location they wish to see
    std::cout << "\n\nDisplaying Location's Inventory: " << std::endl;
    
    all.displayLocationInventory();
    
    std::cout << "Would you like to: \n"
              << "1. Create a new location?\n"
              << "2. Remove a location?\n"
              << std::endl;
    std::cout << "Response: ";
    std::cin >> response;
    
    switch (response) {
        case 1:
            std::cout << "Please enter the name of your new Afterlife location: " << std::endl;
            std::cin >> locationName;
            std::cout << std::endl;
            all.createNewAfterlife(new Afterlife(locationName));
            all.displayLocations();
            break;
        case 2:
            std::cout << "Please enter the name of the Afterlife location you would like to delete: " << std::endl;
            std::cin >> locationName;
            std::cout << std::endl;
            all.destroyAfterlifeLocation(locationName);
            all.displayLocations();
            break;
        default:
            std::cout << "Invalid response" << std::endl;
            break;
    }
}

