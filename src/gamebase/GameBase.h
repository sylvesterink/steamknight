#ifndef GAMEBASE_111P0ECW
#define GAMEBASE_111P0ECW

//#include <SDL/SDL.h>

namespace ie_game
{
    /**
     * @brief The basic game object context.
     */
    class GameBase {
        protected:
            bool _isRunning;

        public:
            GameBase ();
            virtual ~GameBase ();

            virtual int execute();

        protected:
            virtual bool initialize();
            virtual void processEvents();
            virtual void processLogic();
            virtual void render();

            virtual void cleanup();  // May not be needed.  Use destructor
    };
}

#endif /* end of include guard: GAMEBASE_111P0ECW */
