#include <stdio.h>

#define MAZE_MAX_SIZE 51
#define DEFAULT_MAZE_SIZE 10
#define DMAZE_REQ_SIZE 101
#define MAZE_REAL_SIZE 0

#if !defined(DMAZE_REQ_SIZE)
    #undef MAZE_REAL_SIZE
    #define MAZE_REAL_SIZE DEFAULT_MAZE_SIZE
#endif

#if(DMAZE_REQ_SIZE > MAZE_MAX_SIZE)
    #undef MAZE_REAL_SIZE
    #define MAZE_REAL_SIZE MAZE_MAX_SIZE
#endif

#if((MAZE_REAL_SIZE % 2) == 1)
    MAZE_REAL_SIZE + 1
#endif

int maze[MAZE_REAL_SIZE][MAZE_REAL_SIZE];

int main(void){
    printf("Maze size = %d\n", MAZE_REAL_SIZE);
    return 0;
}