//
//  strings.cpp
//  strings
//
//  Created by Debparna Pratiher on 7/9/16.
//  Copyright © 2016 Debparna Pratiher. All rights reserved.
//

#include "strings.hpp"
myString::myString()
{
    len = 0;
    name = 0;
}

myString::myString(char *value)
{
    if (value == NULL) //CHECK
    {
        cout<< "string is empty";
        return;
    }
    len = strlen(value);
    name = new char (len+1);
    strcpy(name, value);

}

istream &operator >>(istream& input, myString& stringName)
{
    input >> stringName.name;
    return input;
}

ostream& operator<<(ostream& output, const myString& name)
{
    output << name.name << endl;
    return output;
}

myString:: &operator <<( char *string)
{
    
}//

void myString::display()
{
    cout << name;
}

myString::~myString()
{
    //delete [];
}

//myString& myString:: operator +(const myString&)
myString& operator +(const myString& s1, const myString& s2)
{
    //myString add;
    return s1+s2;
}
/*
myString& myString:: operator -(string name2)
{
    
}
myString& myString:: operator [](string name2)
{
    
}
*/
//void operator <<(char *filename);
//void operator >>(char *filename);