#include "GameBase.h"

namespace ie_game
{
    /**
     * @brief Create game object.
     */
    GameBase::GameBase()
    {
        _window = NULL;
    }

    /**
     * @brief Destroy game object.
     */
    GameBase::~GameBase()
    {
        //TODO: This is duplicated in cleanup()
        if (_window != NULL) {
            delete _window;
            _window = NULL;
        }
    }

    /**
     * @brief Initializes game, runs game loop, and cleans up when finished.
     * @return Success or failure of run.
     */
    int GameBase::execute()
    {
        if (initialize() == false) {
            return 1;
        }

        SDL_Event Event;

        while (_isRunning) {
            while (SDL_PollEvent(&Event)) {
                processEvents(Event);
            }

            processLogic();
            render();
        }

        cleanup();

        return 0;
    }

    /**
     * @brief Initializes game settings and creates initial member objects.
     * @return Whether initialization was successful or not.
     */
    bool GameBase::initialize()
    {
        // Initialize SDL
        if (SDL_Init( SDL_INIT_EVERYTHING ) != 0) {
            return false;
        }

        // Create game window
        _window = new GameWindow();
        if (_window->initialize(800, 600, 32, false, "Ink Engine") == false) {
            return false;
        }

        //TODO: put this elsewhere
        glClearColor(0.0, 0.0, 0.0, 1.0);

        return true;
    }

    /**
     * @brief Given an SDL event, process the event as required.
     */
    void GameBase::processEvents(SDL_Event& Event)
    {
        if (Event.type == SDL_QUIT) {
            _isRunning = false;
        }
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
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
    }

    /**
     * @brief Remove member objects and uninitialize game settings.
     */
    void GameBase::cleanup()
    {
        if (_window != NULL) {
            delete _window;
            _window = NULL;
        }

        SDL_Quit();
    }
}
