# COP4534-Project_1
# Stephen Lamalie
# User Manual

	This program will create a simple hash table of usernames and passwords using external chaining. The program takes a 
file name as input to a function(lastnames.txt by default), reads the first column and takes it in as a list of unique last names to be used as a key for the hash table. The program then creates a random 9 charcter string as a password(all lower case for simplicity) for every user ID. The program then writes the information to a file named raw.txt(by default). The program will then read the user IDs and passwords in raw.txt and encrypts the passwords using the vigenere cipher. The program will then write the user ID and encrypted password to a file named encrypted.txt(by default). At this point the program creates the hash table from the data in encrypted.txt. With the hash table in place the program will test a number of entries in the has table(five by default) by reading the number of entries from raw.txt(with plain text passwords), encrypting the passwords, and hashing into the table to verify that the passwords match. The program will also test the encryption after changing the first letter of the password to verify that the passwords do NOT match at this point. a smaple output is included in this write up.  

	The following files are included in the zip file for this project:

	* HashEntry.hpp
	* HashTable.hpp
	* HashEntry.cpp
	* HashTable.cpp
	* main.cpp
	* Makefile
	* lastnames.txt
	* Project_1_classDiadram.pdf
	* README.md(this file)

	The program has been tested and ran on a linux based environment and is designed to be used in such. No user inpout is required for this program  in any way.

	The program has a Makefile included which will create a excutable named hash. To run the program type tyhe make command in the command line while in this folders directory to create the hash excutable, then type ./hash to run.The Makefile will also utilize a make run function for easy testing to do all of this in one step. When running the program the file lastname.txt needs to be in the same folder or will not produce the desired outcome.

output goes to colsole:
EXPECTED SAMPLE OUTPUT:

1.Expected encrypted password: krpaplpsx   Stored raw password: sfhhitdke   User ID: smith
     Actual password in table: krpaplpsx
  First letter does not match: lrpaplpsx

2.Expected encrypted password: kzshxecbz   Stored raw password: bllufqpsl   User ID: johnson
     Actual password in table: kzshxecbz
  First letter does not match: lzshxecbz

3.Expected encrypted password: oeklumwav   Stored raw password: swzammkiz   User ID: williams
     Actual password in table: oeklumwav
  First letter does not match: peklumwav

4.Expected encrypted password: jnfqjjjlm   Stored raw password: azsmravyi   User ID: jones
     Actual password in table: jnfqjjjlm
  First letter does not match: knfqjjjlm

5.Expected encrypted password: qvjpshxph   Stored raw password: pevtfggbl   User ID: brown
     Actual password in table: qvjpshxph
  First letter does not match: rvjpshxph





