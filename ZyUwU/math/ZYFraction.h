#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "cocos2d.h"
#include "../platform/ZYMacros.h"
#include "SmartAlgorithm.h"

NS_ZY_BEGIN

const int MAXRATE = 1000000000;

class Fraction
{
public:
    Fraction(int nNumerator = 0, int nDenominator = 1);
    Fraction(const Fraction &f);
public:
    /**
     * Shortcut this fraction
     */
    void shortCut();
    void log();
    Fraction clone();
    void reduceFraction(Fraction& f, bool bIsShortCut = true);

    void add(Fraction& f, bool bIsShortCut = true);
    void subtract(Fraction& f, bool bIsShortCut = true);
    void multiple(Fraction& f, bool bIsShortCut = true);
    void divide(Fraction& f, bool bIsShortCut = true);
    void negate();
    float toFloat();
protected:
    void setMemory();
    void loadMemory();
    void autoValid();
public:
    /**
     * Create a new fraction then shortcut it
     *
     * @pragma nNumerator: the numerator of the fraction
     * @pragma nDenominator: the denominator of the fraction
     * @return The shortcut fraction
     */
    static Fraction fastShortCut(int nNumerator, int nDenominator);

    /**
     * Get the fraction in decimal
     *
     * @pragma f: the fraction to be converted
     * @return The fraction in decimal
     */
    static float toFloat(Fraction f);

    static Fraction toFraction(float fNumber);

    /**
     * Adds the specified fractions and stores the result in dst.
     *
     * @pragma f1: The first fraction
     * @pragma f2: The second fraction
     * @pragma dst: A Fraction to store the result in
     * @pragma bIsShortCut: if you want to shortcut the fraction(dst)
     */
    static void add(Fraction& f1, Fraction& f2, Fraction *dst, bool bIsShortCut = true);
    static void subtract(Fraction& f1, Fraction& f2, Fraction *dst, bool bIsShortCut = true);
    static void multiple(Fraction& f1, Fraction& f2, Fraction *dst, bool bIsShortCut = true);
    static void divide(Fraction& f1, Fraction& f2, Fraction *dst, bool bIsShortCut = true);
public:
    inline void setNumerator(int nNumerator) {this->m_nNumerator = nNumerator;}
    inline void setDenominator(int nDenominator) {this->m_nDenominator = nDenominator;}
public:
    inline int getNumerator() {return this->m_nNumerator;}
    inline int getDenominator() {return this->m_nDenominator;}

    inline int getNumerator() const {return this->m_nNumerator;}
    inline int getDenominator() const {return this->m_nDenominator;}
public:
    /**
     *  Calculate the sum of this fraction with the given fraction
     *
     *  @Note: This does not modify this fraction
     *
     *  @pragma f: The fraction to add
     *  @return The fraction sum
     */
    Fraction operator+(Fraction& f);
    Fraction operator+=(Fraction& f);

    Fraction operator-(Fraction& f);
    Fraction operator-=(Fraction& f);

    Fraction operator-();

    Fraction operator*(Fraction& f);
    Fraction operator*=(Fraction& f);
    Fraction operator/(Fraction& f);
    Fraction operator/=(Fraction& f);

    bool operator==(Fraction& f);
    bool operator!=(Fraction& f);
    bool operator<(Fraction& f);
    bool operator>(Fraction& f);
    bool operator<=(Fraction& f);
    bool operator>=(Fraction& f);
public:
    typedef Fraction Frac;
protected:
    int m_nNumerator, m_nDenominator;
private:
    static const Fraction DEFAULT;
private:
    bool isValid();
    bool isValid() const;
private:
    int p_nNumeratorMem, p_nDenominatorMem;
};
NS_ZY_END