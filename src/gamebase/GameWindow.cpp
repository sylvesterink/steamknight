#include "GameWindow.h"

namespace ie_game
{
    GameWindow::GameWindow():
        _width(0),
        _height(0),
        _bitsPerPixel(0),
        _isFullscreen(false),
        _isInitialized(false)
    {

    }

    GameWindow::~GameWindow()
    {
    }

    bool GameWindow::initialize(int width, int height, int bitsPerPixel,
            bool isFullscreen, const string& title)
    {
        // Store window values
        _height = height;
        _width = width;
        _title = title;
        _isFullscreen = isFullscreen;
        _bitsPerPixel = bitsPerPixel;

        // Check for valid input
        if (_width <= 0) {
            _width = 1;
        }
        if (_height <= 0) {
            _height = 1;
        }
        if (_bitsPerPixel <= 0) {
            _bitsPerPixel = 8;
        }

        if (initializeSDL() == false) {
            return false;
        }

        if (initializeOpenGL() == false) {
            return false;
        }

        // SDL doesn't trigger off a ResizeEvent at startup, but this needs to
        // be done for OpenGL
        SDL_Event resizeEvent;
        resizeEvent.type = SDL_VIDEORESIZE;
        resizeEvent.resize.w = width;
        resizeEvent.resize.h = height;

        SDL_PushEvent(&resizeEvent);

        return true;
    }

    bool initializeOpenGL()
    {
        // Set up OpenGL attributes
        // All values are "at least"!
        // TODO: Set attributes with relation to how window is set up,
        //      for example, bits per pixel etc.
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 5);

        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 1); //vsync

        // Unused settings at the moment
        //SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,    8);
        //SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
        //SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,    8);
        //SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);

        // Anti-aliasing settings
        //SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);   //Enable AA
        //SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);   //How much AA

        // TODO: Check for opengl errors before returning
        return true;
    }

    bool initializeSDL()
    {
        // Set the title.
        SDL_WM_SetCaption(_title.c_str(), _title.c_str());

        // Flags tell SDL about the type of window we are creating.
        int flags = SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL;

        if (_isFullscreen) {
            flags |= SDL_FULLSCREEN;
        }

        // TODO: Might be necessary to store surface that setvideo returns
        if (SDL_SetVideoMode( _width, _height, _bitsPerPixel, flags ) == NULL) {
            return false;
        }

        return true;
    }

    //TODO: Make window process resize and re-initialize
    bool GameWindow::setSize(int width, int height)
    {
        if (!_isInitialized) {
            return false;
        }

        _height = height;
        _width = width;

        return true;
    }

    int GameWindow::getHeight()
    {
        return _height;
    }

    int GameWindow::getWidth()
    {
        return _width;
    }
};
