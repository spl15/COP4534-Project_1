/*
 *      File  : HashEntry.cpp
 *      Author: Stephen Lamalie
 *      Course: COP4534
 *      Proj  : Project 01
 */

#include "HashEntry.hpp"

/*
 * HashEntry constructor that sets the user ID to the parameter given
 * but converts the ID to lower case first
 */
HashEntry::HashEntry(std::string userId)
{
    // character to help convert the userID to lowercase for the encryption alg
    char c;
    // the string to be returned
    std::string temp;
    // to make the compiler happy
    std::string::size_type i;
    // for loop to go through the user ID character by character to convert it to lower case
    for(i=0;i<userId.size();i++)
    {
        c = std::tolower(userId[i]);
        temp = temp + c;
    } 
    HashEntry::userID = temp;
    //sets the HashEntry objects next ptr to NULL to avoid undefinded behavior
    HashEntry::next = NULL;
}
/*
 * getter for returning the password
 */
std::string HashEntry::getPassword()
{
    return password;
}
/*
 * getter for returning the userID
 */
std::string HashEntry::getUerID()
{
    return userID;
}
/*
 * getter for returning the next HashEntry* int he linked list 
 */
HashEntry * HashEntry::getNext()
{
    return next;
}
/*
 * setter for setting the password 
 */
void HashEntry::setPassword(std::string myPassword)
{
    HashEntry::password = myPassword;
} 
/*
 * setter for setting the passwords to a random 9 character array
 */
void HashEntry::setRandomPassword()
{
    // temp password to be returned
    std::string tempPassword = "";
    // the random number to be added to a character
    int offset;
    // the character to be manipulating
    char c;
    // for loop to loop through 9 characters and set them to random values    
    for(int i =0; i<9;i++)
    {
        // random number from 0 to  25
        offset = rand() % 26;
        // adds 0-25 to the a character making it a random character
        c = 'a' + offset;
        tempPassword = tempPassword + c;

    }

    HashEntry::password = tempPassword;
}
/*
 * setter to set the next ptr 
 */
void HashEntry::setNext(HashEntry* tempNext)
{
    HashEntry::next = tempNext;
}
