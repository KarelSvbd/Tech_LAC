struct fraction_s
{
    /* data */
    int numerator;
    int denominator;

    int (*GetNumerator)(struct Fraction_s *f);
    int (*GetDenominator)(struct Fraction_s *f);

    char * (*ToString)(struct Fraction_s *f);
    void (*Free)(struct Fraction_s *f);


}Fraction;

Fraction *new_Fraction(int pNum, int pDen);
