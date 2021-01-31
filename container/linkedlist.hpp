//
//  linkedlist.hpp
//  Containers
//
//  Created by Debparna Pratiher on 8/18/16.
//  Copyright © 2016 Debparna Pratiher. All rights reserved.
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

class ListNode
{
    int data;
    ListNode *next;
    ListNode *prev;
public:
    ListNode(int data);
    ~ListNode();
    friend class List;
    
};

class List
{
    ListNode *head;
    ListNode *tail;
public:
    List();
    ~List();
    void insert(int data);
};

#endif /* linkedlist_hpp */
