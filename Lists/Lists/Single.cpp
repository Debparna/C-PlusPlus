//
//  Single.cpp
//  Lists
//
//  Created by Debparna Pratiher on 9/4/16.
//  Copyright © 2016 Debparna Pratiher. All rights reserved.
//

#include "Single.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstring>
using namespace std;

ListNode::ListNode(int d) : data(d), prev(NULL), next(NULL)
{
}  // ListNode

ListNode::~ListNode() {
    
}

LinkedList::LinkedList() : head(NULL), tail(NULL), curr(NULL)

{
    
}

LinkedList::~LinkedList() //TO delete pointer to node?
{
    ListNode *temp;
    while( head != NULL){
        head = head->next;
        delete temp;
    }
    tail = NULL;
}

void LinkedList::insert(int newItem){
    ListNode *newNode; //pointer to create new node
    newNode = new ListNode(newItem); //create new node
    if(head == NULL){   //if list is empty newNode is both first and last node
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->data = newItem;
        newNode->next = head;
        head = newNode;
    }
    
}

void LinkedList::insertBack(int newItem){
    ListNode *newNode = new ListNode(newItem);
    if ( tail == NULL)
    {
        head = newNode;;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void LinkedList::deleteList(int deleteItem){
    bool found;
    ListNode *prev;
    if(head == NULL){ //list is empty, nothing to delete
        cout << " List is empty, cannot delete" << endl;
    }
    else{ //list is not empty //4
        if(head->data == deleteItem){ //head is the item to be deleted
            curr = head; //preserve rest of the list
            head = head->next;
            
            if(head == NULL){ //list only has one node
                tail = NULL; //then first and last is NULL after deletion of that node
                delete curr;
            }
        }
        else{ //search the list for the item to be deleted //3
            found = false;
            prev = head;
            curr = head->next; // curr will point to second node
            while (curr != NULL && !found) { //till item to be deleted is found
                if(curr->data != deleteItem){ //if curr is not the item to be deleted
                    prev = curr;
                    curr = curr->next;  //set curr to next
                }
                else {//2
                    found = true;
                    if (found){
                        prev->next = curr->next;
                        if(tail == curr)  //node to be deleted was the last node
                            tail = prev;
                            delete curr;
                    }
                    else{ //1
                        cout << "The item to be deleted is not in the list";
                    }//end else1
                } //end else2
            } // end while
        }//end else3
    }//end else4
}// end deleteList

    
void LinkedList::print(){
    ListNode *temp = head;
    while(temp != NULL)
    {
        cout << "Nodes in forward order:" << temp->data << endl;
        temp = temp->next;
    }
}

bool LinkedList::find(int searchItem){
    curr = head;
        while(curr != NULL)
            if(curr->data == searchItem) //item found
                return true;
            else
                curr = curr->next; //continue traversing
    
    return false; //list is empty
}

