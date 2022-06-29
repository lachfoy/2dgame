#include "Engine.h"

Engine::Engine(){}

bool Engine::init(int w, int h)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
    {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    width = w;
    height = h;

    window = SDL_CreateWindow("sdl2 window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    if(window == NULL)
    {
        printf("Window could not be created: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(window == NULL)
    {
        printf("Renderer could not be created: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void Engine::cleanup()
{
    onCleanup(); // run the games cleanup functions

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void Engine::run()
{
    onCreate(); // call the game create functions

    Uint32 now = SDL_GetPerformanceCounter();
    Uint32 last = 0;
    float dt = 0;
    bool quit = false;
    SDL_Event e;
    while(!quit)
    {
        // poll events
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
            {
                quit = true;
            }

            handleInput(e);
        }

        last = now;
        now = SDL_GetPerformanceCounter();

        onUpdate(dt); // let the game update all the game logic

        // calculate dt
        dt = (float)((now - last) * 1000 / (float)SDL_GetPerformanceFrequency()) / 1000.0f;

        onRender(); // let the game present everything to the renderer
    }

    cleanup(); // cleanup resources
}