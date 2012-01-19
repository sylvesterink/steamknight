#include "GameBase.h"

namespace ie_game
{
    /**
     * @brief Create game object.
     */
    GameBase::GameBase()
    {
    }

    /**
     * @brief Destroy game object.
     */
    GameBase::~GameBase()
    {
    }

    /**
     * @brief Initializes game, runs game loop, and cleans up when finished.
     * @return Success or failure of run.
     */
    int GameBase::execute()
    {
        // Initialize SDL
        if (SDL_Init( SDL_INIT_EVERYTHING ) != 0) {
            return -1;
        }

        return 0;
    }

    /**
     * @brief Initializes game settings and creates initial member objects.
     * @return Whether initialization was successful or not.
     */
    bool GameBase::initialize()
    {
        return true;
    }

    /**
     * @brief Given an SDL event, process the event as required.
     */
    void GameBase::processEvents()
    {
    }

    /**
     * @brief Run the game logic.
     */
    void GameBase::processLogic()
    {
    }

    /**
     * @brief Draw the game's visual output.
     */
    void GameBase::render()
    {
    }

    /**
     * @brief Remove member objects and uninitialize game settings.
     */
    void GameBase::cleanup()
    {
        SDL_Quit();
    }
}
