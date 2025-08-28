# Parking Lot System – DSA Project

## Overview  
This project is a **Data Structures and Algorithms (DSA)** implementation of a **Parking Lot Management System** in C++.  
It uses **Stack (LIFO)** and **Linked List** concepts to simulate one-lane or stacked parking facilities where vehicles must follow the Last-In, First-Out rule.  

The system provides core features such as parking a vehicle, removing a vehicle, searching for a vehicle, and displaying all parked cars.

---

## Problem Statement  
Efficient management of parking spaces is a growing challenge in urban areas with limited capacity. In one-lane parking lots, vehicles can only be retrieved in reverse order of entry, following a **LIFO (Last-In, First-Out)** principle.  

This project provides a stack-based solution that:  
- Records vehicle entries and exits.  
- Handles cars strictly in LIFO order.  
- Displays the current parking lot state.  

---

## Objectives  
- Simulate real-world LIFO-based parking operations.  
- Provide basic functionalities:  
  - Park (Add) a vehicle.  
  - Exit (Remove) a vehicle.  
  - Manage overflow (lot full) and underflow (lot empty).  
- Demonstrate the practical use of **stacks and linked lists**.  

---

## Importance  
- Reduces congestion in tight parking spaces.  
- Saves time in vehicle retrieval.  
- Optimizes limited capacity.  
- Demonstrates data structures in real-world applications.  

---

## Tools & Technologies  
- **C++ Programming Language**  
  - Strong support for DSA, efficient memory control.  
  - Features used: linked lists, loops, conditional logic, menu-driven interface.  

- **Microsoft Visual Studio (IDE)**  
  - Debugging support, IntelliSense, real-time error detection.  

- **Object-Oriented Programming Concepts**  
  - `Car` class – Represents vehicles.  
  - `Node` class – Implements linked list nodes.  
  - `Stack` class – Encapsulates LIFO logic.  
  - `ParkingLot` class – Manages operations and user interaction.  

---

## Data Structures Used  
- **Stack (via Linked List)**  
  - Operations: `push()`, `pop()`, `top()`, `size()`, `empty()`.  
  - Perfect for modeling single-lane parking.  
  - O(1) efficiency for insertion and deletion.  

- **Singly Linked List**  
  - Provides dynamic memory allocation.  
  - Removes fixed-size limitations.  
  - Efficient for node creation and deletion.  

- **Custom Classes**  
  - Encapsulation and modularity for scalability.  

---

## Code Flow  
1. Program initializes with defined parking capacity.  
2. User interacts through a menu:  
   - Park Car → `parkCar()`  
   - Exit Car → `exitCar()`  
   - Show Total Cars → `totalCars()`  
   - Find Car → `findCar()`  
   - Show Parked Cars → `showParkedCars()`  
   - Exit Program  
3. Stack operations ensure LIFO behavior.  
4. Program exits gracefully when selected.  
