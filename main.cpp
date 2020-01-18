#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "HashEntry.hpp"
#include <string.h>

void readWritePasswords(std::string);
std::string encrypt(std::string, std::string);
void encryptPasswords(std::string);
int main()
{
    srand(time(0));
    
    readWritePasswords("lastNames.txt");
    encryptPasswords("raw.txt");

    std::cout << encrypt("lamaliestephen","pauljones") << std::endl;
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
            
            
        }

        inputTextFile.close();
        outputTextFile.close();
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
void readWritePasswords(std::string myString)
{
    //string variable for parsing the file line by line
    std::string line = "";

    //file to input
    std::ifstream inputTextFile(myString); 

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