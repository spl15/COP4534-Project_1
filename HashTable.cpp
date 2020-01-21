/*
 *      File  : HashTable.cpp
 *      Author: Stephen Lamalie
 *      Course: COP4534
 *      Proj  : Project 01
 */

#include "HashTable.hpp"


HashTable::HashTable()
{
    HashTable::buckets[NUM_OF_BUCKETS];
    for(int i = 0;i<NUM_OF_BUCKETS;i++)
    {
        buckets[i] = NULL;
    }
}

int HashFunction(std::string key)
{
    int total = 0;
    int temp = 0;
    for(int i = 0; i<key.length();i++)
    {
        temp =key[i] ;
        total = total + temp;
    }

    return (total );
}

int main()
{

	std::cout << HashFunction("kyle") << std::endl;
	 std::cout << HashFunction("josh") << std::endl;
	  std::cout << HashFunction("pete") << std::endl;
	   std::cout << HashFunction("Johnsone") << std::endl;
	    std::cout << HashFunction("u") << std::endl;
	     std::cout << HashFunction("sakjgnkjrn") << std::endl;
	      std::cout << HashFunction("bob") << std::endl;
	       std::cout << HashFunction("a") << std::endl;
	        std::cout << HashFunction("b") << std::endl;
		 std::cout << HashFunction("ab") << std::endl;


	return 0;
}
