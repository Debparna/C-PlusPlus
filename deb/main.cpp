//
//  main.cpp
//  deb
//
//  Created by Debparna Pratiher on 8/30/16.
//  Copyright © 2016 Debparna Pratiher. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstring>
using namespace std;

class myArray{
    
public:
    static const int size = 3;
    int arr[3];
    myArray();
    ~myArray();
    void get();
    void printArray();
    
    void add(int num, int pos);
    void addFront(int num);
    void addBack(int num);
    void deleteArr(int pos);
    void selectionSort();
    void swap(int i, int j);
    void insertionSort();
    void mergesort();
};

void myArray::get(){
    for(int i = 0; i < size; i++){
        cout << "Enter elements of an array" << " ";
        cin >> arr[i];
    }
}

void myArray::swap(int i, int j){
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void myArray::printArray(){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

/*
The selection sort works as follows: you look through the entire array for the smallest element, once you find it you swap it (the smallest element) with the first element of the array. Then you look for the smallest element in the remaining array (an array without the first element) and swap it with the second element.
*/
void myArray::selectionSort(){
    int min;
    for( int i = 0; i < size - 1; i++){
        min = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
                swap(i, min);
            }
        }
        
    }
}

void myArray::insertionSort(){
    for (int i = 1; i < size; i++){
        int j = i;
            while(j > 0 && arr[j - 1] > arr[j]){
                swap(j-1, j);
            }
    }
}

void myArray::mergesort(){
    
}

myArray::myArray(){
    
}

myArray::~myArray(){
    
}

void myArray::addFront(int num){
    //size++;
    for(int i = size - 1; i >= 0; i--){
        arr[i+1] = arr[i];
    }
    arr[0] = num;
}

void myArray::addBack(int num){
    //size++;
    arr[size - 1] = num;
}

void myArray::deleteArr(int pos){
    if (pos < size){
        arr[pos] = 0;
    }
    else {
        cout << "Position out of bounds" << " ";
    }
    
    for(int i = pos + 1 ; i < size ; i++){
        arr[i - 1] = arr[i];
    }
    arr[size-1] = NULL;
}


/*-------------DYNAMIC ARRAY------------------------*/

class myDarray : public myArray
{
public:
    int *darr;
    int size;
    int setSize();
    
    void get();
    
    void printArray();
    myDarray(int size = 0);
    ~myDarray();
    
    void reverse();
    void add(int num, int pos);
    void addFront(int num);
    void addBack(int num);
    void deleteArr(int pos);
    void search(int num);
    
};

myDarray::myDarray(int size1):size(size1)
{
    darr = new int(size);
}

myDarray::~myDarray(){
    delete [] darr;
}


void myDarray::add(int num, int pos){
    
    
    darr[pos] = num ;
}

void myDarray::addFront(int num){
    int *newArray = new int(size + 1);
    newArray[0] = num;
    for(int i = 0; i < size; i++)
    {
        newArray[i+1] = darr[i];
    }
    
    delete[] darr;
    darr = newArray;
    size += 1;
}

void myDarray::addBack(int num){
    int *newArray = new int(size + 1);
    newArray[size] = num;
    for(int i = 0; i < size; i++)
    {
        newArray[i] = darr[i];
    }
    delete[] darr;
    darr = newArray;
    size += 1;
}

int myDarray::setSize(){
    cout << "Size of array " << " ";
    cin >> size;
    return size;
}

void myDarray::get(){
    for(int i = 0; i < size; i++){
        cout << "Enter elements of an array" << " ";
        cin >> darr[i];
    }
}

void myDarray::printArray(){
    for(int i = 0; i < size; i++){
        cout << darr[i] << " ";
    }
}

void myDarray::deleteArr(int pos){
    if (pos < size){
      darr[pos] = 0;
    }
    else {
        cout << "Position out of bounds" << " ";
    }
    
    for(int i = pos + 1 ; i < size ; i++){
        darr[i - 1] = darr[i];
    }
    darr[size-1] = NULL;
}


void myDarray::search(int num){
    int i;
    for(i = 0; i < size; i++){
        if (darr[i] == num){
            cout << "Element found" << endl;
            return;
        }
    }
    
    if ( i == size )
        cout << "Not found";
}

void myDarray::reverse(){
    int *temp = new int(size);
    int index = 0;
    for(int i = size - 1; i >= 0; i--){
        
        temp[index] = darr[i];
        index++;
    }
    
    for(int i = 0; i < size; i++){
        cout << temp[i] << " ";
    }
}

/*-------------Stack------------------------*/


class myDStack : public myDarray
{
    
public:
//    int *stack;
    myDStack(int stackSize);
    virtual ~myDStack();
    void initializeStack();
    void push(int val);
    int pop();
    int top();
    int stackTop;
    int stackSize;
     void printStack();
    private:
    bool isEmpty();
    bool isFull();
    
};

myDStack::myDStack(int Size):myDarray(stackSize) {
    
  //stack = new int(stackSize);
    stackTop = 0;
}

myDStack::~myDStack(){
   // delete [] stack;
}

void myDStack::printStack(){
    //if (stackTop == 0){
      //  cout << "stack is empty";
    //}
        for(int i = 0; i <=stackTop; i++){
            cout << darr[i] << endl;
        }

}
bool myDStack::isEmpty(){
    if ( stackTop == 0 )
        return true ;
    else
        return false;
}

bool myDStack::isFull(){
    if ( stackTop >= stackSize - 1) {         //if top position is the last of position of stack, means stack is full .
        return true;
    }
    else{
        return false;
    }
}

int myDStack::top(){
    return darr[stackSize-1];
}

void myDStack::push(int val){
    if (!isFull()){
        add(val, stackTop);
        stackTop++;
    }
    else
        cout << "stack is full";
}

int  myDStack::pop(){
    if (!isEmpty()){
        
        stackTop--;
        return darr[stackTop-1];
    }
    else
        cout << "cannot remove";
    return -1;
}

/*-------------Queue------------------------*/

class myQueue : public myDarray
{
    
public:
    myQueue(int queueSize);
   // ~myQueue();
    void addQueue(int val);
    void deleteQueue();
    int  back();
    int front();
    int queueFront;
    int queueBack;
    int count;
    int queueSize;
    void printQueue();
private:
    bool isEmpty();
    bool isFull();
    
};

myQueue::myQueue(int sizeq):myDarray(queueSize){
    
    queueFront = queueBack = 0;
}

void myQueue::printQueue(){
    for(int i = 0; i <= queueBack; i++){
        cout << darr[i] << endl;
    }
    
    cout << queueSize;
}

bool myQueue::isEmpty(){
    if ( queueBack == queueFront )
        return true ;
    else
        return false;
}

bool myQueue::isFull(){
    if ( queueBack == queueSize) {         //if top position is the last of position of stack, means stack is full .
        return true;
    }
    else{
        return false;
    }
}

int myQueue::front(){
    return darr[queueFront];
}

int myQueue::back(){
    return darr[queueBack];
}

void myQueue::addQueue(int val){
    if (!isFull()){
       
        add(val, queueBack);
         queueBack += 1;
    }
    else
        cout << "full";
}

void myQueue::deleteQueue(){
    if (!isEmpty()){
        
        darr[queueFront] = 0;
        queueFront = queueFront + 1;
    }
    else
        cout << "cannot remove";
}



int main() {
    myArray array;
    array.get();
    //array.selectionSort();
    array.insertionSort();
    array.printArray();
    //myDarray myFunc(11);
    //myFunc.setSize();
    //myFunc.get();
    //myFunc.add(arr, 1, 11 );
    //myFunc.addFront(1);
    //myFunc.addBack(1);
    //myFunc.search(2);
    //myFunc.deleteArr(1);
    //myFunc.reverse();
    //myFunc.printArray();
    
    //myDStack myStack(10);
    //myStack.push(3);
    //myStack.pop();
    //myStack.printStack();
    //myStack.top();
    
    //myQueue myqueue(10);
    //myqueue.addQueue(3);
    //myqueue.deleteQueue();
    //myqueue.printQueue();
 
}