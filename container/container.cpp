//
//  container.cpp
//  Containers
//
//  Created by Debparna Pratiher on 8/8/16.
//  Copyright © 2016 Debparna Pratiher. All rights reserved.
//

#include "container.hpp"

List::~List()
{
    ListNode *n = tail;
    while(n != NULL)
    {
        ListNode *p = n;
        n = n->prev;
        delete p;
    }
    
    head = NULL;
    tail = NULL;
}

void List::insert(int data)
{
    ListNode *n = new ListNode(data);
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        head->prev = n;
        n->next = head;
        head = n;
    }
    
}

void List::insertBack(int data)
{
    ListNode *n = new ListNode(data);
    if ( tail == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

void List::print()
{
    ListNode *temp = head;
    cout << "\n\nNodes in forward order:" << endl;
    while(temp != NULL)
    {
        cout << temp->data << "   " ;
        temp = temp->next;
    }
}