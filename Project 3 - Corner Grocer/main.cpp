// main.cpp
#include "ItemTracker.h"
#include "Source.cpp" 

int main() {
    ItemTracker tracker; 
    tracker.readInputFile("Inventory.txt");
    tracker.backupData("frequency.dat");
    tracker.displayMenu();
    return 0;    
}
