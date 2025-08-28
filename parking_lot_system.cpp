#include <iostream>
#include <string>
using namespace std;

// --------------------
// Node Class Template
// --------------------
// Represents a node in a singly linked list (used for Stack)
template <typename T>
class Node
{
public:
    T data;           // Data stored in the node
    Node<T>* next;    // Pointer to the next node

    // Constructor initializes node with data and null next pointer
    Node(T value) : data(value), next(nullptr) {}
};

// --------------------
// Stack Class Template
// --------------------
// Implements a stack using linked list nodes
template <typename T>
class Stack
{
private:
    Node<T>* topNode; // Pointer to the top node in the stack
    int count;        // Number of elements in the stack

public:
    Stack() : topNode(nullptr), count(0) {}

    // Push a new element onto the stack
    void push(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    // Pop the top element off the stack
    void pop()
    {
        if (topNode != nullptr)
        {
            Node<T>* temp = topNode;
            topNode = topNode->next;
            delete temp;
            count--;
        }
    }

    // Access the top element (by reference)
    T& top()
    {
        return topNode->data;
    }

    // Check if stack is empty
    bool empty() const
    {
        return topNode == nullptr;
    }

    // Get the current size of the stack
    int size() const
    {
        return count;
    }

    // Getter to access top node pointer
    Node<T>* getTopNode() const
    {
        return topNode;
    }
};

// --------------------
// Car Class
// --------------------
// Represents a car with a unique number plate
class Car
{
public:
    string number;

    Car(string num) : number(num) {}
};

// --------------------
// ParkingLot Class
// --------------------
// Manages car parking operations using a Stack of Cars
class ParkingLot
{
private:
    Stack<Car> parkingStack; // Stack representing parked cars
    int capacity;            // Maximum capacity of parking lot

public:
    ParkingLot(int size) : capacity(size) {}

    // Park a new car if there is space
    void parkCar(string number)
    {
        if (parkingStack.size() >= capacity)
        {
            cout << "Parking Lot Full! Car " << number << " cannot be parked.\n";
            return;
        }
        parkingStack.push(Car(number));
        cout << "Car " << number << " parked successfully.\n";
    }

    // Remove the most recently parked car from the lot
    void exitCar()
    {
        if (parkingStack.empty())
        {
            cout << "Parking Lot is already empty.\n";
            return;
        }
        cout << "Car " << parkingStack.top().number << " exited the parking lot.\n";
        parkingStack.pop();
    }

    // Display all parked cars from most recent to earliest
    void showParkedCars()
    {
        if (parkingStack.empty())
        {
            cout << "Parking Lot is empty.\n";
            return;
        }

        cout << "\nCars in Parking Lot (Top is most recent):\n";
        Node<Car>* current = parkingStack.getTopNode();
        while (current != nullptr)
        {
            cout << current->data.number << "\n";
            current = current->next;
        }
    }

    // Find if a car with a given number is parked
    void findCar(string number)
    {
        Node<Car>* current = parkingStack.getTopNode();
        bool found = false;
        while (current != nullptr)
        {
            if (current->data.number == number)
            {
                found = true;
                break;
            }
            current = current->next;
        }

        if (found)
        {
            cout << "Car " << number << " is currently parked in the parking lot.\n";
        }
        else
        {
            cout << "Car " << number << " is NOT parked in the parking lot.\n";
        }
    }

    // Display total cars currently parked
    void totalCars()
    {
        cout << "Total cars currently parked: " << parkingStack.size() << "\n";
    }
};

// --------------------
// Main Function
// --------------------
// Menu-driven interface for Parking Lot management
int main()
{
    int capacity = 5; // Set parking lot capacity

    ParkingLot lot(capacity);
    int choice;
    string carNumber;

    do
    {
        // Menu 
        cout << "\n====== Parking Lot Menu ======\n";
        cout << "1. Park Car\n";
        cout << "2. Exit Car\n";
        cout << "3. Show Total Cars\n";
        cout << "4. Find Car\n";
        cout << "5. Show Parked Cars\n";
        cout << "6. Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation for menu choice
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid input! Please enter a number between 1 and 6.\n";
            continue;
        }

        // switch case to run different functions based on choice
        switch (choice)
        {
        case 1:
            cout << "Enter Car Number: ";
            cin >> carNumber;
            lot.parkCar(carNumber);
            break;

        case 2:
            lot.exitCar();
            break;

        case 3:
            lot.totalCars();
            break;

        case 4:
            cout << "Enter Car Number to Find: ";
            cin >> carNumber;
            lot.findCar(carNumber);
            break;

        case 5:
            lot.showParkedCars();
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid input! Please enter a number between 1 and 6.\n";
            break;
        }

    } while (choice != 6);

    return 0;
}
