#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
   
private:
	double value;

public:
        Op(double value) : Base() {this->value = value; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value); }


        virtual int number_of_children(){ return 0;}

        virtual Base* get_child(int i){

		return nullptr;
        }//end get get child

	 virtual void accept(Visitor* visitor, int index) {

                visitor->visit_op(this);

        }//end visitor




};

#endif //__OP_HPP__
