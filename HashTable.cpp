/*
 *      File  : HashTable.cpp
 *      Author: Stephen Lamalie
 *      Course: COP4534
 *      Proj  : Project 01
 */

#include "HashTable.hpp"
/*
 * basic constructor that sets all the HashEntry*s to NULL
 */
HashTable::HashTable()
{
    buckets = new HashEntry* [NUM_OF_BUCKETS];    
    for(int i = 0;i< HashTable::NUM_OF_BUCKETS;i++)
    {
        HashTable::buckets[i] = NULL;
    }
}
/*
 * destructor that deletes every entry in the table one by one by using three HashEntry* variables 
 */
HashTable::~HashTable()
{
    //start position
    int position = 0;
    // equals the first bucket
    HashEntry* tempEntry = getBucket(position);
    // whiel its one off fromt he end, this will prevent tring to acces illegal memory locations
    while(position < (NUM_OF_BUCKETS-1))
    {
        // if the first node is not empty
        if(tempEntry != NULL)
        {
            // used to iterate down the linked link
            HashEntry* currentEntry = tempEntry;
            
           while(currentEntry->getNext() != NULL) 
           {
               // the pointer to delete to keep a reference point
                HashEntry* deleteEntry = currentEntry;
                // sets the current entry to the next entry 
                currentEntry = currentEntry->getNext();
                //deletes the temporary entry
                delete deleteEntry;
           }
           delete currentEntry;

        }
        position++;
        tempEntry = getBucket(position);
    }
    // deletes the last entry
    delete tempEntry;
    // deletes the backbone of the array
    delete[] buckets;
}

/*
 * the HashFunction takes a string as a key and hashes based on the character, 
 * position of the character, and a large prime number.  
 */
int HashTable::HashFunction(std::string key)
{
    // making i a size_type to compare to a string and make compiler happy 
    std::string::size_type i;
    // total to be returned
    long long total = 0;
    // value at each individual character
    long long temp = 0;

    // for loop to iterate through the key string one character at a time
    for(i = 0; i<key.size();i++)
    {
        // 65537 just a big prime number chosen at random to garentee over 90000
        temp = (i+1) * key[i]  * 65537;
        total = total + temp;
    }

    return (total % 90000);
}

/*
 * getter to return the first entry of the linked list at bucket number given in the parameter
 */
HashEntry* HashTable::getBucket(int bucketNumber)
{
    return HashTable::buckets[bucketNumber];
}

/*
 * creates a new HashEntry object and puts it into the first location in the appropriate bin
 */
void HashTable::insertEntry(std::string tempID, std::string tempPassword )
{
    // creating a new hashEntry object
    HashEntry * tempEntry = new HashEntry(tempID);

    tempEntry->setPassword(tempPassword);
    //hashes on userID
    int placeHolder = HashFunction(tempID);

    tempEntry->setNext(getBucket(placeHolder));
   
    HashTable::buckets[placeHolder] = tempEntry;
}
/*
 * finds and returns a ptr to a Hashentry object. if none is found it prints such to console
 */
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
        return entryPtr;
    }
}