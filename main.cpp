/* 
 * File name:   Assignment #0
 * Author:      Connor Stanford 
 * 
 * Class :      CMPS 261
 * Assignment:  #0
 * Due Date :   February 5, 2015
 * Due Time :   9:30 am
 * Program Description: A complete, templated, quack class. A quack is a mutant
 * abstract data type that encapsulates the behavior of both a queue and a stack
 *  in the same data type. The underlying data structure is a linked list. The 
 *  main application simply declares and uses the class to demonstrate that it is
 *  correct.
 * 
 * Certificate of Authenticity: I certify that this assignment is entirely my
 * own work. 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "quackT.h"

using namespace std;


int main()
{
    cout <<"We will first test the quack template class using an int data type:"
         << endl << endl;
    
    quackT<int> intQuack(1);
    cout << "Here are the current items in  intQuack: " << endl;
    intQuack.printItemsInQuack();
    
    cout << endl;
    intQuack.push(2);
    intQuack.enqueue(3);
    cout << "Here are the current items in  intQuack: " << endl;
    intQuack.printItemsInQuack();
    
    cout << endl;
    intQuack.dequeue();
    cout << "Here are the current items in  intQuack: " << endl;
    intQuack.printItemsInQuack();
    
    cout << endl << "Is intQuack empty?  " << intQuack.isEmpty() << endl<< endl;
    
    cout <<"We will now test the quack template class using a string data type:"
         << endl << endl;
    quackT<string> stringQuack("first");
    cout << "Here are the current items in stringQuack: " << endl;
    stringQuack.printItemsInQuack();
    
    cout << endl;
    stringQuack.pop();
    
    cout << endl<<"Lets try to call dequeue from the empty stringQuack:" << endl;
    stringQuack.dequeue();
    
    cout << endl << "Is the stringQuack empty?  " << stringQuack.isEmpty()
         << endl;
    
    cout << endl;
    stringQuack.enqueue("second");
    stringQuack.push("third");
    stringQuack.enqueue("fourth");
    stringQuack.push("fifth");
    
    cout << endl << "Here are the current items in stringQuack: " << endl;
    stringQuack.printItemsInQuack();
    
    cout << endl;
    stringQuack.dequeue();
    stringQuack.pop();
    
    cout << endl << "Here are the current items in stringQuack: " << endl;
    stringQuack.printItemsInQuack();
    
    return 0;
}

