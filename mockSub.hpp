#include "base.hpp"

class PositiveMock: public Base {
    public:
        PositiveMock() { }

        virtual double evaluate() { return 5.0; }
        virtual std::string stringify() { return "(10.000000-5.000000)"; }
};

class NegativeMock: public Base {
    public:
        NegativeMock() { }

        virtual double evaluate() { return -5.0; }
        virtual std::string stringify() { return "(5.000000-10.000000)"; }
};

class ZeroMock: public Base {
    public:
        ZeroMock() { }

        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return "(8.000000-8.000000)"; }
};


class TwoNegativeMock: public Base {
    public:
        TwoNegativeMock() { }

        virtual double evaluate() { return 4; }
        virtual std::string stringify() { return "(-5.000000--9.000000)"; }
};


