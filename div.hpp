#ifndef __DIV__HPP__
#define __DIV__HPP__
#include "base.hpp"
#include <bits/stdc++.h>
using namespace std;
#include <string.h>
#include <stdexcept>

class Div : public Base {

private:
        double value1;
        double value2;
        string paraOne;
        string paraTwo;

public:
        Div(Base* para1, Base* para2) : Base() {
                value1 = para1->evaluate();
                value2 = para2->evaluate();
                paraOne = para1->stringify();
                paraTwo = para2->stringify();
         }
        virtual double evaluate() 
	{
	if( value2 == 0 ){
		throw runtime_error("Attempting to divide by zero"); 

	}//end if diviging by denomitor		

	 return (value1 /  value2);
	 }//end evaulate function

        virtual std::string stringify()
        {

                 return "(" + paraOne + "/" + paraTwo + ")";

         }//end stringify function
};

#endif
