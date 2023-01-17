/// \file my_busybox.c
/// \brief Replica of the os busybox in c
/// \author Karel.SVBD, CFPT-i
/// \date 17.01.2023
/// \version 1.0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//For main
#define MIN_MAIN_ARGUMENTS 1
#define MY_SEQ_NAME "my_seq"
#define MY_RANDOM_NAME "my_random"

//For my_seq
#define INC_DEFAULT_VALUE 1
#define LIMIT_ARGUMENT 4
#define MIN_ARGUMENTS_SEQ 3

//For my_random
#define ARGUMENTS_RANDOM 4
#define RANDOM_SEED time(0)

//For both
#define MARGIN 1
#define FIRST_ARGUMENT 2
#define SECOND_ARGUMENT 3

//Creates a sequence using the arguments
//Argv[0] filename
//Argv[1] min
//Argv[3] (optional) interval
//Argv[2] max
static void my_seq(int argc, char *argv[]){

    if(argc >= MIN_ARGUMENTS_SEQ)
    {
        //getting the first argument
        int i = atoi(argv[FIRST_ARGUMENT]);
    
        int inc = INC_DEFAULT_VALUE;
    
        if(argc == LIMIT_ARGUMENT + MARGIN){
            inc = atoi(argv[SECOND_ARGUMENT]);
        }

        //While i is not bigger then the last argument
        while(i <= atoi(argv[argc - MARGIN])){
            printf("%d\n", i);
            i += inc; 
        }
    }
    else{
        printf("%s%d%s%d\n", "Wrong number of arguments. Given : ", argc, " asked min : ", MIN_ARGUMENTS_SEQ);
    }
}

//Creates a sequence using the arguments
//Random source : https://www.geeksforgeeks.org/generating-random-number-range-c/
//Argv[0] filename
//Argv[1] min (included)
//Argv[2] max (included)
static void my_random(int argc, char *argv[]){

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
}


int main(int argc, char *argv[])
{
    //Arguement testing
    //Comparing the second arguement with the names of the functions
    if(strcmp(argv[1], MY_SEQ_NAME) == 0){
        my_seq(argc, argv);
    }
    else if(strcmp(argv[1], MY_RANDOM_NAME) == 0){
        my_random(argc, argv);
    }  
    
    return 0;
}