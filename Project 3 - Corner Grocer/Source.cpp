#include "ItemTracker.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor
ItemTracker::ItemTracker() {
    // Initialize frequencyMap to an empty map
    frequencyMap = {};
}

// Function to read data from the input file and populate the frequency map
void ItemTracker::readInputFile(const std::string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file: " << filename << endl;
        return; 
    }

    std::string item;
    cout << "Reading input file: " << filename << endl;
    while (inputFile >> item) {
        frequencyMap[item]++;
    }

    inputFile.close();
    cout << "Input file reading completed." << endl;
}

// Function to backup data to a file
void ItemTracker::backupData(const std::string& filename) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file for backup: " << filename << endl;
        return;
    }

    for (const auto& pair : frequencyMap) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    outputFile.close();
    cout << "Data backup completed.\n" << endl;
}

// Function to display menu options and handle user input
void ItemTracker::displayMenu() {
    int choice; 
    do {
        cout << "\n\033[32m";
        cout << " ____ ____ ____ _  _ ____ ____    ____ ____ ____ ____ ____ ____ \n";
        cout << " |    |  | |__| |\\ | |___ |__|    | __ |__| |  | |    |___ |__| \n";
        cout << " |___ |__| |  \\ | \\| |___ |  \\    |__] |  \\ |__| |___ |___ |  \\ \n";
        cout << "\033[0m";
        cout << "================================================================\n";                                                                                                                
        cout << "******************************MENU******************************\n";
        cout << "----------------------------------\n";
        cout << "1 - Search for an item\n"; 
        cout << "2 - Print items with frequencies\n"; 
        cout << "3 - Print histogram\n";
        cout << "4 - \033[1;31mExit\033[0m\n"; 
        cout << "----------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice; 
        cin.ignore();

        switch (choice) {
            case 1: 
                searchItem(); // Call the function to search for an item
                break;
            case 2:
                printItemList(); // Call the function to print items with frequencies
                break;
            case 3:
                printHistogram(); // Call the function to print a histogram
                break;
            case 4:
                cout << "Exiting program, Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";    
        }
    } while (choice != 4);
}

// Function to search for a specific item and return its frequency
void ItemTracker::searchItem() {
    string item;
    cout << "Enter the item you wish to search for: ";
    cin >> item;

    // Check if the item is found in the frequency map
    if (frequencyMap.find(item) != frequencyMap.end()) {
        cout << "Frequency of " << item << ": " << frequencyMap[item] << endl;
    } else {
        cout << "Item not found." << endl;
    }
}

// Function to print the list of items with their frequencies
void ItemTracker::printItemList() {
    cout << "Item List with Frequencies:\n";
    for (const auto& pair : frequencyMap) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// Function to print histogram
void ItemTracker::printHistogram() {
    cout << "Histogram:\n";
    for (const auto& pair : frequencyMap) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}
