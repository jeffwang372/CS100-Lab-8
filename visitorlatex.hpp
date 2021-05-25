#ifndef __VISITORLATEX_HPP__
#define __VISITORLATEX_HPP__

#include "visitor.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "div.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "rand.hpp"

#include "iterator.hpp"
#include <iostream>
#include <string>


using namespace std;

class VisitorLaTeX: public Visitor {
	private:
		string result = "";
	public:

		virtual void visit_op(Op* node) {
			this->result = this->result + "{" + to_string(node->evaluate()) + "}";
		}
        	virtual void visit_rand(Rand* node) {
			this->result = this->result + "{" + to_string(node->evaluate()) + "}";
		}
		
		virtual void visit_add_begin(Add* node) { 
			this->result = this->result + "{(";
		}
        	virtual void visit_add_middle(Add* node) {
			this->result = this->result + "+";
		}
        	virtual void visit_add_end(Add* node) {
			this->result = this->result + ")}";
		}
        	virtual void visit_sub_begin(Sub* node) {
			this->result = this->result + "{(";
		}
        	virtual void visit_sub_middle(Sub* node) {
			this->result = this->result + "-";

		}
        	virtual void visit_sub_end(Sub* node) {
			this->result = this->result + ")}";
		}
        	virtual void visit_mult_begin(Mult* node) {
			this->result = this->result + "{(";
		}
        	virtual void visit_mult_middle(Mult* node) {
			this->result = this->result + "\\cdot";

		}
        	virtual void visit_mult_end(Mult* node) {
			this->result = this->result + ")}";
		}
        	virtual void visit_div_begin(Div* node) {
			this->result = this->result + "{\\frac";
		}
        	virtual void visit_div_middle(Div* node) {

		}
        	virtual void visit_div_end(Div* node) {
			this->result = this->result + "}";
		}
        	virtual void visit_pow_begin(Pow* node) {
			this->result = this->result + "{(";
		}
        	virtual void visit_pow_middle(Pow* node)  {
			result = result + "^";

		}
        	virtual void visit_pow_end(Pow* node) {
			this->result = this->result + ")}";
		}
		
		string PrintLaTeX(Base* ptr) {
			result = "$";
			
			for(Iterator it(ptr); !it.is_done();it.next()) {
					it.current_node()->accept(this, it.current_index());
			}
			
			result = result + "$";
				
			return result;
		}



};

#endif
