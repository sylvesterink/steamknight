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

Game::Game()
{
    cout << "Begin Game" << endl;
}

Game::~Game()
{
    cout << "End Game" << endl;
}

int Game::execute()
{
    if (initialize() == false) {
        return 1;
    }

    while (_isRunning) {
        processEvents();
        processLogic();
        render();
    }

    cleanup();

    return 0;
}

bool Game::initialize()
{
    cout << "Initialized" << endl;
    cout << "Version:";
    cout << STEAMKNIGHT_VERSION_MAJOR;
    cout << " " << STEAMKNIGHT_VERSION_MINOR;
    cout << " " << STEAMKNIGHT_VERSION_BUILD << endl;

    return true;
}

void Game::processEvents()
{
    char quit;
    cout << "Processing Events" << endl;
    cin >> quit;

    if (quit == 'q') {
        _isRunning = false;
    }
}

void Game::processLogic()
{
    cout << "Processing Logic" << endl;
}

void Game::render()
{
    cout << "Rendering" << endl;
}

void Game::cleanup()
{
    cout << "Cleaning Up" << endl;
}
