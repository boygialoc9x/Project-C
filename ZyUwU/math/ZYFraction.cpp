#include "ZYFraction.h"

NS_ZY_BEGIN

const Fraction Fraction::DEFAULT(0, 1);

//Constructor
Fraction::Fraction(int nNumerator, int nDenominator)
{
    this->m_nDenominator = nDenominator;
    this->m_nNumerator = nNumerator;
    if(!isValid())
    {
        this->m_nNumerator = DEFAULT.m_nNumerator;
        this->m_nDenominator = DEFAULT.m_nDenominator;
    }
    this->autoValid();
    this->setMemory();
}

Fraction::Fraction(const Fraction& f)
{
    if(!f.isValid())
    {
        this->m_nNumerator = DEFAULT.m_nNumerator;
        this->m_nDenominator = DEFAULT.m_nDenominator;
        return;
    }
    this->m_nNumerator = f.getNumerator();
    this->m_nDenominator = f.getDenominator();
    this->autoValid();
    this->setMemory();
}

//Public
void Fraction::shortCut()
{
    int first, second;

    first = abs(this->m_nNumerator);
    second = abs(this->m_nDenominator);

    while (first != second)
    {
        if (first > second)
        {
            first -= second;
        }
        else
        {
            second -= first;
        }
    }
    this->m_nNumerator /= first;
    this->m_nDenominator /= second;
}

void Fraction::reduceFraction(Fraction &f, bool bIsShortCut)
{
    if (!f.isValid()) return;
    if (bIsShortCut)
    {
        f.shortCut();
        this->shortCut();
    }
    auto nLCM = SmartAlgorithm::findLCM(this->getDenominator(), f.getDenominator(), NULL);

    this->setNumerator(nLCM/this->getDenominator()*this->getNumerator());
    this->setDenominator(nLCM);

    f.setNumerator(nLCM/f.getDenominator()*f.getNumerator());
    f.setDenominator(nLCM);
}

void Fraction::log()
{
    CCLOG("FRACTION: %d/%d = %f", this->m_nNumerator, this->m_nDenominator, this->toFloat());
}

float Fraction::toFloat()
{
    return (float)(this->m_nNumerator ) / (float)(this->m_nDenominator);
}

//Static
Fraction Fraction::fastShortCut(int nNumerator, int nDenominator)
{
    Fraction scF(nNumerator, nDenominator);
    scF.shortCut();

    return scF;
}

void Fraction::add(Fraction& f1, Fraction& f2, Fraction *dst, bool bIsShortCut)
{
    GP_ASSERT(dst);

    if(!f1.isValid() || !f2.isValid())
    {
        return;
    }
    auto sub = f1+f2;
    dst->setNumerator(sub.getNumerator());
    dst->setDenominator(sub.getDenominator());
}

void Fraction::subtract(Fraction& f1, Fraction& f2, Fraction *dst, bool bIsShortCut)
{
    GP_ASSERT(dst);

    if(!f1.isValid() || !f2.isValid())
    {
        return;
    }
    auto sub = f1-f2;
    dst->setNumerator(sub.getNumerator());
    dst->setDenominator(sub.getDenominator());
}

void Fraction::multiple(Fraction& f1, Fraction& f2, Fraction *dst, bool bIsShortCut)
{
    GP_ASSERT(dst);

    if(!f1.isValid() || !f2.isValid())
    {
        return;
    }
    auto sub = f1*f2;
    dst->setNumerator(sub.getNumerator());
    dst->setDenominator(sub.getDenominator());
}

void Fraction::divide(Fraction& f1, Fraction& f2, Fraction *dst, bool bIsShortCut)
{
    GP_ASSERT(dst);

    if(!f1.isValid() || !f2.isValid())
    {
        return;
    }
    auto sub = f1/f2;
    dst->setNumerator(sub.getNumerator());
    dst->setDenominator(sub.getDenominator());
}

float Fraction::toFloat(Fraction f)
{
    return f.toFloat();
}

Fraction Fraction::toFraction(float fNumber)
{
    float fIntegral = std::floor(fNumber);
    float fFrac = fNumber - fIntegral;

    int nGCD = SmartAlgorithm::findGCD(round(fFrac * MAXRATE), MAXRATE);

    int nDenominator = MAXRATE/nGCD;
    int nNumerator = round(fFrac * MAXRATE)  / nGCD;

    return Fraction(nNumerator, nDenominator);
}
//Private
bool Fraction::isValid()
{
    if(m_nDenominator == 0) {
        CCLOG("FRACTION: Invalid fraction. The denominator can not be 0");
        return false;
    }
    return true;
}

bool Fraction::isValid() const
{
    if(m_nNumerator == 0) {
        CCLOG("FRACTION: Invalid fraction. The denominator can not be 0");
        return false;
    }
    return true;
}

//Protected
void Fraction::setMemory()
{
    this->p_nNumeratorMem = this->m_nNumerator;
    this->p_nDenominatorMem = this->m_nDenominator;
}

void Fraction::loadMemory()
{
    this->m_nNumerator = this->p_nNumeratorMem;
    this->m_nDenominator = this->p_nDenominatorMem;
}

void Fraction::autoValid()
{
    if( this->m_nDenominator >= 0 && this->m_nNumerator <= 0)
        return;
    else if(this->m_nDenominator >= 0 && this->m_nNumerator >= 0)
        return;
    this->setDenominator(m_nDenominator*(-1));
    this->setNumerator(m_nNumerator*(-1));
}

//
Fraction Fraction::clone()
{
    Fraction fraction(this->getNumerator(), this->getDenominator());

    return fraction;
}

void Fraction::add(Fraction& f, bool bIsShortCut)
{
    this->reduceFraction(f, bIsShortCut);

    this->setNumerator(this->getNumerator() + f.getNumerator());

    if(bIsShortCut) this->shortCut();
    f.loadMemory();

    this->autoValid();
}

void Fraction::subtract(Fraction& f, bool bIsShortCut)
{
    this->reduceFraction(f, bIsShortCut);

    this->setNumerator(this->getNumerator() - f.getNumerator());

    if(bIsShortCut) this->shortCut();
    f.loadMemory();

    this->autoValid();
}

void Fraction::multiple(Fraction &f, bool bIsShortCut)
{
    if(!f.isValid()) return;
    this->setNumerator(this->getNumerator() * f.getNumerator());
    this->setDenominator(this->getDenominator() * f.getDenominator());
    if(bIsShortCut) this->shortCut();

    this->autoValid();
}

void Fraction::divide(Fraction &f, bool bIsShortCut)
{
    if(!f.isValid()) return;
    this->setNumerator(this->getNumerator()*f.getDenominator());
    this->setDenominator(this->getDenominator()*f.getNumerator());
    if(!this->isValid())
    {
        this->loadMemory();
        return;
    }
    if (bIsShortCut) this->shortCut();
    this->autoValid();
}

void Fraction::negate()
{
    this->m_nNumerator*(-1);
}

//operator
Fraction Fraction::operator+(Fraction &f)
{
    Fraction result(*this);
    result.add(f);
    return result;
}

Fraction Fraction::operator+=(Fraction &f)
{
    this->add(f);
    return *this;
}

Fraction Fraction::operator-(Fraction& f)
{
    Fraction result(*this);
    result.subtract(f);
    return result;
}

Fraction Fraction::operator-=(Fraction &f)
{
    this->subtract(f);
    return *this;
}

Fraction Fraction::operator-()
{
    Fraction result(*this);
    result.negate();
    return result;
}

Fraction Fraction::operator*(Fraction &f)
{
    Fraction result(*this);
    result.multiple(f);
    return result;
}

Fraction Fraction::operator*=(Fraction &f)
{
    this->multiple(f);
    return *this;
}

Fraction Fraction::operator/(Fraction &f)
{
    Fraction result(*this);
    result.divide(f);
    return result;
}

Fraction Fraction::operator/=(Fraction &f)
{
    this->divide(f);
    return *this;
}

bool Fraction::operator==(Fraction &f)
{
    bool bIs = false;

    this->shortCut();
    f.shortCut();

    if(this->getNumerator() == f.getNumerator() && this->getDenominator() == f.getDenominator())
        bIs = true;

    this->loadMemory();
    f.loadMemory();

    return bIs;
}

bool Fraction::operator!=(Fraction &f)
{
    return !this->operator==(f);
}

bool Fraction::operator<(Fraction& f)
{
    bool bIs = false;
    this->reduceFraction(f);

    if(this->getNumerator() < f.getNumerator())
        bIs = true;

    this->loadMemory();
    f.loadMemory();

    return bIs;
}

bool Fraction::operator>(Fraction &f)
{
    bool bIs = false;
    this->reduceFraction(f);

    if(this->getNumerator() > f.getNumerator())
        bIs = true;

    this->loadMemory();
    f.loadMemory();

    return bIs;

}

bool Fraction::operator>=(Fraction& f)
{
    return !this->operator<(f);
}

bool Fraction::operator<=(Fraction& f)
{
    return !this->operator>(f);
}

NS_ZY_END