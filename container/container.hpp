//
//  container.hpp
//  Containers
//
//  Created by Debparna Pratiher on 8/8/16.
//  Copyright © 2016 Debparna Pratiher. All rights reserved.
//

#ifndef container_hpp
#define container_hpp

using namespace std;


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
    virtual int* insert(int num) = 0; //which inserts the num into the container, and returns a pointer to the int in the container.
}; // class Container

#endif /* container_hpp */
