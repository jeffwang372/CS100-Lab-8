#include "base.hpp"

class SevenOpMock: public Base {
    public:
        SevenOpMock() { }

        virtual double evaluate() { return 7.5; }
        virtual std::string stringify() { return "7.5"; }
};

class FiveOpMock: public Base {
    public:
        FiveOpMock() { }

        virtual double evaluate() { return 5.0; }
        virtual std::string stringify() { return "5.0"; }
};

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { }

        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return "0.0"; }
};


class NegativeOpMock: public Base {
    public:
        NegativeOpMock() { }

        virtual double evaluate() { return -3; }
        virtual std::string stringify() { return "-3"; }
};


