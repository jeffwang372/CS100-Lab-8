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
	Base* right;
	Base* left;

public:
        Div(Base* para1, Base* para2) : Base() {
                value1 = para1->evaluate();
                value2 = para2->evaluate();
                paraOne = para1->stringify();
                paraTwo = para2->stringify();
		right = para2;
		left = para1;
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


        virtual int number_of_children(){ return 2;}

        virtual Base* get_child(int i){

                if( i == 0 ) {
                        return left;
                }

                else if ( i == 1 ) {
                        return right;
                }

        }//end get get child



        virtual void accept(Visitor* visitor, int index) {

                if(index == 0) {
                visitor->visit_div_begin(this);
                }

                else if ( index == 1 ){
                visitor->visit_div_middle(this);
                }

                else if ( index == 2) {
                visitor->visit_div_end(this);
                }

        }//end visitor


};

#endif
