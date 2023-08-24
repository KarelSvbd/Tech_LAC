#include <stdio.h>
#include <stdlib.h>
#include "fraction.c"

int main(void){
    Fraction *fraction = new_Fraction(1,2);
    printf("%s\n", fraction->ToString(fraction));
    printf("%s\n", fraction->ToStringDecimal(fraction));
    return 0;
}

