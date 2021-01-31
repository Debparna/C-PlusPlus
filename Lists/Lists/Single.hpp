//
//  Single.hpp
//  Lists
//
//  Created by Debparna Pratiher on 9/4/16.
//  Copyright © 2016 Debparna Pratiher. All rights reserved.
//

#ifndef Single_hpp
#define Single_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstring>
using namespace std;

class ListNode
{
    int data;
    ListNode *prev;
    ListNode *next;
public:
      ListNode(int data);
    ~ListNode();
    friend class LinkedList;
};

class LinkedList
{
    ListNode *tail;
    ListNode *head;
    ListNode *curr;
public:
    LinkedList();
    ~LinkedList();
    void insert(int newItem);
    void insertBack(int newItem);
    void deleteList(int deleteItem);
    bool find(int searchItem);
    void print();
    void find(char name);
};

#endif /* Single_hpp */
