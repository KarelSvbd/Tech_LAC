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
    SDL_Keycode key = event.key.keysym.sym;
    int is_key_pressed = event.type == SDL_KEYDOWN;

    if (key == SDLK_UP)
        self->upDirection = is_key_pressed ? 1 : 0;
    else if (key == SDLK_DOWN)
        self->downDirection = is_key_pressed ? 1 : 0;
    else if (key == SDLK_RIGHT)
        self->rightDirection = is_key_pressed ? 1 : 0;
    else if (key == SDLK_LEFT)
        self->leftDirection = is_key_pressed ? 1 : 0;
}

static void PlayerUpdate(Player *self, float deltaTime) {
    float pixel_shift = self->moveSpeedPxPerS * deltaTime;
    if (self->upDirection)
        self->y -= pixel_shift;
    if (self->downDirection)
        self->y += pixel_shift;
    if (self->rightDirection)
        self->x += pixel_shift;
    if (self->leftDirection)
        self->x -= pixel_shift; 
}

static void PlayerRender(Player *self, SDL_Renderer *renderer) {
    SDL_Rect rectangle = (SDL_Rect){self->x, self->y, self->width, self->height};
    SDL_SetRenderDrawColor(
        renderer, 
        //cheking if the 2 bits of the color (8 bit) are both at 1
        (self->color & 0xc0) >> 6 == 0x03 ? 0xff : 0x00, //r
        (self->color & 0x30) >> 4 == 0x03 ? 0xff : 0x00, //g
        (self->color & 0x0c) >> 2 == 0x03 ? 0xff : 0x00, //b
        (self->color & 0x03) == 0x03 ? 0xff : 0x00 //a
    );
    //blue simple display
    //SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xff, 0xff);
    SDL_RenderFillRect(renderer, &rectangle);
}

static void PlayerFree(Player *self) {
    free(self);
}

Player* new_Player(int x, int y, int pWindowWidth, int pWindowHeight){
    Player *self = malloc(sizeof(Player));
    self->x = x;
    self->y = y;
    self->width = pWindowWidth / 10;
    self->height = pWindowHeight / 10;

    //red   --> 0xc3 = 0b11000011
    //green --> 0x33 = 0b00110011
    //blue  --> 0x0f = 0b00001111
    self->color = 0x33;//8 bit color

    self->windowWidth = pWindowWidth;
    self->windowHeight = pWindowHeight;

    self->upDirection = 0;
    self->downDirection = 0;
    self->rightDirection = 0;
    self->leftDirection = 0;

    self->moveSpeedPxPerS = 100.0;

    self->ProcessInput = PlayerProcessInput;
    self->Update = PlayerUpdate;
    self->Render = PlayerRender;
    self->Free = PlayerFree;

    return self;
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
