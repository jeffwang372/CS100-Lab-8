#include "base.hpp"

class TwoSquaredMock: public Base {
    public:
        TwoSquaredMock() { }

        virtual double evaluate() { return 4.0; }
        virtual std::string stringify() { return "(2.000000**2.000000)"; }
};

class ZeroRaisedMock: public Base {
    public:
        ZeroRaisedMock() { }

        virtual double evaluate() { return 1; }
        virtual std::string stringify() { return "(5.000000**0.000000)"; }
};

class ZeroRaisedZeroMock: public Base {
    public:
        ZeroRaisedZeroMock() { }

        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return "(0.000000**0.000000)"; }
};


class SixCubedMock: public Base {
    public:
        SixCubedMock() { }

        virtual double evaluate() { return 216.0; }
        virtual std::string stringify() { return "(6.000000**3.000000)"; }
};

