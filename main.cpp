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
    srand(time(0));
    
    readWritePasswords("lastNames.txt");

    encryptPasswords("raw.txt");

    HashTable ht;
    HashTable* htPtr = &ht;

    createTable("encrypted.txt", htPtr);
    std::cout << changeFirstLetter("lamalie") << std::endl;
    //testEncryption("raw.txt",htPtr,5);
    
    return 0;
}
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
            /*if(count < 5)
            {
                std::cout <<  count + 1 << "." << "expected encrypted password: " << encrypt(he.getPassword(),he.getUerID()) << "\t" << "key: " << he.getUerID() << "\t" << "plain text password: "<< he.getPassword()<< std::endl;
            }*/
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
            /*
            if(count < 5)
            {
                std::cout << count + 1 << "." << "stored encrptped password: " << password  << "\t" << userID << std::endl;
            }*/
            count++;
        }

        inputTextFile.close();
    }
    else
    {
        std::cerr << "Unable to open file"<< std::endl;        
    }
    
}

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
                    
            std::cout << count + 1 << "." << "expected encrypted password: " << encrypt(password, userID) << 
            "   " <<"stored raw password: " << password  << "   " << "user ID: " <<userID << std::endl;
        
            std::cout << "     actual password in table: " << tablePtr->find(userID)->getPassword() << std::endl;


            count++;
        }
        
        inputTextFile.close();
    }
    else
    {
        std::cerr << "Unable to open file"<< std::endl;        
    }
    
}
std::string changeFirstLetter(std::string password)
{
    std::string newPassword = "";
    std::string::size_type i;
    for(i = 0;i<password.size();i++)
    {
        if(i == 0)
        {
            newPassword += password[i] + 1;
        }
        else
        {
            newPassword += password[i];
        }
    }

    return newPassword;
}