/*
Author: Michael Naiss
Class: CS210
Project 3
*/

#pragma once

#ifndef GROCERY_ITEM_H
#define GROCERY_ITEM_H

#include <string>
#include <map>

// Define the ItemTracker class
class ItemTracker 
{
    private: 
    // Map to store item frequencies
    std::map<std::string, int> frequencyMap;
    
    public:
    // Constructor
    ItemTracker();

    // Function to read data from the input file
    void readInputFile(const std::string& filename);

    // Function to backup data to a file
    void backupData(const std::string& filename);

    // Function to display the menu
    void displayMenu();

    // Function to search for an item
    void searchItem();

    // Function to print the list of items with frequencies
    void printItemList();

    // Function to print a histogram
    void printHistogram();

};

#endif // GROCERY_ITEM_H
