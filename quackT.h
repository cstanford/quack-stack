/* 
 * File:   quackT.h
 * Author: Connor Stanford
 * 
 * This is the header file for the quack template.
 */

#ifndef QUACKT_H
#define	QUACKT_H

using namespace std;

template <typename T>
struct node
{           
    T item;
    node<T> *next;
};

template <typename T>
class quackT
{
    public:
        quackT(T item);
        void push(T item);
        void pop();
        void enqueue(T item);
        void dequeue();
        bool isEmpty();
        void printItemsInQuack();
        ~quackT();
    private:
       node<T> *headPtr;
       int elementCount;    //elementCount will be used to keep track of how
                            //many items are in the quack and if the quack
                            //isEmpty()
};

template <typename T>
quackT<T>::quackT(T item){
    headPtr = new node<T>;
    headPtr->next = NULL;
    headPtr->item = item;
    elementCount = 1;
};

template <typename T>
void quackT<T>::push(T item){
   
    if(headPtr == NULL)                    
    {
        headPtr = new node<T>; 
        headPtr->next = NULL;
        cout << headPtr->item << " was pushed onto the quack. " << endl;
        elementCount += 1;
        return;
        /*If the last remaining item in the quack was previously removed by pop()
         * or dequeue(), headPtr will be set to NULL. If this is so, the item that
         * is currently being pushed will be the first item in the linked quack.
         * It's place is established by  setting headPtr to a new node with
         * headPtr->next = NULL.
         */
        
    }
    
    node<T> *current = headPtr;
    while(current)
    {
        if(current->next != NULL)
        {
            current = current->next;
        }
        else
        {
            current->next = new node<T>;
            current = current->next;
            current->item = item;
            current->next = NULL;
            elementCount += 1;
            break;
        }
        /*This cycles through the linked quack until current finds the last 
         *node. Once found, current->next creates a new node where the parameterized
         *item is then pushed onto the list.
         */
    }
    cout << current->item << " was pushed onto the quack. " << endl;
};

template <typename T>
void quackT<T>::printItemsInQuack(){
    
    if(isEmpty())
    {
        cout << "The quack is empty." << endl;
        return;
    }
    else if(headPtr->next == NULL)
    {
        cout << headPtr->item << endl;
        /*If headPtr->next =+ NULL, this means that there is only one item in the
         *quack, and there is no need to cycle through to print out each item.
         */
    }
    else
    {
        node<T> *currentPtr = headPtr;
        while(currentPtr != NULL){
        cout << currentPtr->item << endl;
        currentPtr = currentPtr->next;
        //Cycles through the quack and prints out each item. 
    }
    }
    
};

template <typename T>
void quackT<T>::enqueue(T item){
    
    if(headPtr == NULL)                   
    {
        headPtr = new node<T>;
        headPtr->next = NULL;
        headPtr->item = item;
        cout << headPtr->item << " was enqueued. " << endl;
        elementCount += 1;
        return;
        /*If the last remaining item in the quack was previously removed by pop()
         * or dequeue(), headPtr will be set to NULL. If this is so, the item that
         * is currently being enqueued will be the first item in the linked quack.
         * It's place is established by  setting headPtr to a new node with
         * headPtr->next = NULL.
         */
    }
    
    node<T> *current = headPtr;
    while(current)
    {
        if(current->next != NULL)
        {
            current = current->next;
        }
        else
        {
            current->next = new node<T>;
            current = current->next;
            current->item = item;
            current->next = NULL;
            elementCount += 1;
            break;
        }
        /*This cycles through the linked quack until current finds the last 
         *node. Once found, current->next creates a new node where the parameterized
         *item is then enqueued onto the list.
         */
    }
    cout << current->item << " was enqueued. " << endl;
};

template <typename T>
void quackT<T>::pop(){ 
    
     if(isEmpty())
    {
        cout << "The quack is empty! There is nothing to pop. " << endl;
        return;
    }
     
     else
     {
         node<T> *prev = headPtr;
         node<T> *current = prev->next;
         
         while(!isEmpty())
         {
             
             if(current == NULL)
             {
                 cout << prev->item << " was popped from the quack." << endl;
                 delete current;
                 elementCount -= 1;
                 headPtr = NULL;
                 delete prev;                
                 return;
                 /*Since headPtr->next == current, if current is NULL this means
                  *that there is only one element in the quack. If this is the 
                  *case, headPtr is set to NULL, and the original node is deleted
                  */
             }
             else if(current->next == NULL)
             {
                 cout << current->item << " was popped from the quack." << endl;
                 prev->next = current->next;
                 delete current;
                 elementCount -= 1;
                 return;
                 //Once the last node is found, it is popped off the quack.
             }
             else
             {   prev = prev->next;
                 current = current->next;
                 /*If the previous conditions are not met, this cycles through
                  *quack until the last node is reached.
                  */
             }
         }
         
     }
    
    
};

template <typename T>
void quackT<T>::dequeue(){
    
    if(isEmpty())
    {
        cout << "The quack is empty! There is nothing to dequeue. " << endl;
        return;
    }
    
    if(headPtr->next != NULL)
    {
        node<T> *temp = headPtr;
        headPtr = headPtr->next;
        cout << temp->item << " was dequeued from the quack." << endl;
        delete temp;
        elementCount -= 1;
        /*If there is more than one item in the quack, a temp pointer is used as
         *a placeholder while headPtr is moved to the second node. After the
         *headPtr is on the second node, the first node is deleted. Thus, 
         *headPtr is once again now on the first node in the quack.
         */
    }
    else
    {
        node<T> *temp = headPtr;
        cout << temp->item << " was dequeued from the quack." << endl;
        headPtr = NULL;
        elementCount -= 1;
        delete temp;
        /*If there is only one element in the quack, the first node is deleted 
         *and headPtr is set to NULL
         */
    }
};

template <typename T>
quackT<T>::~quackT()
{
    delete headPtr;
    cout << endl << "The destructor was called, and the quack has been deleted."
         << endl;
};

template <typename T>
bool quackT<T>::isEmpty()
{
    return (elementCount == 0);
};



#endif	/* QUACKT_H */

