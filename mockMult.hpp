#include "base.hpp"

class ZeroMultMock: public Base {
    public:
        ZeroMultMock() { }

        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return "(0.000000*0.000000)"; }
};

class IntMultMock: public Base {
    public:
        IntMultMock() { }

        virtual double evaluate() { return 15.0; }
        virtual std::string stringify() { return "(5.000000*3.000000)"; }
};

class IntMultMock2: public Base {
    public:
        IntMultMock2() { }

        virtual double evaluate() { return 8.0; }
        virtual std::string stringify() { return "(4.000000*2.000000)"; }
};


class NegativeMultMock: public Base {
    public:
        NegativeMultMock() { }

        virtual double evaluate() { return -2.0; }
        virtual std::string stringify() { return "(-2.000000*1.000000)"; }
};
