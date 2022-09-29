/// \file maze.c
/// \brief Creates a maze and tests parameters values
/// \author Karel.SVBD, CFPTI
/// \date 29.09.2022
/// \version 1.1

//includes
#include <stdio.h>

//pseudo constants
#define MAZE_MAX_SIZE 100
#define MAZE_MIN_SIZE 0
#define DEFAULT_MAZE_SIZE 20
#define DEVIDED_BY 2
#define DEVIDED_RESULT 0
#define INCREMENT_VALUE 1

//tests
#if !defined(MAZE_REQ_SIZE) || MAZE_REQ_SIZE <= MAZE_MIN_SIZE
    #undef MAZE_REQ_SIZE
    #define MAZE_REQ_SIZE DEFAULT_MAZE_SIZE
#endif

#if MAZE_REQ_SIZE > MAZE_MAX_SIZE
    #undef MAZE_REQ_SIZE
    #define MAZE_REQ_SIZE MAZE_MAX_SIZE
#endif

#if MAZE_REQ_SIZE % DEVIDED_BY != DEVIDED_RESULT
    #define NEW_VALUE ((MAZE_REQ_SIZE) + (INCREMENT_VALUE))
    #undef MAZE_REAL_SIZE
    #define MAZE_REAL_SIZE NEW_VALUE
#endif

#if !defined(MAZE_REAL_SIZE)
    #undef MAZE_REAL_SIZE
    #define MAZE_REAL_SIZE MAZE_REQ_SIZE
#endif

//code
int maze[MAZE_REAL_SIZE][MAZE_REAL_SIZE];

int main(void){
    printf("Maze size = %d\n", MAZE_REAL_SIZE);
    return 0;
}