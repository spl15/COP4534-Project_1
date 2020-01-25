/*
 *      File  : HashTable.cpp
 *      Author: Stephen Lamalie
 *      Course: COP4534
 *      Proj  : Project 01
 */

#include "HashTable.hpp"

HashTable::HashTable()
{
    
    for(int i = 0;i< HashTable::NUM_OF_BUCKETS;i++)
    {
        HashTable::buckets[i] = NULL;
    }
}

int HashTable::HashFunction(std::string key)
{
    std::string::size_type i;
    long long total = 0;
    long long temp = 0;
    for(i = 0; i<key.size();i++)
    {
        temp = (i+1) * key[i]  * 65537;
        total = total + temp;
    }

    return (total % 90000);
}

HashEntry* HashTable::getBucket(int bucketNumber)
{
    return HashTable::buckets[bucketNumber];
}

void HashTable::insertEntry(std::string tempID, std::string tempPassword )
{
    HashEntry * tempEntry = new HashEntry(tempID);
    tempEntry->setPassword(tempPassword);

    int placeHolder = HashFunction(tempID);

    tempEntry->setNext(getBucket(placeHolder));
   
    HashTable::buckets[placeHolder] = tempEntry;
}
HashEntry* HashTable::find(std::string tempUser)
{

    bool found = false;
    int placeholder = HashTable::HashFunction(tempUser);
    
    HashEntry* entryPtr = NULL;
    {
        
        if(HashTable::getBucket(placeholder) != NULL)
        {
            HashEntry* currentEntry = HashTable::getBucket(placeholder);
           while(currentEntry->getNext() != NULL) 
           {
                if(currentEntry->getUerID().compare(tempUser) == 0)
                {
                    found = true;
                    entryPtr = currentEntry;
                }

                currentEntry = currentEntry->getNext();
           }

           if(currentEntry->getUerID().compare(tempUser) == 0)
                {
                    found = true;
                    entryPtr = currentEntry;
                }
        }
    }
    if(!found)
    {
        std::cout << tempUser << " is NOT in the table " << std::endl;
        return entryPtr;
    }
    else
    {
        //std::cout << tempUser << " is in the table in bucket #" << placeholder << std::endl;
        return entryPtr;
    }
}