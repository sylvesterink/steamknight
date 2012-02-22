#include "GBase.h"

namespace ie_game
{
    /**
     * @brief Create game object.
     */
    GBase::GBase():
        _isRunning(false),
        _window(NULL)
    {

    }

    /**
     * @brief Destroy game object.
     */
    GBase::~GBase()
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
    int GBase::execute()
    {
        //if (initialize() == false) {
            //return 1;
        //}

        //SDL_Event Event;

        //// Run game loop
        //while (_isRunning) {
            //while (SDL_PollEvent(&Event)) {
                //processEvents(Event);
            //}

            //processLogic();
            //render();
        //}

        //cleanup();

        return 0;
    }

    /**
     * @brief Initializes game settings and creates initial member objects.
     * @return Whether initialization was successful or not.
     */
    bool GBase::initialize()
    {
        //_isRunning = true;

        return true;
    }

    /**
     * @brief Given an SDL event, process the event as required.
     * @param Event The event to process
     */
    void GBase::processEvents(SDL_Event& Event)
    {

    }

    /**
     * @brief Run the game logic.
     */
    void GBase::processLogic()
    {
    }

    /**
     * @brief Draw the game's visual output.
     */
    void GBase::render()
    {

    }

    /**
     * @brief Remove member objects and uninitialize game settings.
     */
    void GBase::cleanup()
    {

    }
}
