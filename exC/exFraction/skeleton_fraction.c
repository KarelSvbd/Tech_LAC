#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fraction.h"
#ifdef UNIT_TESTS
#include "tests.h" /* macro-commands for simpleCtest */
#include <string.h>
#endif


struct *new_Fraction(int pNum, int pDen) {
  /* add your code here */
  struct Fraction *fraction = malloc(sizeof (struct Fraction))

  fraction->numerator = pNum;
  fraction->denominator = pDen;
}

void del_Fraction(struct Fraction *fraction){
  if(fraction != NULL){
    free(fraction->data);
    free(fraction);
  }
}



#ifdef UNIT_TESTS
/* Start the overall test suite */
START_TESTS()

/* A new group of tests, with an identifier */
START_TEST("constructor")
{ /* this bracket is mandatory to permit the variables declaration in the block */
  Fraction *target = new_Fraction(1, 2);
  ASSERT(target != NULL);
  ASSERT(target->numerator == 1);
  ASSERT(target->denominator == 2);
  target->Free(target);
}
END_TEST()

START_TEST("getters")
{ /* this bracket is mandatory to permit the variables declaration in the block */
  Fraction *target = new_Fraction(1, 2);
  ASSERT(target->GetNumerator(target) == 1);
  ASSERT(target->GetDenominator(target) == 2);
  target->Free(target);
}
END_TEST()

START_TEST("ToString")
{ /* this bracket is mandatory to permit the variables declaration in the block */
  Fraction *target = new_Fraction(1, 2);
  char *result = target->ToString(target);
  ASSERT(strcmp("1 / 2", result) == 0);
  target->Free(target);
  free(result);
}
END_TEST()

START_TEST("use valgrind memcheck tool for checking memory allocation/free")
END_TEST()

/*/ End the overall test suite */
END_TESTS()
#endif
