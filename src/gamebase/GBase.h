#ifndef GAMEBASE_111P0ECW
#define GAMEBASE_111P0ECW

#include <SDL/SDL.h>

#include "GWindow.h"

namespace ie_game
{
    /**
     * @brief The basic game object context.
     */
    class GBase {
        protected:
            bool _isRunning;
            GWindow* _window;

        public:
            GBase ();
            virtual ~GBase ();

            virtual int execute();

        protected:
            virtual bool initialize();
            virtual void processEvents(SDL_Event&);
            virtual void processLogic();
            virtual void render();

            virtual void cleanup();  // May not be needed.  Use destructor
    };
}

#endif /* end of include guard: GAMEBASE_111P0ECW */
