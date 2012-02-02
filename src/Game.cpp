#include "Game.h"
#include "SteamknightConfig.h"
using namespace std;

/**
 * @brief Main function.  Creates a game class and executes.
 * @param argc Number of arguments being passed to program.
 * @param argv[] List of arguments passed to program.
 * @return Status of whether run was successful or not.
 */
int main(int argc, const char *argv[])
{
    Game steamknight;

    return steamknight.execute();
}

//TODO: Call Gamebase constructor
Game::Game()
{
    cout << "Begin Game" << endl;
}

Game::~Game()
{
    //TODO: This is duplicated in cleanup()
    if (_window != NULL) {
        delete _window;
        _window = NULL;
    }
    cout << "End Game" << endl;
}

int Game::execute()
{
    if (initialize() == false) {
        return 1;
    }

    SDL_Event Event;

    // Run game loop
    while (_isRunning) {
        while (SDL_PollEvent(&Event)) {
            processEvents(Event);
        }

        processLogic();
        render();

        // Added to prevent monopolization of cpu.
        SDL_Delay(1);

    }

    cleanup();

    return 0;
}

bool Game::initialize()
{
    // Initialize SDL
    if (SDL_Init( SDL_INIT_EVERYTHING ) != 0) {
        return false;
    }

    // Create game window
    _window = new ie_game::GameWindow();
    if (_window->initialize(800, 600, 32, false, "Ink Engine") == false) {
        return false;
    }

    //TODO: put this elsewhere
    glClearColor(0.0, 0.0, 0.0, 1.0);

    _isRunning = true;

    cout << "Initialized" << endl;
    cout << "Version:";
    cout << STEAMKNIGHT_VERSION_MAJOR;
    cout << " " << STEAMKNIGHT_VERSION_MINOR;
    cout << " " << STEAMKNIGHT_VERSION_BUILD << endl;

    return true;
}

void Game::processEvents(SDL_Event& Event)
{
    if (Event.type == SDL_QUIT) {
        _isRunning = false;
    }
}

void Game::processLogic()
{

}

void Game::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
}

void Game::cleanup()
{
    if (_window != NULL) {
        delete _window;
        _window = NULL;
    }

    SDL_Quit();

    cout << "Cleaning Up" << endl;
}
