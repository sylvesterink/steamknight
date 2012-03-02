// Credit to SDL Tutorials
// http://www.sdltutorials.com/sdl-events
#include "GEvent.h"

namespace ie_game {

    GEvent::GEvent()
    {

    }

    GEvent::~GEvent()
    {
        //Do nothing
    }

    void GEvent::OnEvent(SDL_Event* event)
    {
        switch(event->type) {
            case SDL_ACTIVEEVENT:
                OnActiveEvent(event);
                break;

            case SDL_KEYDOWN:
                OnKeyDown(event->key.keysym.sym,event->key.keysym.mod,
                        event->key.keysym.unicode);
                break;

            case SDL_KEYUP:
                OnKeyUp(event->key.keysym.sym,event->key.keysym.mod,
                        event->key.keysym.unicode);
                break;

            case SDL_MOUSEMOTION:
                OnMouseMove(event->motion.x,event->motion.y,event->motion.xrel,
                        event->motion.yrel,
                        (event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,
                        (event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,
                        (event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
                break;

            case SDL_MOUSEBUTTONDOWN:
                OnMouseDown(event);
                break;

            case SDL_MOUSEBUTTONUP:
                OnMouseUp(event);
                break;

            case SDL_JOYAXISMOTION:
                OnJoyAxis(event->jaxis.which,event->jaxis.axis,event->jaxis.value);
                break;

            case SDL_JOYBALLMOTION:
                OnJoyBall(event->jball.which,event->jball.ball,
                        event->jball.xrel,event->jball.yrel);
                break;

            case SDL_JOYHATMOTION:
                OnJoyHat(event->jhat.which,event->jhat.hat,event->jhat.value);
                break;

            case SDL_JOYBUTTONDOWN:
                OnJoyButtonDown(event->jbutton.which,event->jbutton.button);
                break;

            case SDL_JOYBUTTONUP:
                OnJoyButtonUp(event->jbutton.which,event->jbutton.button);
                break;

            case SDL_QUIT:
                OnExit();
                break;

            case SDL_SYSWMEVENT:
                //Ignore
                break;

            case SDL_VIDEORESIZE:
                OnResize(event->resize.w,event->resize.h);
                break;

            case SDL_VIDEOEXPOSE:
                OnExpose();
                break;

            default:
                OnUser(event->user.type,event->user.code,event->user.data1,
                        event->user.data2);
                break;
        }
    }

    void GEvent::OnInputFocus() {
        //Pure virtual, do nothing
    }

    void GEvent::OnInputBlur() {
        //Pure virtual, do nothing
    }

    void GEvent::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
        //Pure virtual, do nothing
    }

    void GEvent::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
        //Pure virtual, do nothing
    }

    void GEvent::OnMouseFocus() {
        //Pure virtual, do nothing
    }

    void GEvent::OnMouseBlur() {
        //Pure virtual, do nothing
    }

    void GEvent::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,
            bool Right,bool Middle) {
        //Pure virtual, do nothing
    }

    void GEvent::OnMouseWheel(bool Up, bool Down) {
        //Pure virtual, do nothing
    }

    void GEvent::OnLButtonDown(int mX, int mY) {
        //Pure virtual, do nothing
    }

    void GEvent::OnLButtonUp(int mX, int mY) {
        //Pure virtual, do nothing
    }

    void GEvent::OnRButtonDown(int mX, int mY) {
        //Pure virtual, do nothing
    }

    void GEvent::OnRButtonUp(int mX, int mY) {
        //Pure virtual, do nothing
    }

    void GEvent::OnMButtonDown(int mX, int mY) {
        //Pure virtual, do nothing
    }

    void GEvent::OnMButtonUp(int mX, int mY) {
        //Pure virtual, do nothing
    }

    void GEvent::OnJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
        //Pure virtual, do nothing
    }

    void GEvent::OnJoyButtonDown(Uint8 which,Uint8 button) {
        //Pure virtual, do nothing
    }

    void GEvent::OnJoyButtonUp(Uint8 which,Uint8 button) {
        //Pure virtual, do nothing
    }

    void GEvent::OnJoyHat(Uint8 which,Uint8 hat,Uint8 value) {
        //Pure virtual, do nothing
    }

    void GEvent::OnJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
        //Pure virtual, do nothing
    }

    void GEvent::OnMinimize() {
        //Pure virtual, do nothing
    }

    void GEvent::OnRestore() {
        //Pure virtual, do nothing
    }

    void GEvent::OnResize(int w,int h) {
        //Pure virtual, do nothing
    }

    void GEvent::OnExpose() {
        //Pure virtual, do nothing
    }

    void GEvent::OnExit() {
        //Pure virtual, do nothing
    }

    void GEvent::OnUser(Uint8 type, int code, void* data1, void* data2) {
        //Pure virtual, do nothing
    }

    void GEvent::OnActiveEvent(SDL_Event* event)
    {
        switch(event->active.state) {
            case SDL_APPMOUSEFOCUS:
                if ( event->active.gain ) {
                    OnMouseFocus();
                }
                else {
                    OnMouseBlur();
                }
                break;

            case SDL_APPINPUTFOCUS:
                if ( event->active.gain ) {
                    OnInputFocus();
                }
                else {
                    OnInputBlur();
                }
                break;

            case SDL_APPACTIVE:
                if ( event->active.gain ) {
                    OnRestore();
                }
                else {
                    OnMinimize();
                }
                break;
        }
    }

    void GEvent::OnMouseDown(SDL_Event* event)
    {
        switch(event->button.button) {
            case SDL_BUTTON_LEFT:
                OnLButtonDown(event->button.x,event->button.y);
                break;

            case SDL_BUTTON_RIGHT:
                OnRButtonDown(event->button.x,event->button.y);
                break;

            case SDL_BUTTON_MIDDLE:
                OnMButtonDown(event->button.x,event->button.y);
                break;
        }
    }

    void GEvent::OnMouseUp(SDL_Event* event)
    {
        switch(event->button.button) {
            case SDL_BUTTON_LEFT:
                OnLButtonUp(event->button.x,event->button.y);
                break;

            case SDL_BUTTON_RIGHT:
                OnRButtonUp(event->button.x,event->button.y);
                break;

            case SDL_BUTTON_MIDDLE:
                OnMButtonUp(event->button.x,event->button.y);
                break;
        }
    }

} /* namespace ie_game */

