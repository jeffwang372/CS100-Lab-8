#include "base.hpp"

class ZeroDivMock: public Base {
    public:
        ZeroDivMock() { }

        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return "(0.000000/1.000000)"; }
};

class IntDivMock: public Base {
    public:
        IntDivMock() { }

        virtual double evaluate() { return 2.0; }
        virtual std::string stringify() { return "(6.000000/3.000000)"; }
};

class IntDivMock2: public Base {
    public:
        IntDivMock2() { }

        virtual double evaluate() { return 2.0; }
        virtual std::string stringify() { return "(4.000000/2.000000)"; }
};


class NegativeDivMock: public Base {
    public:
        NegativeDivMock() { }

        virtual double evaluate() { return -2.0; }
        virtual std::string stringify() { return "(-2.000000/1.000000)"; }
};
