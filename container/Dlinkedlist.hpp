//
//  linkedlist.hpp
//  Containers
//
//  Created by Debparna Pratiher on 8/8/16.
//  Copyright © 2016 Debparna Pratiher. All rights reserved.
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

#include "container.hpp"

class DListNode
{
    int data;
    DListNode *previous;
    DListNode *next;
    DListNode( int d, DListNode *p, DListNode *n);
    friend class DLinkedList;
};

class DLinkedList : public Container
{
protected:
    DListNode *head;
    DListNode *tail;
    DListNode *curr;
public:
    DLinkedList();//The constructor sets the three members to NULL.
    ~DLinkedList();//The destructor removes all of the ListNodes
    virtual int* erase(int num);
    virtual int* find(int num);
    virtual int* insert(int num);
    int* operator-- ();
    int* operator++ ();
};

#endif /* linkedlist_hpp */
