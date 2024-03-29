#ifndef GEVENT_H
#define GEVENT_H

#include <SDL/SDL.h>

namespace ie_game {

    /**
     * @brief Base class for dealing with SDL events.
     *        Derived classes implement the required event handling functions.
     */
    class GEvent
    {
        public:
            GEvent();
            virtual ~GEvent();

            virtual void OnEvent(SDL_Event* event);

            virtual void OnInputFocus();
            virtual void OnInputBlur();
            virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
            virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
            virtual void OnMouseFocus();
            virtual void OnMouseBlur();
            virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool left,
                    bool right, bool middle);
            virtual void OnMouseWheel(bool up, bool down);    //Not implemented
            virtual void OnLButtonDown(int mX, int mY);
            virtual void OnLButtonUp(int mX, int mY);
            virtual void OnRButtonDown(int mX, int mY);
            virtual void OnRButtonUp(int mX, int mY);
            virtual void OnMButtonDown(int mX, int mY);
            virtual void OnMButtonUp(int mX, int mY);
            virtual void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
            virtual void OnJoyButtonDown(Uint8 which, Uint8 button);
            virtual void OnJoyButtonUp(Uint8 which, Uint8 button);
            virtual void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value);
            virtual void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);
            virtual void OnMinimize();
            virtual void OnRestore();
            virtual void OnResize(int w,int h);
            virtual void OnExpose();

            virtual void OnExit();
            virtual void OnUser(Uint8 type, int code, void* data1, void* data2);

        protected:
            virtual void OnActiveEvent(SDL_Event* event);
            virtual void OnMouseDown(SDL_Event* event);
            virtual void OnMouseUp(SDL_Event* event);
    };

} /* namespace ie_game */

#endif /* end of include guard: GEVENT_H */
