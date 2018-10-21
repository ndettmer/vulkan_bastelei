#include <SDL.h>
#include <iostream>

int SDLWindow() {
    SDL_Window *window = nullptr;
    SDL_Surface *windowSurface = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return 1;
    }
    else {
        window = SDL_CreateWindow("Hello",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
        if (window == NULL ) {
        std::cout << "Error" << SDL_GetError() << std::endl;
    }
        else {
        windowSurface = SDL_GetWindowSurface(window);
        SDL_UpdateWindowSurface(window);
        SDL_Delay(2000);
    }
    }
}
