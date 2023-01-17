/// \file my_random.c
/// \brief Creates a replica of the command random in bash
/// \author Karel.SVBD, CFPT-i
/// \date 17.01.2023
/// \version 1.0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ARGUMENTS_SEQ 2
#define RANDOM_SEED time(0)
#define ARGUMENTS_RANDOM 3
#define MARGIN 1
#define FIRST_ARGUMENT 1
#define SECOND_ARGUMENT 2

int main(int argc, char *argv[])
{
    if(argc == ARGUMENTS_RANDOM)
    {
        int firstArguement = atoi(argv[FIRST_ARGUMENT]);
        int secondArguement = atoi(argv[SECOND_ARGUMENT]);
        // seed for random
        srand((unsigned)RANDOM_SEED);
        // creating random
        int result = (rand() % (secondArguement - firstArguement + MARGIN)) + firstArguement;
        printf("%d\n", result);

    }
    else{
        printf("%s%d%s%d\n", "Wrong number of arguments. Given : ", argc, " asked : ", ARGUMENTS_RANDOM);
    }

    return 0;
}