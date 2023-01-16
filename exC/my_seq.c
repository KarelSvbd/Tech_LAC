#include <stdio.h>
#include <stdlib.h>

#define MARGIN 1
#define INC_DEFAULT_VALUE 1
#define FIRST_ARGUMENT 1
#define SECOND_ARGUMENT 2
#define LIMIT_ARGUMENT 4

int main(int argc, char *argv[])
{
    //getting the first argument
    int i = atoi(argv[FIRST_ARGUMENT]);
    int inc = INC_DEFAULT_VALUE;
    
    if(argc == LIMIT_ARGUMENT){
        inc = atoi(argv[SECOND_ARGUMENT]);
    }

    //While i is not bigger then the last argument
    while(i <= atoi(argv[argc - MARGIN])){
        printf("%d\n", i);
        i += inc; 
    }

    return 0;
}