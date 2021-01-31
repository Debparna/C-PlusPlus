//
//  strings.hpp
//  strings
//
//  Created by Debparna Pratiher on 7/9/16.
//  Copyright © 2016 Debparna Pratiher. All rights reserved.
//

#ifndef mstrings_hpp
#define mstrings_hpp

#include <iostream>
#include <string>
using namespace std;

class myString
{
    //string name;
    char *name;
    size_t len;
public:
    myString();
    myString(char *value);
    ~myString();
    void display();
    //char getString(char *name);
    //char setString(char *name);
    friend ostream &operator <<(ostream& output, const myString& name);
    friend istream &operator >>(istream& input, myString& stringName);
    
    myString& operator +(const myString&);
    //myString& operator -(string name2);????
    char *operator [](int no);
    myString& operator +(char *srt);
    //myString& operator =(const myString&);
    myString &operator <<(char *string);  //
    myString &operator >>(char *str); //
    
};


#endif /* strings_hpp */
