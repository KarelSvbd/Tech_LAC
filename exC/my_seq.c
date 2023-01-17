/// \file my_busybox.c
/// \brief Replica of the os busybox in c
/// \author Karel.SVBD, CFPT-i
/// \date 17.01.2023
/// \version 1.0

#include <stdio.h>
#include <stdlib.h>

#define INC_DEFAULT_VALUE 1
#define LIMIT_ARGUMENT 4
#define MIN_ARGUMENTS_SEQ 2
#define MARGIN 1
#define FIRST_ARGUMENT 1
#define SECOND_ARGUMENT 2

int main(int argc, char *argv[])
{
    if(argc >= MIN_ARGUMENTS_SEQ && argc <= LIMIT_ARGUMENT)
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

    return 0;
}