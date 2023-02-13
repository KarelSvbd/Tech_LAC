/* # $Id: main.c 10972 2021-02-02 22:08:58Z marechal $ */
/* \file hello_sdl2.c
 * \author C. Marechal
 * \date 10/12/2020
 * \brief minimal source for testing SDL installation
   package : apt install libsdl2-dev
   compilation :
     gcc -Wall -c main.c
     gcc -Wall -c player.c
     gcc -Wall -o demo_player main.o player.o -lSDL2
*/
#include <SDL2/SDL.h>
#include "../inc/player.h"

#define FPS 30.0
#define FRAME_TIME_LENGTH_MS (1000.0 / FPS)

#define WINDOW_WIDTH         800
#define WINDOW_HEIGHT        600

#define BACKGROUND_RED      0x00
#define BACKGROUND_GREEN    0x00
#define BACKGROUND_BLUE     0x00
#define BACKGROUND_ALPHA    0xFF

int main() {
    int isGameRunning;
    int ticksLastFrame;

    SDL_Event event;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("Rectangle SDL2",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               WINDOW_WIDTH,
                               WINDOW_HEIGHT,
                               SDL_WINDOW_SHOWN);
    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window,
                                  -1, /* automatic driver choice */
                                  SDL_RENDERER_ACCELERATED);       
    if (renderer == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    /* end of SDL2 initializations */

    /* build a rectangle */
    Player *player = new_Player(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    isGameRunning = SDL_TRUE;
    ticksLastFrame = 0;//default value to avoid warning
    /* game loop */
    while (isGameRunning == SDL_TRUE) {
        /* read and process inputs */
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT: {
                    isGameRunning = SDL_FALSE;
                    break;
                }
                default:break;
            } /* end switch(event.type) */
            player->ProcessInput(player, event);
        } /* end while(SDL_PollEvent()) */


        /* update objects */

        // waste some time until we reach the target frame time length
        while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TIME_LENGTH_MS));
        float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
        ticksLastFrame = SDL_GetTicks();

        /* move rectangle */
        player->Update(player, deltaTime);

        /* clear background */
        SDL_SetRenderDrawColor(renderer, BACKGROUND_RED, BACKGROUND_GREEN, BACKGROUND_BLUE, BACKGROUND_ALPHA);
        SDL_RenderClear(renderer);

        /* render objects */
        player->Render(player, renderer);

        /* update the screen with any rendering performed since the previous call */
        SDL_RenderPresent(renderer);

    } /* end while(isGameRunning) */

    /* SDL2 cleanup before exiting */
    player->Free(player);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();     
    return EXIT_SUCCESS; 
}

