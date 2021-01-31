//
//  Double.hpp
//  Lists
//
//  Created by Debparna Pratiher on 9/4/16.
//  Copyright © 2016 Debparna Pratiher. All rights reserved.
//

#ifndef Double_hpp
#define Double_hpp

#include <stdio.h>

class DListNode
{
    int data;
    DListNode *previous;
    DListNode *next;
    DListNode(int d, DListNode *p, DListNode *n);
    friend class LinkedList;
   
};

class DLinkedList
{
protected:
    DListNode *head;
    DListNode *tail;
    DListNode *curr;
public:
    DLinkedList();
    ~DLinkedList();
    virtual int* erase(int num);
    virtual int* find(int num);
    virtual int* insert(int num);
    int* operator-- ();
    int* operator++ ();
}; // class LinkedList


#endif /* Double_hpp */

/*
 class Container
 {
 protected:
 int size;
 public:
 Container(int siz);
 virtual ~Container();
 int getSize() const;
 virtual int* erase(int num) = 0;
 virtual int* find(int num) = 0;
 virtual int* insert(int num) = 0;
 }; // class Container
 
 class ListNode{
 int data;
 ListNode *prev;
 ListNode *next;
 friend class LinkedList;
 ListNode(int d, ListNode *p, ListNode *n);
 };
 
 class LinkedList: public Container{
 protected:
 ListNode *head;
 ListNode *tail;
 ListNode *curr;
 public:
 LinkedList();
 ~LinkedList();
 virtual int* erase(int num);
 virtual int* find(int num);
 virtual int* insert(int num);
 };
 
 ListNode::ListNode(int d, ListNode *p, ListNode *n): data(d), prev(p), next(n){
 }
 
 LinkedList::LinkedList() : Container(0), head(NULL), tail(NULL), curr(NULL){
 
 }
 
 LinkedList::~LinkedList(){
 for( curr = head; curr; curr = head){
 
 }
 }

*/