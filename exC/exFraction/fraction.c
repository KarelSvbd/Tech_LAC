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