/*
 *      File  : HashTable.hpp
 *      Author: Stephen Lamalie
 *      Course: COP4534
 *      Proj  : Project 01
 */

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <string>
#include <iostream>
#include "HashEntry.hpp"

class HashTable
{       
    public:
        HashTable();
        void insertEntry(HashEntry *);
        void deleteEntry(HashEntry *);
        int HashFunction(std::string);

    private:
        const int NUM_OF_BUCKETS = 90000;
        HashEntry * buckets[];
};

#endif