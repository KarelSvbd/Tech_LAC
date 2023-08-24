typedef struct fraction_s
{
    /* data */
    int numerator;
    int denominator;

    int (*GetNumerator)(struct fraction_s *f);
    int (*GetDenominator)(struct fraction_s *f);

    char *(*ToString)(struct fraction_s *f);
    char *(*ToStringDecimal)(struct fraction_s *f);
    void (*Free)(struct fraction_s *f);


}Fraction;

Fraction *new_Fraction(int pNum, int pDen);