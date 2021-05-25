#include<iostream>
/*
#include "visitor.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "div.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "rand.hpp"
*/
#include "visitorlatex.hpp"


using namespace std;

int main() {
	Base* three = new Op(3);
    	Base* seven = new Op(7);
    	Base* four = new Op(4);
    	Base* two = new Op(2);
    	Base* mult = new Mult(seven, four);
    	Base* add = new Add(three, mult);
    	Base* minus = new Sub(add, two);

	Base* one = new Op(1);
	Base* five = new Op(5);
	Base* zero = new Op(0);

	Base* test3 = new Div(two, three);
	
	Base* test4 = new Sub(five, zero);
	Base* test5 = new Add(one, test4);

	Base* test6 = new Pow(five, two);

	Base* test7 = new Mult(two, five);

	Base* test8 = new Div(test7, test6);


	VisitorLaTeX test;

	cout << test.PrintLaTeX(minus) << endl;
	cout << test.PrintLaTeX(test5) << endl;
	cout << test.PrintLaTeX(test6) << endl;
	cout << test.PrintLaTeX(test7) << endl;
	cout << test.PrintLaTeX(test3) << endl;
	cout << test.PrintLaTeX(test8) << endl;


	delete three;
	delete seven;
	delete four;
	delete two;
	delete mult;
	delete add;
	delete minus;
	delete one;
	delete five;
	delete zero;
	delete test3;
	delete test4;
	delete test5;
	delete test6;
	delete test7;
	delete test8;
	
	return 0;
}
