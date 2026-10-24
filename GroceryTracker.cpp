// GroceryTracker.cpp
// Aidan Tully
// 18 October 2026
// Function definitions for the GroceryTracker class

#include "GroceryTracker.h"

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

// Reads every item from the input file and counts it in the map
bool GroceryTracker::LoadItems(const string& t_inputFileName) {
   ifstream inFS;
   string itemName;

   inFS.open(t_inputFileName);
   if (!inFS.is_open()) {
      return false;
   }

   m_itemFrequencies.clear();

   // one item per line, add 1 each time it shows up
   while (inFS >> itemName) {
      m_itemFrequencies[itemName]++;
   }

   inFS.close();
   return true;
}

// Saves every item and its count to the backup file
bool GroceryTracker::WriteBackupFile(const string& t_outputFileName) const {
   ofstream outFS;

   outFS.open(t_outputFileName);
   if (!outFS.is_open()) {
      return false;
   }

   for (const auto& item : m_itemFrequencies) {
      outFS << item.first << " " << item.second << endl;
   }

   outFS.close();
   return true;
}

// Returns how many times one item was bought, or 0 if it isn't in the list
int GroceryTracker::GetItemFrequency(const string& t_itemName) const {
   string searchName = FormatItemName(t_itemName);

   if (m_itemFrequencies.count(searchName) == 0) {
      return 0;
   }
   return m_itemFrequencies.at(searchName);
}

// Prints each item with its count
void GroceryTracker::PrintAllFrequencies() const {
   cout << endl;
   for (const auto& item : m_itemFrequencies) {
      cout << left << setw(14) << item.first << item.second << endl;
   }
}

// Prints each item with one asterisk per purchase
void GroceryTracker::PrintHistogram() const {
   cout << endl;
   for (const auto& item : m_itemFrequencies) {
      cout << left << setw(14) << item.first << string(item.second, '*') << endl;
   }
}

// Makes the first letter uppercase and the rest lowercase so "potatoes" matches "Potatoes"
string GroceryTracker::FormatItemName(const string& t_itemName) const {
   string formattedName = t_itemName;

   for (size_t i = 0; i < formattedName.size(); ++i) {
      if (i == 0) {
         formattedName.at(i) = toupper(formattedName.at(i));
      }
      else {
         formattedName.at(i) = tolower(formattedName.at(i));
      }
   }
   return formattedName;
}
