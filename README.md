# Festival Vendor Management System
This project is a C++ implementation of a festival vendor management system developed for a programming methodologies course (CS302).  
It demonstrates **recursion**, **inheritance**, **dynamic memory management**, and **object-oriented design** in C++.

## Features
- Manage **Artists**, **Merch Vendors**, and **Food Vendors**  
- Insert, remove, and display vendor lists using recursive linked list functions  
- Interact with individual vendors through node-level functions  
- Demonstrates deep copy constructors, assignment operators, and destructors  
- Fully interactive menu system for user-driven testing

## Technical Highlights
- Implemented in C++  
- Demonstrates recursion with **Linear Linked Lists (LLL)** and **Circular Linked Lists (CLL)**  
- Uses **STL Vector** for dynamic food menu management  
- Follows best practices for **encapsulation**, **inheritance**, and **copy control**  
- No global variables — all operations encapsulated within classes  

## Data Structures Used
- **Artist** – Stored in a Linear Linked List (LLL)  
- **Merch** – Stored in a Circular Linked List (CLL)  
- **Food** – Stored in an STL Vector  

## File Structure
vendor.h / vendor.cpp        → Base class implementation  
artist.h / artist.cpp        → Artist subclass  
artistNode.h / artistNode.cpp → Artist node for LLL  
ArtistList.h / ArtistList.cpp → Linear Linked List management  
merch.h / merch.cpp          → Merch subclass  
merchNode.h / merchNode.cpp  → Merch node for CLL  
C_list.h / C_list.cpp        → Circular Linked List management  
food.h / food.cpp            → Food subclass using STL vector  
main.cpp                     → Interactive driver program  

## How to Compile & Run
```bash
g++ -Wall *.cpp -o festival
./festival
