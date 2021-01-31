//
//  linkedlist.cpp
//  Containers
//
//  Created by Debparna Pratiher on 8/8/16.
//  Copyright © 2016 Debparna Pratiher. All rights reserved.
//

#include "Dlinkedlist.hpp"
using namespace std;
#include <iostream>

DListNode::DListNode( int d, DListNode *p, DListNode *n): data(d), previous(p), next(n)
{
    
}

DLinkedList:: DLinkedList(): Container(0), head(NULL), tail(NULL), curr(NULL)
{

}

DLinkedList::~DLinkedList()
{
    for(curr = head; curr != NULL; curr = head)
    {
        head = curr->next;
        delete curr;
    }
}

//DO NOT UNDERSTAND//
int DLinkedList::erase(int num)
{
    DLinkedList *prev = NULL;
    int *ptr;
    
    for(curr = head; curr && (curr->data < num || num < curr->data);curr = curr->next)
        prev = curr;
    
    if(!curr)
        return NULL;
    
    size--;
    
    if(prev)
        prev->next = curr->next;
    else
        head = curr->next;
    
    if(curr->next)
    {
        curr->next->previous = prev;
        ptr = &curr->next->data;
    }
    else
        ptr = NULL;
    delete curr;
    return ptr;
}

int* DLinkedList::insert(int num)
{
    if(tail)
        tail = tail->next = new DLinkedNode(num, tail, NULL);
    else
        head = tail = new DLinkedNode(num, NULL, NULL);
    
    curr = tail;
    size++;
    return &tail->data; //WHY ADDRESS OF?
}

int* DLinkedList::find(int num)
{
  for(curr = head; curr && (curr->data < num || num < curr->data);curr = curr->next)
      out<< curr->data << '';
    
    if(!curr)
        return NULL;
    return curr->data;
}

int* DLinkedList::operator--()
{
    if(curr)
        curr = curr->previous;
    /////WTF//////
    if(curr)
        return &curr->data;
    
    return NULL;
}

int* DLinkedList::operator++()
{
    if(curr)
        curr = curr->next;
    
    if(curr)
        return &curr->data;
    
    return NULL;
}
