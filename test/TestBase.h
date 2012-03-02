#ifndef TESTBASE_H
#define TESTBASE_H

#include "GBase.h"
#include "GWindow.h"

class TestBase : public ie_game::GBase {
    public:
        TestBase();
        virtual ~TestBase();

        virtual int execute();

    protected:
        virtual bool initialize();
        virtual void processEvents(SDL_Event& event);

        virtual void OnExit();
        virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        virtual void processLogic();
        virtual void render();

        virtual void cleanup();  // May not be needed.  Use destructor
};

#endif /* end of include guard: TESTBASE_H */
