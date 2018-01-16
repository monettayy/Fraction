#ifndef FRACTION_H
#define FRACTION_H

#include <string>

using namespace std;

class Fraction
{
    public:
        Fraction();
        Fraction(int, int);
        Fraction(int, int, int);

        enum FractType { Proper, Improper, Mixed };

        void setWhole(int w)        {_whole = w; }
        void setNum(int n)          { _num = n; }
        void setDen(int d)          { _den = d; }
        void setType(FractType f)   { _type = f; }
        void setFraction(int, int);
        void setFraction(int, int, int);
        int getWhole()              { return _whole; }
        int getNum()                { return _num; }
        int getDen()                { return _den; }
        int getType()               { return _type; }

        double toDecimal()          { return (double)_num / _den; }
        string toString();
        void convert();
        void show();
        void lowestTerm();

        Fraction plusFraction(Fraction);
        Fraction minusFraction(Fraction);
        Fraction multiplyFraction(Fraction);
        Fraction divideFraction(Fraction);
        int compareFraction(Fraction);

        virtual ~Fraction();
    protected:

    private:
        int _whole;
        int _num;
        int _den;
        FractType _type;
};

#endif // FRACTION_H
