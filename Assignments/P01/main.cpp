/**********************************************************************
*                                                                     *
* Author:           Jonathan Hogan                                    *
* Email:            jon.hogan83@gmail.com                             *
* Label:            P01                                               *
* Title:            Array Based Stack                                 *
* Course:           2143                                              *
* Semester:         Fall 2020                                         *
*                                                                     *
* Description:                                                        *
*       Example implementation of an array based stack that holds     *
*       integers. Further adding on to it by allowing the stack to    *
*       grow or shrink in size depending on how much is pushed or     *
*       popped to or from the stack.                                  *
*                                                                     *
* Usage:                                                              *
*       Nothing special right now. Getting familiar with stacks, etc. *
*                                                                     *
* Files:                                                              *
*       main.cpp                                                      *
*       input.txt                                                     *
*       output.txt                                                    *
*                                                                     *
**********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*********************************************************************
 * Stack
 *
 * Description:
 *      Integer array based stack implementation
 *
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - void Print()
 *
 * Private Methods:
 *      - None
 *
 * Usage:
 *
 *  Reads set of push and pop commands
 *  from an input file provided.
 *
 *********************************************************************/
class Stack {
private:
    int* S;                     // array pointer
    int cap;                    // max stack size
    unsigned long int Max_Size; // Max stack size variable
    bool MemDoub;               // Variable to track if memory was doubled
    int size;                   // current num items
    int top;                    // current top (index)
    
public:

    /******************************************************************
     * Pop:
     *    remove item from stack.
     * Params:
     *    void
     *
     * Returns:
     *     int
     ******************************************************************/
    int Pop() {

        if (top == -1)                                   // If stack is empty
        {
            cout << "Error: Stack Empty!\n";
            return -1;
        }

        if (MemDoub == true && top < (cap / 2))          // If stack size dips below half
        {
            cout << "Stack is at less than 50% of capacity, decreasing size.\n";
            cap = cap / 2;                               // Halves the capacity
            cout << "New capacity is :" << cap << '\n';
            int* NStack;
            NStack = new int[cap];


            for (int i = 0; i < cap; i++)
            {
                NStack[i] = S[i];                         // Copying contents of the previous bigger stack
            }                                             // into the new array with smaller capacity

            delete[] S;                                   // Releasing the memory of previous array
            S = NStack;
            int data = S[top];
            top--;
            size--;
            return data;

        }
        else
        {
            int data = S[top];                            // pull item from stack
            top--;                                        // shrink the stack
            size--;                                       // update our size
            return data;                                  // send item back
        }
    }
    
    /******************************************************************
     * Print:
     *    Used so we can inspect our stack.
     * Params:
     *    void
     *
     * Returns:
     *     void
     *****************************************************************/
    void Print()
    {
        // Output File Print formatting 

        ofstream outFile("output.txt");
        outFile << "Name: Jonathan Hogan\n" << "Program: P01\n" << "Date: 15 September 2020\n\n"
            << "Starting Size: 10\n" << "Max Size: " << Max_Size << '\n' << "Ending Size: "
            << size << '\n';
    }

        /******************************************************************
     * Push:
     *    Push item onto stack.
     * Params:
     *    int : data
     *
     * Returns:
     *     Void
     *****************************************************************/
    void Push(int data) {


        if (size == cap)
        {
            top++;
            size++;
            cout << "Stack is full. Increasing size.\n";
            cap = cap * 2;
            cout << "New capacity is :" << cap << '\n';
            int* NewS;                                    // Creating a new dynamic array with double the memory
            NewS = new int[cap];
            MemDoub = true;                               

            for (int i = 0; i < (cap / 2); i++)           // Assigning the values of the old array into the new one
            {
                NewS[i] = S[i];
            }

            delete[] S;                                   // Releasing the memory of previous array

            S = NewS;                                     // Pointing to the new array

            S[top] = data;

            if (Max_Size <= cap)                          // Updating our Max Size variable
            {
                Max_Size = cap;
            }
        }
        else
        {
            top++;                                        // move top of stack up
            size++;                                       // increment size
            S[top] = data;                                // add item to array
        }

    }

    /******************************************************************
     * Stack:
     *    Constructor.
     * Params:
     *    void
     *
     * Returns:
     *     Void
     *****************************************************************/
    Stack() {
        cap = 10;               // set array size
        S = new int[cap];       // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
        Max_Size = 0;
        MemDoub = false;        // memory double is false
    }
};


int main() {
    int num;                                            // Int variable read from input file
    string command;                                     // Command read from input file
    Stack S1;                                           // Stack Object dedclared
    ifstream inFile;


    inFile.open("input.txt");

    if (!inFile)                                        // If file isn't opened successfully
    {
        cout << "file not found\n";
        system("pause");
        exit(1);
    }

    while (!inFile.eof())                                // While file is still open
    {
        inFile >> command;

        if (command == "push")                           // If the command is Push, a number is read next
        {
            inFile >> num;
            S1.Push(num);
        }
        else
        {
            S1.Pop();
        }
    }
    inFile.close();


    S1.Print();

    system("pause");
    return 0;
}
