#include <iostream>
#include <string.h>\
	


int main()
{
	std::string temp = "Smith";
	int c = 0;

	for(int i = 0;i <100;i++)
	{
		 	
		std::cout << c << std::endl;
		c = (c + 1) % 10;
	}


	return 0;
}
