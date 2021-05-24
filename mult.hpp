#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include <bits/stdc++.h>
using namespace std;
#include <string.h>

class Mult : public Base {

private:
        double value1;
	double value2;
	string paraOne;
	string paraTwo;	

public:
        Mult(Base* para1, Base* para2) : Base() {
		value1 = para1->evaluate();
		value2 = para2->evaluate();
		paraOne = para1->stringify();
		paraTwo = para2->stringify();
	 }
        virtual double evaluate() { return (value1 * value2); }
        virtual std::string stringify() 
	{

		 return "(" + paraOne + "*" + paraTwo + ")";

	 }//end stringify function 
};

#endif
