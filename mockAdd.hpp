#include "base.hpp"

class ZeroAddMock: public Base {
    public:
        ZeroAddMock() { }

        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return "(0.000000+0.000000)"; }
};

class IntAddMock: public Base {
    public:
        IntAddMock() { }

        virtual double evaluate() { return 8.0; }
        virtual std::string stringify() { return "(5.000000+3.000000)"; }
};

class IntAddMock2: public Base {
    public:
        IntAddMock2() { }

        virtual double evaluate() { return 6.0; }
        virtual std::string stringify() { return "(4.000000+2.000000)"; }
};


class NegativeAddMock: public Base {
    public:
        NegativeAddMock() { }

        virtual double evaluate() { return -1.0; }
        virtual std::string stringify() { return "(-2.000000+1.000000)"; }
};
