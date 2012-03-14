// Credit to SDL Tutorials
// http://www.sdltutorials.com/sdl-events
#include "GEvent.h"

namespace ie_game {

    /**
     * @brief Create event object
     */
    GEvent::GEvent()
    {

    }

    /**
     * @brief Destroy event object
     */
    GEvent::~GEvent()
    {
        //Do nothing
    }

    /**
     * @brief Check the type of event passed and process it through the
     *        appropriate method.
     * @param event The event to be processed.
     */
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

    /**
     * @brief Handle the input focus event
     */
    void GEvent::OnInputFocus() {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the input blur event
     */
    void GEvent::OnInputBlur() {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the keydown event
     * @param sym The id of the key pressed
     * @param mod The modification key pressed
     * @param unicode The unicode value of the pressed key
     */
    void GEvent::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the keyup event
     * @param sym The id of the key pressed
     * @param mod The modification key pressed
     * @param unicode The unicode value of the pressed key
     */
    void GEvent::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the mouse focus event
     */
    void GEvent::OnMouseFocus() {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the mouse blur event
     */
    void GEvent::OnMouseBlur() {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the mouse move event
     * @param mX X coordinate, relative to the window
     * @param mY Y coordinate, relative to the window
     * @param relX Relative motion in the X direction
     * @param relY Relative motion in the Y direction
     * @param Left Whether the left button is pressed
     * @param Right Whether the right button is pressed
     * @param Middle Whether the middle button is pressed
     */
    void GEvent::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,
            bool Right,bool Middle) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the mouse wheel event
     * @param Up Whether mouse wheel was moved up
     * @param Down Whether mouse wheel was moved down
     * TODO: Replace with more complex implementation
     *       Not implemented in OnEvent()
     */
    void GEvent::OnMouseWheel(bool Up, bool Down) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the left mouse button down event
     * @param mX X coordinate, relative to the window
     * @param mY Y coordinate, relative to the window
     */
    void GEvent::OnLButtonDown(int mX, int mY) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the left mouse button up event
     * @param mX X coordinate, relative to the window
     * @param mY Y coordinate, relative to the window
     */
    void GEvent::OnLButtonUp(int mX, int mY) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the right mouse button down event
     * @param mX X coordinate, relative to the window
     * @param mY Y coordinate, relative to the window
     */
    void GEvent::OnRButtonDown(int mX, int mY) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the right mouse button up event
     * @param mX X coordinate, relative to the window
     * @param mY Y coordinate, relative to the window
     */
    void GEvent::OnRButtonUp(int mX, int mY) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the middle mouse button down event
     * @param mX X coordinate, relative to the window
     * @param mY Y coordinate, relative to the window
     */
    void GEvent::OnMButtonDown(int mX, int mY) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the middle mouse button up event
     * @param mX X coordinate, relative to the window
     * @param mY Y coordinate, relative to the window
     */
    void GEvent::OnMButtonUp(int mX, int mY) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handles the joystick motion event
     * @param which The index of the joystick that was moved
     * @param axis The index of the axis that was moved
     * @param value The current position of the axis
     */
    void GEvent::OnJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handles the joystick button down event
     * @param which The index of the joystick
     * @param button The button pressed
     */
    void GEvent::OnJoyButtonDown(Uint8 which,Uint8 button) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handles the joystick button up event
     * @param which The index of the joystick
     * @param button The button pressed
     */
    void GEvent::OnJoyButtonUp(Uint8 which,Uint8 button) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handles the hat change event
     * @param which The index of the joystick
     * @param hat The index of the hat that changed
     * @param value The new position of the hat
     */
    void GEvent::OnJoyHat(Uint8 which,Uint8 hat,Uint8 value) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handles the josytick trackball motion event
     * @param which The index of the joystick
     * @param ball The index of the trackball that changed
     * @param xrel The relative motion in the X direction
     * @param yrel The relative motion in the Y direction
     */
    void GEvent::OnJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the minimize window event
     */
    void GEvent::OnMinimize() {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the restore window event
     */
    void GEvent::OnRestore() {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the resize window event
     * @param w The new window width
     * @param h The new window height
     */
    void GEvent::OnResize(int w,int h) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the window exposed event
     */
    void GEvent::OnExpose() {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the program exit event
     */
    void GEvent::OnExit() {
        //Pure virtual, do nothing
    }

    /**
     * @brief Handle the user custom event
     * @param type The type of event called
     * @param code The user defined event code
     * @param data1 User defined data pointer
     * @param data2 User defined data pointer
     */
    void GEvent::OnUser(Uint8 type, int code, void* data1, void* data2) {
        //Pure virtual, do nothing
    }

    /**
     * @brief Legacy event handling
     * @param event Event to handle
     * NOTE: Avoid using
     */
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

    /**
     * @brief Check the type of mousedown event passed and process it through
     *        the appropriate method.
     * @param event The event to be processed.
     */
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

    /**
     * @brief Check the type of mouseup event passed and process it through the
     *        appropriate method.
     * @param event The event to be processed.
     */
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

