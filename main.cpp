// main.cpp
// Aidan Tully
// 18 October 2026
// Corner Grocer item tracker: menu for looking up item purchase frequencies

#include <iostream>
#include <string>

#include "GroceryTracker.h"

using namespace std;

void DisplayMenu();

int main() {
   GroceryTracker tracker;
   string menuChoice;
   string itemName;

   // load the day's records, stop if the file can't be found
   if (!tracker.LoadItems("CS210_Project_Three_Input_File.txt")) {
      cout << "Error: could not open CS210_Project_Three_Input_File.txt" << endl;
      return 1;
   }

   // back up the counts right away, no user input needed
   if (!tracker.WriteBackupFile("frequency.dat")) {
      cout << "Warning: could not create frequency.dat" << endl;
   }

   // keep showing the menu until the user picks 4
   while (true) {
      DisplayMenu();
      getline(cin, menuChoice);

      // stop if input ends unexpectedly
      if (cin.fail()) {
         break;
      }

      if (menuChoice == "1") {
         cout << "Enter the item to search for: ";
         getline(cin, itemName);
         cout << itemName << " was purchased " << tracker.GetItemFrequency(itemName) << " time(s)." << endl;
      }
      else if (menuChoice == "2") {
         tracker.PrintAllFrequencies();
      }
      else if (menuChoice == "3") {
         tracker.PrintHistogram();
      }
      else if (menuChoice == "4") {
         cout << "Goodbye." << endl;
         break;
      }
      else {
         // anything other than 1 to 4 is rejected
         cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
      }
   }

   return 0;
}

// Prints the menu options
void DisplayMenu() {
   cout << endl;
   cout << "===== Corner Grocer =====" << endl;
   cout << "1. Search for an item" << endl;
   cout << "2. Print all item frequencies" << endl;
   cout << "3. Print histogram" << endl;
   cout << "4. Exit" << endl;
   cout << "Enter your choice: ";
}
