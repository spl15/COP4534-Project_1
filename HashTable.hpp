/*
 *      File  : HashTable.hpp
 *      Author: Stephen Lamalie
 *      Course: COP4534
 *      Proj  : Project 01
 */

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "HashEntry.hpp"

class HashTable
{       
    public:
        HashTable();
        ~HashTable();
        void insertEntry(std::string, std::string);
        HashEntry* find(std::string);
        //void deleteEntry(HashEntry *);
        int HashFunction(std::string);
        HashEntry* getBucket(int);

    private:
        const int NUM_OF_BUCKETS = 90000;
        HashEntry** buckets;
};

#endif