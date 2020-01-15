/*
 *      File  : HashEntry.hpp
 *      Author: Stephen Lamalie
 *      Course: COP4534
 *      Proj  : Project 01
 */

#ifndef HASHENTRY_HPP
#define HASHENTRY_HPP
#include <string>
#include <iostream>

class HashEntry
{       
    public:
        HashEntry(std::string userId);
        std::string getPassword();
        std::string getUerID();
        void setPassword();
        HashEntry* getNext();
        

    private:
        std::string userID;
        std::string password;
        HashEntry * next;
};

#endif