#ifndef STEAMKNIGHT_H
#define STEAMKNIGHT_H

#include <iostream>
#include "GBase.h"

class Game : public ie_game::GBase {
    public:
        Game ();
        virtual ~Game ();

        virtual int execute();

    protected:
        virtual bool initialize();
        virtual void processEvents(SDL_Event& event);
        virtual void processLogic();
        virtual void render();

        virtual void cleanup();  // May not be needed.  Use destructor
};

#endif /* end of include guard: STEAMKNIGHT_H */
