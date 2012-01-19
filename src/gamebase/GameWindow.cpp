#include "GameWindow.h"

namespace ie_game
{
    GameWindow::GameWindow():
        _width(0),
        _height(0),
        _bitsPerPixel(0),
        _isFullscreen(false)
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

        // Set the title.
        SDL_WM_SetCaption(title.c_str(), title.c_str());

        // Flags tell SDL about the type of window we are creating.
        int flags = SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL;

        if (isFullscreen)
        {
            flags |= SDL_FULLSCREEN;
        }

        if (SDL_SetVideoMode( width, height, bitsPerPixel, flags ) == NULL)
        {
            return false;
        }

        // Set up OpenGL attributes
        // All values are "at least"!
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 5);

        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 1); //vsync

        // SDL doesn't trigger off a ResizeEvent at startup, but this needs to
        // be done for OpenGL
        SDL_Event resizeEvent;
        resizeEvent.type = SDL_VIDEORESIZE;
        resizeEvent.resize.w = width;
        resizeEvent.resize.h = height;

        SDL_PushEvent(&resizeEvent);

        return true;
    }

    //TODO: Make window process resize and re-initialize
    void GameWindow::setSize(int width, int height)
    {
        _height = height;
        _width = width;
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
