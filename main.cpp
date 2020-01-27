#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "HashEntry.hpp"
#include <string.h>
#include "HashTable.hpp"

void readWritePasswords(std::string);
std::string encrypt(std::string, std::string);
void encryptPasswords(std::string);
void createTable(std::string, HashTable*);
void testEncryption(std::string, HashTable*, int);
std::string changeFirstLetter(std::string);


int main(int argc, char *argv[])
{
    // to seed a random time varibale
    srand(time(0));
    //reads the last names and creates random password for each
    readWritePasswords("lastNames.txt");
    // reads passwords and encrypts them
    encryptPasswords("raw.txt");

    HashTable ht;
    HashTable* htPtr = &ht;

    createTable("encrypted.txt", htPtr);
    //test the first 5 entries
    testEncryption("raw.txt",htPtr,5);
    
    return 0;
}

/*
 * a method to take the file given as a parameter and encrypt the passwords(second column)
 * and out put the results into a file named encrypted.txt
 */
void encryptPasswords(std::string myString)
{
    //string variable for parsing the file line by line
    std::string line = "";

    //file to input
    std::ifstream inputTextFile(myString); 

    //check if the file is open
    if(inputTextFile.is_open())
    {

        std::ofstream outputTextFile("encrypted.txt");
        int count = 0;

        while(getline(inputTextFile, line))
        {
            //finds the first space position
            int spacePosition = line.find(" ");
            //stores the first word in line 
            std::string userID = line.substr(0,spacePosition);
            //stores the next column assumed to be password field
            ++spacePosition;
            std::string password =line.substr(spacePosition);
            HashEntry he(userID);
            he.setPassword(password);
            outputTextFile << he.getUerID() << " " << encrypt(he.getPassword(),he.getUerID()) << std::endl;
            count++;
            
        }

        inputTextFile.close();
        outputTextFile.close();
    }
    else
    {
        std::cerr << "Unable to open file"<< std::endl;        
    }
    
}
/*
 * creates the HashTable from a file given as a string in the parameter
 * 
 */
void createTable(std::string myString, HashTable* tablePtr)
{
    int count = 0;
    //string variable for parsing the file line by line
    std::string line = "";

    //file to input
    std::ifstream inputTextFile(myString); 

   
    //check if the file is open
    if(inputTextFile.is_open())
    {

       


        while(getline(inputTextFile, line))
        {
            //finds the first space position
            int spacePosition = line.find(" ");
            //stores the first word in line 
            std::string userID = line.substr(0,spacePosition);
            //stores the next column assumed to be password field
            ++spacePosition;
            std::string password =line.substr(spacePosition);
            tablePtr->insertEntry(userID,password);
            count++;
        }

        inputTextFile.close();
    }
    else
    {
        std::cerr << "Unable to open file"<< std::endl;        
    }
    
}

/*
 * encrypt function that encrypts on a vigenere cipher. Taking the first parameter 
 * as the string to encrypt(password), and trhe second string as the key(userID) 
 */
std::string encrypt(std::string tempIn, std::string key)
{
    //needed type to make compiler happy when comparing strings and ints
    std::string::size_type i;
    //placeholder to hold the place of the index of the key
    int j = 0;
    //the output string being built(added to)
    std::string tempOut = "";

    for(i = 0; i < tempIn.size();i++)
    {
        char c;
        if(((tempIn[i] - 'a') + key[j]) <= 'z')
        {
            c = (tempIn[i] - 'a') + key[j];
        }
        else
        {
            c = (tempIn[i] - 'a') + key[j] - 26;
        }
        
        tempOut = tempOut + c;
        //at the end of the string the index will return to position 0
        j = (j + 1) % key.size();

    }

    return tempOut;
}
/*
 * reads the first column of a file in as user names and creates a random
 * password to match. Them stores the entries into a file named raw.txt
 */
void readWritePasswords(std::string myFile)
{
    //string variable for parsing the file line by line
    std::string line = "";

    //file to input
    std::ifstream inputTextFile(myFile); 

    //check if the file is open
    if(inputTextFile.is_open())
    {

        std::ofstream outputTextFile("raw.txt");


        while(getline(inputTextFile, line))
        {
            //finds the first space position
            int spacePosition = line.find(" ");
            //stores the first word in line 
            std::string userID = line.substr(0,spacePosition);
            
            HashEntry he(userID);
            he.setRandomPassword();
            outputTextFile << he.getUerID() << " " << he.getPassword() << std::endl;
            
            
        }

        inputTextFile.close();
        outputTextFile.close();
    }
    else
    {
        std::cerr << "Unable to open file"<< std::endl;        
    }
    
}
/*
 * function to test the encryption to make sure what is output is the desired output. takes the first parameter as the file name,
 * the HashTable object ptr as the second parameter, and the number of lines(entries) to test 
 */
void testEncryption(std::string file, HashTable* tablePtr, int numToTest)
{
    int count = 0;
    //string variable for parsing the file line by line
    std::string line = "";

    //file to input
    std::ifstream inputTextFile(file); 

   
    //check if the file is open
    if(inputTextFile.is_open())
    {

       


        while(count < numToTest)
        {
            getline(inputTextFile, line);
            //finds the first space position
            int spacePosition = line.find(" ");
            //stores the first word in line 
            std::string userID = line.substr(0,spacePosition);
            //stores the next column assumed to be password field
            ++spacePosition;
            std::string password =line.substr(spacePosition);
                    
            std::cout << count + 1 << "." << "Expected encrypted password: " << encrypt(password, userID) << 
            "   " <<"Stored raw password: " << password  << "   " << "User ID: " <<userID << std::endl;
        

            std::cout << "     Actual password in table: " << tablePtr->find(userID)->getPassword() << std::endl;

            std::cout << "  First letter does not match: " << encrypt(changeFirstLetter(password), userID) << "\n" << std::endl;
            
            count++;
        }
        
        inputTextFile.close();
    }
    else
    {
        std::cerr << "Unable to open file"<< std::endl;        
    }
    
}
/*
 * changes the first letter of a string to the next letter unless 'z' then changes to 'y'
 */
std::string changeFirstLetter(std::string password)
{
    std::string newPassword = "";
    std::string::size_type i;
    for(i = 0;i<password.size();i++)
    {
        if(i == 0)
        {
            if(password[i] == 'z')
            {
                newPassword += password[i] - 1;
            }
            else
            {
                newPassword += password[i] + 1;
            }
                
        }
        else
        {
            newPassword += password[i];
        }
    }

    return newPassword;
}