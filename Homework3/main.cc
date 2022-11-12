#include <iostream>
#include <vector> 
#include "polynomial.h"

//usage .\polynom 0 1 2 3 4 5 6 0

int main(int argc, char** argv)
{
    if (argc % 2 == 0 || argc < 3)
	{
		std::cout<<"Incorrect amount of arguments is provided."<<std::endl;
		return 1;
	}

    Linux103::Polynomial p;

    int c, d;
	for (int i = 1; i < argc; i++)
	{        
        double num = atof(argv[i]);
        if(i%2 == 0) { 
            d = num;
            p.add(c, d); 
        }   
        else {
            c = num;
        }
	}

    p.print();
    std::cout<<"P(1) = " << p.calculate(1) << std::endl;

    Linux103::Polynomial der = p.derive();
    der.print();
    
    return 0;
}