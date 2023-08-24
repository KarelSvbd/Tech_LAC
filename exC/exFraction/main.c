/* # $Id: main.c 10878 2021-01-25 21:02:09Z marechal $ */
/* \file program.c
 * \author C. Marechal, CFPT-EI
 * \date 01/2014
 * \brief Fraction module for training structure and function pointers
*/
// { beginList }
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fraction.h"

int *func(int param){
  static char buffer[10];
  
}


int main() {
  Fraction *aFraction, *bFraction;
  char *toStringBuffer;

  /* call "object" constructors */
  aFraction = new_Fraction(1, 2);
  assert(aFraction != NULL);
  bFraction = new_Fraction(3, 2);
  assert(bFraction != NULL);

  printf("aFraction : num = %d\n", aFraction->GetNumerator(aFraction));
  printf("aFraction : den = %d\n", aFraction->GetDenominator(aFraction));
  
  toStringBuffer = bFraction->ToString(bFraction);
  printf("bFraction->ToString = %s\n", toStringBuffer);

  // each dynamic memory area MUST be freed
  aFraction->Free(aFraction);
  bFraction->Free(bFraction);
  free(toStringBuffer);
    
  return 0;
}
// { endList }

