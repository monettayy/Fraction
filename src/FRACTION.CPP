#include <iostream>
#include <string>
#include <sstream>

#include "Fraction.h"
#include "FractionMenu.h"

using namespace std;

Fraction::Fraction(): _whole(0), _num(0), _den(0) {}

Fraction::Fraction(int n, int d)
{
    setFraction(n, d);
}

Fraction::Fraction(int w, int n, int d)
{
    setFraction(w, n, d);
}

void Fraction::setFraction(int n, int d)
{
    _whole = 0;
    _num = n;
    _den = d;
    _type = _num < _den ? Proper : Improper;
}

void Fraction::setFraction(int w, int n, int d)
{
    _whole = w;
    _num = n;
    _den = d;
    _type = Mixed;
}

void Fraction::convert()
{
    if (_type == Mixed)
    {
        setNum(_den * _whole + _num);
        setType(Improper);
    }
    else
    {
        setWhole(_num / _den);
        setNum(_num % _den);
        setType(Mixed);
    }
    setDen(_den);
}

string Fraction::toString()
{
    stringstream stream;

    if(_type == Mixed)
        stream << _whole << " " << _num << "/" << _den;
    else
        stream << _num << "/" << _den;

    return stream.str();
}

void Fraction::show()
{
    stringstream stream;
    if(_type == Mixed)
        stream << _whole << " " << _num << "/" << _den;
    else
        stream << _num << "/" << _den;

    if(_num == _den)
        stream << " or 1";

    FractionMenu::centerText(stream.str());
}

void Fraction::lowestTerm()
{
    if(_type == Mixed)
        convert();

    Fraction f1(_num, _den);
    for(int i=1; i<_num; i++)
        for(int j=1; j<_den; j++)
        {
            Fraction f2(i, j);
            int result = f1.compareFraction(f2);
            if(result == 0)
            {
                setFraction(i, j);
                return;
            }
        }
}

Fraction Fraction::plusFraction(Fraction frac)
{
    if(_type == Mixed)
        convert();

    if (frac.getType() == 2)
        frac.convert();

    int d = _den * frac.getDen();
    int n1 = _num * frac.getDen();
    int n2 = _den * frac.getNum();
    int n = n1 + n2;

    Fraction f(n, d);
    f.lowestTerm();
    return f;
}

Fraction Fraction::minusFraction(Fraction frac)
{
    if(_type == Mixed)
        convert();

    if (frac.getType() == 2)
        frac.convert();

    int d = _den * frac.getDen();
    int n1 = _num * frac.getDen();
    int n2 = _den * frac.getNum();
    int n = n1 - n2;

    Fraction f(n, d);
    f.lowestTerm();
    return f;
}

Fraction Fraction::multiplyFraction(Fraction frac)
{
    if(_type == Mixed)
        convert();

    if (frac.getType() == 2)
        frac.convert();

    int d = _den * frac.getDen();
    int n = _num * frac.getNum();

    Fraction f(n, d);
    f.lowestTerm();
    return f;
}

Fraction Fraction::divideFraction(Fraction frac)
{
    if(_type == Mixed)
        convert();

    if (frac.getType() == 2)
        frac.convert();

    int d = _den * frac.getNum();
    int n = _num * frac.getDen();

    Fraction f(n, d);
    f.lowestTerm();
    return f;
}

int Fraction::compareFraction(Fraction frac)
{
    if(_type == Mixed)
        convert();

    if (frac.getType() == 2)
        frac.convert();

    double f = toDecimal();
    double s = frac.toDecimal();

    return f == s ? 0 : f > s ? 1 : -1;
}

Fraction::~Fraction()
{
    //dtor
}
