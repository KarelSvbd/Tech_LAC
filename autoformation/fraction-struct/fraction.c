#include "fraction.h"

int getNumerator(Fraction *this){
    return this->numerator;
}

int getDenominator(Fraction *this){
    return this->denominator;
}

char *toString(Fraction *this){
    char *buffer = malloc(10);
    sprintf(buffer, "%d/%d", this->numerator, this->denominator);
    return buffer;
}

char *toStringDecimal(Fraction *this){
    char *buffer = malloc(10);
    sprintf(buffer, "%f", (float)this->numerator/this->denominator);
    return buffer;
}

void freeFraction(Fraction *this){
    free(this);
}


Fraction *new_Fraction(int numerator, int denominator){
    Fraction *this = malloc(sizeof(Fraction));
    this->numerator = numerator;
    this->denominator = denominator;
    this->GetNumerator = getNumerator;
    this->GetDenominator = getDenominator;
    this->ToString = toString;
    this->ToStringDecimal = toStringDecimal;
    this->Free = freeFraction;
    return this;
}