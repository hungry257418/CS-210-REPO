# CS-210-REPO
Aidan Tully's repo for module eight journal as part of CS-210 Programming Languages

# CS-210 Project Three: Corner Grocer Item Tracker

A C++ console program built for CS-210 Programming Languages at SNHU. It reads a day's worth of purchase records and tells the store how often each item was bought.

## Files

- `main.cpp` runs the menu and handles user input
- `GroceryTracker.h` and `GroceryTracker.cpp` hold the class that loads, counts, and prints the data
- `CS210_Project_Three_Input_File.txt` is the sample input file
- `frequency.dat` is the backup file the program creates at startup
- `.sln` and `.vcxproj` files are the Visual Studio project

## Reflection

**Summarize the project and what problem it was solving.**

The Corner Grocer wanted to rearrange their produce section based on what customers actually buy. They had text records listing every item purchased throughout the day, but no easy way to make sense of them. My program reads that file, counts how many times each item shows up, and gives the user a menu to look up a single item, see the full list with counts, or see the same data as a text histogram. It also writes all the counts to a backup file called `frequency.dat` as soon as it starts.

**What did you do particularly well?**

I think the class design is the strongest part. All the data lives in a private map inside the `GroceryTracker` class, and `main` only talks to it through public functions, so the menu code stays short and easy to follow. I also handled the user side well. The search ignores capitalization, so "potatoes" still finds "Potatoes", an item that isn't in the list returns 0 instead of breaking anything, and any menu choice other than 1 to 4 just shows an error and brings the menu back.

**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**

Right now the program reads the file one word at a time, so an item with a space in its name, like "Green Peppers", would get split into two items. Reading full lines with `getline` would fix that. I'd also normalize the capitalization when the data is loaded instead of only when searching, so "apples" and "Apples" in the file would count as the same item. The file names are hardcoded too, so letting the user pass in a file name would make it work for any day's records, not just this one. Finally, adding a few automated tests for the counting and search functions would make it safer to change the code later without breaking something by accident.

**Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?**

Getting comfortable with map syntax took some work, especially the difference between using `[]`, which adds a missing key, and `.count()` with `.at()`, which doesn't. I used the `[]` version for counting and the safer version for searching so a lookup wouldn't accidentally add empty items. The other challenge wasn't really code at all. When I first ran the program, Windows Security blocked it from writing `frequency.dat`, and it took some digging to work out that the problem was my system settings and not my code. The zyBooks sections on maps and file I/O, cppreference.com, and the Visual Studio debugger are all part of my support network now.

**What skills from this project will be particularly transferable to other projects or course work?**

Splitting a program into a class that handles the data and a main file that handles the user is something I'll use in pretty much every project from here on. Reading from and writing to files, picking the right data structure for the job (a map was a much better fit than parallel vectors here), and validating user input are all skills that carry over to other languages too, not just C++.

**How did you make this program maintainable, readable, and adaptable?**

I kept each function focused on one job, used clear names like `GetItemFrequency` and `PrintHistogram`, and followed a consistent naming style with `m_` for member variables and `t_` for parameters. Each function has a short comment explaining what it does, and the header file uses include guards. Because the data and the logic are kept inside the class, adding a new feature, like sorting items by how popular they are, would mostly mean adding one new function without touching the menu code much.
