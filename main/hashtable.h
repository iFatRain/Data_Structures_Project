//
// Created by Michael Emperador on 4/23/18.
//

#ifndef DATA_STRUCTURES_PROJECT_HASHTABLE_H
#define DATA_STRUCTURES_PROJECT_HASHTABLE_H

#include <iostream>
#include <string>
using namespace std;

typedef void(*pass)(void);

class hashtable
{
public:
    hashtable();
    ~hashtable();
    void poparray(string key, pass functions);
    pass getfunction(string key);

protected:
    int SIZE = 403;
    pass task[503];
};



#endif //DATA_STRUCTURES_PROJECT_HASHTABLE_H
