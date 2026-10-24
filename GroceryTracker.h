// GroceryTracker.h
// Aidan Tully
// 18 October 2026
// Class that counts how often each item shows up in the Corner Grocer records

#ifndef CORNERGROCER_GROCERYTRACKER_H_
#define CORNERGROCER_GROCERYTRACKER_H_

#include <map>
#include <string>

class GroceryTracker {
public:
   bool LoadItems(const std::string& t_inputFileName);
   bool WriteBackupFile(const std::string& t_outputFileName) const;
   int GetItemFrequency(const std::string& t_itemName) const;
   void PrintAllFrequencies() const;
   void PrintHistogram() const;

private:
   std::map<std::string, int> m_itemFrequencies;   // item name -> times purchased
   std::string FormatItemName(const std::string& t_itemName) const;
};

#endif // CORNERGROCER_GROCERYTRACKER_H_
