/* # $Id: skeleton_player.c 10971 2021-02-02 21:56:39Z marechal $ */
/* \file player.c
 * \author C. Marechal
 * \date 10/01/2021
 * \brief player class
*/
#include <stdio.h>
#include <limits.h>
#include <SDL2/SDL.h>
#include <assert.h>
#include "../inc/player.h"

#ifdef UNIT_TESTS
#include "../inc/tests.h"
#endif

static void PlayerProcessInput(Player *self, SDL_Event event) {
}

static void PlayerUpdate(Player *self, float deltaTime) {
}

static void PlayerRender(Player *self, SDL_Renderer *renderer) {
}

static void PlayerFree(Player *self) { 
}

Player* new_Player(int x, int y, int pWindowWidth, int pWindowHeight){
}

#ifdef UNIT_TESTS

/* Start the overall test suite */
START_TESTS()

/* A new group of tests, with an identifier */
START_TEST("constructor test") {
    /* this bracket is mandatory to permit the variables declaration in the block */
    Player *target = new_Player(150, 250, 800, 600);
    ASSERT(target->x == 150);
    ASSERT(target->y == 250);
    ASSERT(target->windowWidth == 800);
    ASSERT(target->windowHeight == 600);

    ASSERT(target->upDirection == 0);
    ASSERT(target->downDirection == 0);
    ASSERT(target->rightDirection == 0);
    ASSERT(target->leftDirection == 0);
    ASSERT(target->moveSpeedPxPerS == 100);

    ASSERT(target->ProcessInput != NULL);
    ASSERT(target->Update != NULL);
    ASSERT(target->Render != NULL);
    ASSERT(target->Free != NULL);

    target->Free(target); /* for valgrind leak-check */
}
END_TEST()

START_TEST("process input test") {
    /* this bracket is mandatory to permit the variables declaration in the block */
    Player *target = new_Player(150, 250, 800, 600);

    SDL_Event event;
    
    // Keydown type
    event.type = SDL_KEYDOWN;
    // directions
    event.key.keysym.sym = SDLK_UP;
    target->ProcessInput(target, event);
    ASSERT(target->upDirection == 1);
    ASSERT(target->downDirection == 0);
    ASSERT(target->rightDirection == 0);
    ASSERT(target->leftDirection == 0);

    event.key.keysym.sym = SDLK_DOWN;
    target->ProcessInput(target, event);
    ASSERT(target->upDirection == 1);
    ASSERT(target->downDirection == 1);
    ASSERT(target->rightDirection == 0);
    ASSERT(target->leftDirection == 0);

    event.key.keysym.sym = SDLK_RIGHT;
    target->ProcessInput(target, event);
    ASSERT(target->upDirection == 1);
    ASSERT(target->downDirection == 1);
    ASSERT(target->rightDirection == 1);
    ASSERT(target->leftDirection == 0);

    event.key.keysym.sym = SDLK_LEFT;
    target->ProcessInput(target, event);
        ASSERT(target->upDirection == 1);
    ASSERT(target->downDirection == 1);
    ASSERT(target->rightDirection == 1);
    ASSERT(target->leftDirection == 1);

    // Keyup type
    event.type = SDL_KEYUP;
    // directions
    event.key.keysym.sym = SDLK_UP;
    target->ProcessInput(target, event);
    ASSERT(target->upDirection == 0);
    ASSERT(target->downDirection == 1);
    ASSERT(target->rightDirection == 1);
    ASSERT(target->leftDirection == 1);

    event.key.keysym.sym = SDLK_DOWN;
    target->ProcessInput(target, event);
    ASSERT(target->upDirection == 0);
    ASSERT(target->downDirection == 0);
    ASSERT(target->rightDirection == 1);
    ASSERT(target->leftDirection == 1);

    event.key.keysym.sym = SDLK_RIGHT;
    target->ProcessInput(target, event);
    ASSERT(target->upDirection == 0);
    ASSERT(target->downDirection == 0);
    ASSERT(target->rightDirection == 0);
    ASSERT(target->leftDirection == 1);

    event.key.keysym.sym = SDLK_LEFT;
    target->ProcessInput(target, event);
        ASSERT(target->upDirection == 0);
    ASSERT(target->downDirection == 0);
    ASSERT(target->rightDirection == 0);
    ASSERT(target->leftDirection == 0);

    target->Free(target); /* for valgrind leak-check */
}
END_TEST()

START_TEST("move function test : movement of the player") {
    /* this bracket is mandatory to permit the variables declaration in the block */
#define DELTA_TIME 0.1
    Player *target = new_Player(150, 250, 800, 600);

    // no movement
    target->Update(target, DELTA_TIME);
    ASSERT(target->x == 150);
    ASSERT(target->y == 250);

    // movement to up
    target->upDirection = 1;
    target->downDirection = 0;
    target->rightDirection = 0;
    target->leftDirection = 0;
    
    target->Update(target, DELTA_TIME);
    ASSERT(target->x == 150);
    ASSERT(target->y == 250 - 100 * DELTA_TIME);

    // movement to down
    target->upDirection = 0;
    target->downDirection = 1;
    target->rightDirection = 0;
    target->leftDirection = 0;

    target->Update(target, DELTA_TIME);
    ASSERT(target->x == 150);
    ASSERT(target->y == 250);

    // movement to right
    target->upDirection = 0;
    target->downDirection = 0;
    target->rightDirection = 1;
    target->leftDirection = 0;
    
    target->Update(target, DELTA_TIME);
    ASSERT(target->x == 150 + 100 * DELTA_TIME);
    ASSERT(target->y == 250);

    // movement to left
    target->upDirection = 0;
    target->downDirection = 0;
    target->rightDirection = 0;
    target->leftDirection = 1;
    
    target->Update(target, DELTA_TIME);
    ASSERT(target->x == 150);
    ASSERT(target->y == 250);
    
    // movement to up-left
    target->upDirection = 1;
    target->downDirection = 0;
    target->rightDirection = 0;
    target->leftDirection = 1;
    
    target->Update(target, DELTA_TIME);
    ASSERT(target->x == 150 - 100 * DELTA_TIME);
    ASSERT(target->y == 250 - 100 * DELTA_TIME);
    
    target->Free(target); /* for valgrind leak-check */
}
END_TEST()

/*/ End the overall test suite */
END_TESTS()
#endif // UNIT_TESTS