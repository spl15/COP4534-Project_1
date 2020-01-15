#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "HashEntry.hpp"
#include <string.h>

void readWritePasswords();

int main()
{
    srand(time(0));
    
    readWritePasswords();

    std::cout << "done" << std::endl;
    return 0;
}

void readWritePasswords()
{
    //string variable for parsing the file line by line
    std::string line = "";

    //file to input
    std::ifstream inputTextFile("lastNames.txt"); 

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