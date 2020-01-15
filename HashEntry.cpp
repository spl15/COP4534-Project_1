/*
 *      File  : HashEntry.cpp
 *      Author: Stephen Lamalie
 *      Course: COP4534
 *      Proj  : Project 01
 */

#include "HashEntry.hpp"

HashEntry::HashEntry(std::string userId)
{
    HashEntry::userID = userId;
    setPassword();
}

std::string HashEntry::getPassword()
{
    return password;
}

std::string HashEntry::getUerID()
{
    return userID;
}

HashEntry * HashEntry::getNext()
{
    return next;
}
void HashEntry::setPassword()
{
    
    std::string tempPassword = "";
    int offset;
    char c;
    //std::string ss = HashEntry::getUerID().substr(0,3);

    
   // srand(time(0));
    for(int i =0; i<9;i++)
    {
        offset = rand() % 26;
        c = 'a' + offset;
        tempPassword = tempPassword + c;

    }

    HashEntry::password = tempPassword;
}
/*
int main()
{
    HashEntry he("stephen");

    std::cout << he.getPassword() << std::endl;


    return 0;
}
*/