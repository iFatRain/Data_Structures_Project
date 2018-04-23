


//created by Connor Lathrop	4/21/2018

#include "hashtable.h"


hashtable::hashtable()
{
    //constructs array of size SIZE

}

void hashtable::poparray(string key, pass functions)
{
    int arrayval = 0;
    int hashval =0;
    int i, j;
    for (j = 0; j < key.length(); j++)
    {
        key[j] = toupper(key[j]);
    }//converts it to all caps so it isn't case sensitive

    for (i=0;i < key.length();i++)
    {
        arrayval = arrayval + int(key[i]);
    }//sums all the values for the key

    hashval = arrayval % SIZE; //hashfunction
    task[hashval] = functions;

}
pass hashtable::getfunction(string key)
{
    int arrayval = 0;
    int hashval= 0;
    int i, j;
    for (j = 0; j < key.length(); j++)
    {
        key[j] = toupper(key[j]);
    } // converts it to all caps so it isn't case sensitive

    for (i = 0; i<key.length(); i++)
    {//sums all the values for the key
        arrayval= arrayval + int(key[i]);
    }

    hashval = arrayval % SIZE; //hashfunction
    if (task[hashval] == NULL) {
        return NULL;
    }
    else
        return task[hashval];
}

hashtable::~hashtable()
{
}
